s = """Washington	April 30, 1789	March 4, 1797
Adams	March 4, 1797	March 4, 1801	
Jefferson	March 4, 1801	March 4, 1809	
Madison	March 4, 1809	March 4, 1817	
Monroe	March 4, 1817	March 4, 1825	
Adams	March 4, 1825	March 4, 1829	
Jackson	March 4, 1829	March 4, 1837	
Van Buren	March 4, 1837	March 4, 1841	
Harrison	March 4, 1841	April 4, 1841	
Tyler	April 4, 1841	March 4, 1845	
Polk	March 4, 1845	March 4, 1849	
Taylor	March 4, 1849	July 9, 1850	
Fillmore	July 9, 1850	March 4, 1853	
Pierce	March 4, 1853	March 4, 1857	
Buchanan	March 4, 1857	March 4, 1861	
Lincoln	March 4, 1861	April 15, 1865	
Johnson	April 15, 1865	March 4, 1869	
Grant	March 4, 1869	March 4, 1877	
Hayes	March 4, 1877	March 4, 1881	
Garfield	March 4, 1881	September 19, 1881	
Arthur	September 19, 1881	March 4, 1885	
Cleveland	March 4, 1885	March 4, 1889	
Harrison	March 4, 1889	March 4, 1893	
Cleveland	March 4, 1893	March 4, 1897	
McKinley	March 4, 1897	September 14, 1901	
Roosevelt	September 14, 1901	March 4, 1909	
Taft	March 4, 1909	March 4, 1913	
Wilson	March 4, 1913	March 4, 1921	
Harding	March 4, 1921	August 2, 1923	
Coolidge	August 2, 1923	March 4, 1929	
Hoover	March 4, 1929	March 4, 1933	
Roosevelt	March 4, 1933	April 12, 1945	
Truman	April 12, 1945	January 20, 1953	
Eisenhower	January 20, 1953	January 20, 1961	
Kennedy	January 20, 1961	November 22, 1963	
Johnson	November 22, 1963	January 20, 1969	
Nixon	January 20, 1969	August 9, 1974	
Ford	August 9, 1974	January 20, 1977	
Carter	January 20, 1977	January 20, 1981	
Reagan	January 20, 1981	January 20, 1989"""
data = s.split("\n")
a = int(input()) - 1
print(data[a].split("\t")[0])