#include <cstdio>
#include <algorithm>

using namespace std;

#define chmin(a,b) a=min(a,b)
#define rep(i,x) for(int i=0;i<(x);++i)

const int inf = 1e9;

int N, M;
int mc[100][100], mt[100][100];

int main()
{
	while (scanf("%d %d", &N, &M), N || M) {
		fill(mc, mc[M], inf);
		fill(mt, mt[M], inf);

		rep(i, M) mc[i][i] = mt[i][i] = 0;

		rep(i, N) {
			int a, b, cost, time; scanf("%d %d %d %d", &a, &b, &cost, &time); a--; b--;
			mc[a][b] = mc[b][a] = cost;
			mt[a][b] = mt[b][a] = time;
		}

		rep(k, M) rep(i, M) rep(j, M) {
			chmin(mc[i][j], mc[i][k] + mc[j][k]);
			chmin(mt[i][j], mt[i][k] + mt[j][k]);
		}

		int K; scanf("%d", &K);
		rep(i, K) {
			int p, q, r; scanf("%d %d %d", &p, &q, &r); p--; q--;
			printf("%d\n", r == 0 ? mc[p][q] : mt[p][q]);
		}
	}
}