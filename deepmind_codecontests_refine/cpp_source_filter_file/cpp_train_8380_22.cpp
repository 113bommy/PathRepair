#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> tbl;
int x, y, xx0, yy0, a, b, a0, b0, hit;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> x >> y >> xx0 >> yy0 >> s;
  tbl = vector<vector<bool>>(x, vector<bool>(y, 0));
  a = --xx0, b = --yy0, hit = 1, a0 = b0 = -1;
  tbl[a][b] = 1;
  cout << 1;
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if (c == 'U')
      a = max(0, min(x - 1, xx0 - 1));
    else if (c == 'D')
      a = max(0, min(x - 1, xx0 + 1));
    else if (c == 'R')
      b = max(0, min(y - 1, yy0 + 1));
    else if (c == 'L')
      b = max(0, min(y - 1, yy0 - 1));
    bool h = !tbl[a][b];
    tbl[a][b] = 1;
    hit += h;
    if (i == s.size() - 1)
      cout << ' ' << x * y - hit + 1 << endl;
    else
      cout << ' ' << (h ? 0 : 1);
    a0 = xx0;
    b0 = yy0;
    xx0 = a;
    yy0 = b;
  }
}
