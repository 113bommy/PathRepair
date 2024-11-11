#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5e3, MAX_M = 3;
map<string, bitset<MAX_M> > V[2];
int main() {
  ios::sync_with_stdio(false);
  V[0]["?"] = bitset<MAX_M>();
  V[1]["?"] = bitset<MAX_M>().set();
  int n, m;
  cin >> n >> m;
  for (int i = (0), i_ = (n); i < i_; ++i) {
    string var, t, o, s;
    cin >> var >> t >> s;
    if (isdigit(s[0]))
      V[0][var] = V[1][var] = bitset<MAX_M>(s);
    else {
      cin >> o >> t;
      for (int j = (0), j_ = (1); j <= j_; ++j) {
        const bitset<MAX_M> &x = V[j][s], &y = V[j][t];
        switch (o[0]) {
          case 'A':
            V[j][var] = x & y;
            break;
          case 'O':
            V[j][var] = x | y;
            break;
          default:
            V[j][var] = x ^ y;
        }
      }
    }
  }
  bitset<MAX_M> ans[2];
  for (int i = (0), i_ = (m); i < i_; ++i) {
    int cnt[2] = {0, 0};
    for (int j = (0), j_ = (1); j <= j_; ++j) {
      for (map<string, bitset<MAX_M> >::iterator ix = V[j].begin();
           ix != V[j].end(); ++ix)
        if (ix->first[0] != '?') cnt[j] += ix->second[i];
    }
    ans[0][i] = cnt[1] < cnt[0];
    ans[1][i] = cnt[1] > cnt[0];
  }
  for (int i = (0), i_ = (1); i <= i_; ++i) {
    for (int j = (m - 1), j_ = (0); j >= j_; --j) cout << ans[i][j];
    cout << endl;
  }
  return 0;
}
