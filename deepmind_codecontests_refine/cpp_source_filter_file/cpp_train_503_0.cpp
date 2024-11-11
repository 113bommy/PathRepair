#include <cstdio>
const int MAXN = 51;
const int ZERO = 2550;
const int MAXM = ZERO * 2;
typedef long long LL;
LL F[2][MAXM];
int main() {
	int n, a, i, j, x;
	scanf ( "%d%d", &n, &a );
	F[0][ZERO] = 1;
	for ( i = 1; i <= n; ++i ) {
		scanf ( "%d", &x );
		x -= A;
		for ( j = MAXN; j + MAXN < MAXM; ++j )
			F[i & 1][j] = F[ ( i - 1 ) & 1][j] + F[ ( i - 1 ) & 1][j - x];
	}
	printf ( "%lld\n", F[N & 1][ZERO] - 1 );
}
