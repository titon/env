<?hh // strict
/**
 * @copyright   2010-2013, The Titon Project
 * @license     http://opensource.org/licenses/bsd-license.php
 * @link        http://titon.io
 */

namespace Titon\Environment;

use Titon\Utility\Converter;

type HostnameList = Vector<string>;

/**
 * A Host represents a shared configuration for a collection of hostnames.
 *
 * @package Titon\Environment
 */
class Host {

    /**
     * Path to configuration bootstrap.
     *
     * @type string
     */
    protected string $_bootstrap = '';

    /**
     * List of hostnames.
     *
     * @type \Titon\Environment\HostnameList
     */
    protected HostnameList $_hostnames;

    /**
     * Unique identifier.
     *
     * @type string
     */
    protected string $_key = '';

    /**
     * Type of environment.
     *
     * @type \Titon\Environment\Server
     */
    protected Server $_type;

    /**
     * Set the required settings.
     *
     * @param string|array $hostnames
     * @param \Titon\Environment\Server $type
     */
    public function __construct(mixed $hostnames, Server $type = Server::DEV) {
        $this->_hostnames = Converter::toVector($hostnames);
        $this->_type = $type;
    }

    /**
     * Return the bootstrap path.
     *
     * @return string
     */
    public function getBootstrap(): string {
        return $this->_bootstrap;
    }

    /**
     * Return the list of hostnames.
     *
     * @return \Titon\Environment\HostnameList
     */
    public function getHostnames(): HostnameList {
        return $this->_hostnames;
    }

    /**
     * Return the host key.
     *
     * @return string
     */
    public function getKey(): string {
        return $this->_key;
    }

    /**
     * Return the environment type.
     *
     * @return \Titon\Environment\Server
     */
    public function getType(): Server {
        return $this->_type;
    }

    /**
     * Is the current environment development?
     *
     * @return bool
     */
    public function isDevelopment(): bool {
        return ($this->getType() === Server::DEV);
    }

    /**
     * Is the current environment production?
     *
     * @return bool
     */
    public function isProduction(): bool {
        return ($this->getType() === Server::PROD);
    }

    /**
     * Is the current environment QA?
     *
     * @return bool
     */
    public function isQA(): bool {
        return ($this->getType() === Server::QA);
    }

    /**
     * Is the current environment staging?
     *
     * @return bool
     */
    public function isStaging(): bool {
        return ($this->getType() === Server::STAGING);
    }

    /**
     * Is the current environment testing?
     *
     * @return bool
     */
    public function isTesting(): bool {
        return ($this->getType() === Server::TESTING);
    }

    /**
     * Set the bootstrap file path.
     *
     * @param string $path
     * @return $this
     */
    public function setBootstrap(string $path): this {
        $this->_bootstrap = $path;

        return $this;
    }

    /**
     * Set the unique key.
     *
     * @param string $key
     * @return $this
     */
    public function setKey(string $key): this {
        $this->_key = $key;

        return $this;
    }

}