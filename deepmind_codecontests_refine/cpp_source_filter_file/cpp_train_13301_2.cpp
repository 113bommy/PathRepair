#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int r, c, k; cin >> r >> c >> k;
	vector<vector<int> > g1(r + 1, vector<ll> (c + 1)), g2(g1), g3(g2), g(g1);
	for (int i = 0; i < k; ++i) {
		int row, col, val; cin >> row >> col >> val;
		g[row][col] = val;
	}
	g1[1][1] = g2[1][1] = g3[1][1] = g[1][1];
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			
				if (i > 1) {
					g1[i][j] = g3[i-1][j] + g[i][j] ;
					g2[i][j] = g1[i][j];
					g3[i][j] = g2[i][j];
				}
				if (j > 1) {
					g1[i][j] = max({g[i][j], g1[i][j-1], g1[i][j]});
					g2[i][j] = max({g[i][j] + g1[i][j-1], g2[i][j], g2[i][j-1]});
					g3[i][j] = max({g3[i][j], g[i][j] + g2[i][j-1], g3[i][j-1]});
				}
			
		}
	}
	cout << g3[r][c] << endl;
}