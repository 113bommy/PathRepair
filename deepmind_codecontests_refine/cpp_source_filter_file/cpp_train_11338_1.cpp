#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef pair<int, int>P;

char c[80][80];
struct str {
	string s;
	str(string s = "") :s(s) {}
}d[80][80];
bool operator<(str a, str b) {
	if (a.s.size() == b.s.size())return a.s < b.s;
	return a.s.size() < b.s.size();
}
int main() {
	int w, h;
	while (scanf("%d%d", &w, &h), w) {
		rep(i, h)scanf("%s", c[i]);
		str Max = "0";
		rep(i, h)rep(j, w) {
			if ('0' <= c[i][j] && c[i][j] <= '9') {
				d[i][j] = to_string(c[i][j] - '0');
				if (i)d[i][j] = max(d[i][j], str(d[i - 1][j].s + c[i][j]));
				if (j)d[i][j] = max(d[i][j], str(d[i][j - 1].s + c[i][j]));
				str s = d[i][j];
				while (!s.s.empty() && s.s.front() == '0')s = s.s.substr(1);
				Max = max(Max, s);
			}
			else d[i][j] = (string)"";
		}
		cout << Max.s << endl;
	}
}