#include "bits\stdc++.h"
#define MOD 1000000007
#define INF 11234567890
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
#define reps(i,j,N) for(LL i=j;i<N;++i)
typedef long long int LL;
typedef std::pair<int, int> P;

int N, K, a[5112];
int ans;

int main()
{
	in >> N >> K;
	rep(i, N) { in >> a[i]; }

	LL sum;
	std::sort(a, a + N, std::greater<int>());
	rep(i, N)
	{
		sum = 0;
		reps(j, i, N)
		{
			sum += a[j];
			if (sum >= K)
			{
				ans = std::max<LL>(ans, j + 1);
				sum -= a[j];
			}
		}
	}
	ans = N - ans;

	out << ans << std::endl;
	return 0;
}