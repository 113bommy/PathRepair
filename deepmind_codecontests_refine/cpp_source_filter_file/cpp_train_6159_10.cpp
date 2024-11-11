#include <bits/stdc++.h>
using namespace std;
vector<int> PIS, PIT;
int D[1001][50][50];
void getPI(const string &s, vector<int> &PI) {
  int j = 0;
  PI.resize(s.size());
  for (int i = 1; i < s.size(); i++) {
    while (j && s[i] != s[j]) j = PI[j - 1];
    if (s[i] == s[j]) PI[i] = ++j;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ((void)0);
  ((void)0);
  ((void)0);
  int tj, tk, v, ans = 0x80808080;
  string c, s, t;
  cin >> c >> s >> t;
  getPI(s, PIS);
  getPI(t, PIT);
  memset(D, 0x80, sizeof(D));
  D[0][0][0] = 0;
  for (int i = 0; i < c.size(); i++)
    for (int j = 0; j < s.size(); j++)
      for (int k = 0; k < t.size(); k++) {
        if (D[i][j][k] == 0x80808080) continue;
        if (c[i] == '*') {
          for (char tc = 'a'; tc <= 'z'; tc++) {
            tj = j;
            tk = k;
            v = 0;
            while (tj && tc != s[tj]) tj = PIS[tj - 1];
            while (tk && tc != t[tk]) tk = PIT[tk - 1];
            if (tc == s[tj] && ++tj == s.size()) v++, tj = PIS[tj - 1];
            if (tc == t[tk] && ++tk == t.size()) v--, tk = PIT[tk - 1];
            D[i + 1][tj][tk] = max(D[i + 1][tj][tk], D[i][j][k] + v);
          }
        } else {
          tj = j;
          tk = k;
          v = 0;
          while (tj && c[i] != s[tj]) tj = PIS[tj - 1];
          while (tk && c[i] != t[tk]) tk = PIT[tk - 1];
          if (c[i] == s[tj] && ++tj == s.size()) v++, tj = PIS[tj];
          if (c[i] == t[tk] && ++tk == t.size()) v--, tk = PIT[tk];
          D[i + 1][tj][tk] = max(D[i + 1][tj][tk], D[i][j][k] + v);
        }
      }
  for (int i = 0; i < s.size(); i++)
    for (int j = 0; j < t.size(); j++) ans = max(ans, D[c.size()][i][j]);
  cout << ans << '\n';
  return 0;
}
