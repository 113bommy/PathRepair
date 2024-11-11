#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PI;
int distL[200][200];
int distS[200][200];
int dp[2][200];
int z[1000];
int main() {
	int N, M;
	while (cin >> N >> M, N) {
		fill((int*)distL, (int*)(distL + 200), 1 << 25);
		fill((int*)distS, (int*)(distS + 200), 1 << 25);
		for (int i = 0; i < N; i++) distL[i][i] = distS[i][i] = 0;
		for (int i = 0; i < M; i++) {
			int x, y, t;
			char sl[2];
			cin >> x >> y >> t >> sl;
			x--; y--;
			if (sl[0] == 'L') {
				distL[x][y] = distL[y][x] = min(distL[x][y], t);
			}
			else {
				distS[x][y] = distS[y][x] = min(distS[x][y], t);
			}
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					distL[i][j] = min(distL[i][j], distL[i][k] + distL[k][j]);
					distS[i][j] = min(distS[i][j], distS[i][k] + distS[k][j]);
				}
			}
		}
		int R;
		cin >> R;
		for (int i = 0; i < R; i++) {
			cin >> z[i];
			z[i]--;
		}
		fill((int*)dp, (int*)(dp + 2), 1 << 25);
		dp[0][z[0]] = 0;
		for (int i = 1; i < R; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					if (j == k) dp[i % 2][k] = min(dp[i % 2][k], dp[(i - 1) % 2][j] + distL[z[i - 1]][z[i]]);
					else dp[i % 2][k] = min(dp[i % 2][k], dp[(i - 1) % 2][j] + distL[z[i - 1]][j] + distS[j][k] + distL[k][z[i]]);
				}
			}
			for (int j = 0; j < N; j++) dp[(i - 1) % 2][j] = 1 << 25;
		}
		int ans = 1 << 25;
		for (int i = 0; i < N; i++) ans = min(ans, dp[(R - 1) % 2][i]);
		cout << ans << endl;
	}
}
