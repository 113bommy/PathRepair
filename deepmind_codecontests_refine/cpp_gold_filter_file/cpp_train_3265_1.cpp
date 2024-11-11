#include <bits/stdc++.h>
using namespace std;
int n, m, k, stx, sty, fnx, fny;
char ac[105][105], ch;
pair<int, int> st[30];
int at[105][105];
string s;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> ac[i][j];
      if (ac[i][j] >= 'a' && ac[i][j] <= 'z') {
        st[int(ac[i][j] - 'a')].first = i;
        st[int(ac[i][j] - 'a')].second = j;
        at[i][j] = 1;
      } else if (ac[i][j] >= '1' && ac[i][j] <= '9') {
        at[i][j] = int(ac[i][j] - '0');
      }
    }
  }
  cin >> stx >> sty;
  cin >> s;
  cin >> fnx >> fny;
  int sz = s.size();
  s += char('z' + 1);
  sz++;
  st[int('z' - 'a' + 1)].first = fnx;
  st[int('z' - 'a' + 1)].second = fny;
  for (int i = 0; i < sz; i++) {
    int sp = int(s[i] - 'a');
    while (stx != st[sp].first || sty != st[sp].second) {
      k -= at[stx][sty];
      if (k < 0) {
        cout << stx << " " << sty << endl;
        return 0;
      }
      if (stx < st[sp].first)
        stx++;
      else if (stx > st[sp].first)
        stx--;
      else if (sty < st[sp].second)
        sty++;
      else if (sty > st[sp].second)
        sty--;
    }
  }
  cout << fnx << " " << fny << endl;
  return 0;
}
