#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

int dp[1010][1010][16];

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };


//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"
int main() {
	int H, W; cin >> H >> W;
	for (int i = 0; i < 1010; ++i)for (int j = 0; j < 1010; ++j)for (int k = 0; k < 16; ++k){
		dp[i][j][k] = 1e9;
	}
	dp[5][5][0] = 0;
	vector<vector<int>>field(H + 8, vector<int>(W + 8));
	for (int i = 0; i < H; ++i) {
		string st; cin >> st;
		for (int j = 0; j < W; ++j) {
			if (st[j] != '.') {
				field[i + 5][j + 5] = st[j] - '0';
			}
		}
	}
	for (int nowy = 5; nowy < H + 6; ++nowy) {
		for (int nowx = 5; nowx < W +6; ++nowx) {
			for (int n = 0; n < 16; ++n) {
				const int eat_ld = n & 1;
				const int eat_d = (n & 2) >> 1;
				const int eat_r = (n & 4) >> 2;
				const int eat_ru = (n & 8) >> 3;
				if (1e9 <= dp[nowy][nowx][n])continue;
				vector<vector<char>>baseeats(4, vector<char>(4));
				baseeats[2][0] = eat_ld;
				baseeats[2][1] = eat_d;
				baseeats[1][2] = eat_r;
				baseeats[0][2] = eat_ru;
				baseeats[1][1] = true;
				for (int way = 0; way < 2; ++way) {
					const int  nextx = nowx + dx[way];
					const int nexty = nowy + dy[way];
					const int ax = 1 + dx[way];
					const int ay = 1 + dy[way];
					bool flag = false;
					for (int w = 0; w < 4; ++w) {
						int nexteat_ld = baseeats[2 + dy[way]][0 + dx[way]];
						int nexteat_d = baseeats[2 + dy[way]][1 + dx[way]];
						int nexteat_r = baseeats[1 + dy[way]][2 + dx[way]];
						int nexteat_ru = baseeats[0 + dy[way]][2 + dx[way]];
						int eat_sum = 0;
						if (!eats[ay][ax]) {
							if (ay == 2 + dy[way] && ax == 0 + dx[way])nexteat_ld = true;
							if (ay == 2 + dy[way] && ax == 1 + dx[way])nexteat_d = true;
							if (ay == 1 + dy[way] && ax == 2 + dx[way])nexteat_r = true;
							if (ay == 0 + dy[way] && ax == 2 + dx[way])nexteat_ru = true;
							//eats[ay][ax] = true;
							eat_sum += field[nexty][nextx];
						}
						for (int v = 0; v < 4; ++v) {
							if (v == w)continue;
							else {
								if (!eats[ay + dy[v]][ax + dx[v]]) {
									if (ay + dy[v]== 2 + dy[way] && ax + dx[v] == 0 + dx[way])nexteat_ld = true;
									if (ay + dy[v]== 2 + dy[way] && ax + dx[v] == 1 + dx[way])nexteat_d = true;
									if (ay + dy[v]== 1 + dy[way] && ax + dx[v] == 2 + dx[way])nexteat_r = true;
									if (ay + dy[v]== 0 + dy[way] && ax + dx[v] == 2 + dx[way])nexteat_ru = true;
									//eats[ay + dy[v]][ax + dx[v]] = true;
									eat_sum += field[nexty + dy[v]][nextx + dx[v]];
								}
							}
						}
						int n = dp[nowy][nowx][eat_ld+2*eat_d+4*eat_r+8*eat_ru] + eat_sum;
						dp[nexty][nextx][nexteat_ld+2*nexteat_d+4*nexteat_r+8*nexteat_ru] = min(dp[nexty][nextx][nexteat_ld + 2 * nexteat_d + 4 * nexteat_r + 8 * nexteat_ru], n);

					}
				}
			}
		}
	}
	int ans = 1e9;
	for (int l = 0; l < 16; ++l) {
		ans = min(ans, dp[H + 4][W + 4][l]);	
	}
	cout << ans << endl;

	return 0;
}