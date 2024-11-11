#include<iostream>
#include<utility>
#include<cstdlib>

typedef std::pair<double, int> P;

const int INF = 1 << 30;

int n;

int main()
{
	while( std::cin >> n, n )
	{
		P ans( INF, INF );
		
		while( n-- )
		{
			int i; 
			double h, w;
			std::cin >> i >> h >> w;
			h /= 100.0;
			ans = std::min( ans, P( fabs( w / ( h * h ) - 22.0 ), i ) );
		}

		std::cout << ans.second << std::endl;
	}

	return 0;
}