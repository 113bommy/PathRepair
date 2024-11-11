#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int b[100], x1[100][100], Y1[100][100], x2[100][100], y2[100][100];
string link[100][100];
map<string, int>mp;
int main() {
	int n;
	while (scanf("%d", &n), n) {
		mp.clear();
		int w, h; scanf("%d%d", &w, &h);
		vector<string>v;
		rep(i, n) {
			string s; cin >> s >> b[i]; mp[s] = i;
			if (i == 0)v.push_back(s);
			rep(j, b[i])cin >> x1[i][j] >> Y1[i][j] >> x2[i][j] >> y2[i][j] >> link[i][j];
		}
		int pos = 0;
		int m; scanf("%d", &m);
		rep(i, m) {
			string s; cin >> s;
			if (s == "click") {
				int x, y; cin >> x >> y;
				int a = mp[v[pos]];
				rep(i, b[a]) {
					if (x1[a][i] <= x&&x <= x2[a][i] && Y1[a][i] <= y&&y <= y2[a][i]) {
						v.erase(v.begin() + pos + 1, v.end());
						v.push_back(link[a][i]); pos = v.size() - 1; break;
					}
				}
			}
			if (s == "back") {
				if (pos)pos--;
			}
			if (s == "forward") {
				if (pos < v.size() - 1)pos++;
			}
			if (s == "show")cout << v[pos] << endl;
		}
	}
}