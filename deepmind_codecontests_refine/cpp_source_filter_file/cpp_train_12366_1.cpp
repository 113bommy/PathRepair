#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
const int INF = 1001001001;

int c[10][1005];
int main() {
	int h, w, k; cin >> h >>w >> k;
	vector<string>s(h);
	REP(i, h)cin >> s[i];
	int ans = INF;
	REP(div, 1 << (h - 1)) {
		int g = 0;
		vector<int>id(h);
		REP(i, h) {
			id[i] = g;
			if (div >> i & 1)++g;
		}
		g++;
		REP(i, g)REP(j, w)c[i][j] = 0;
		REP(i, h)REP(j, w)c[id[i]][j] += (s[i][j] - '0');
		int num = g - 1;
		vector<int>now(g,0);
		bool ok = true;
		REP(j, w) {
			REP(i, g) {
				now[i] += c[i][j];
			}
			REP(i, g) {
				if (now[i] > k) {
					num++;
					now = vector<int>(g,0);
					REP(l, g) {
						now[l] += c[l][j];
					}
					REP(l, g) {
						if (now[l] > k) {
							ok = false;
						}
					}
				}
			}
		}
		if (ok) {
			ans = min(ans, num);
		}
	}
	cout << ans << endl;
	return 0;
}