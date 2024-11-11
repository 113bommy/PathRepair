#include <bits/stdc++.h>
using namespace std;
const long long int N = 3e6 + 5, inf = 1e9 + 7;
int len, Z[N], cum[N];
string s;
void z_fun() {
  Z[0] = len;
  int lft = 0, rgt = 0;
  for (int i = 1; i < len; i++) {
    if (rgt <= i) {
      lft = rgt = i;
      while (rgt < len && s[rgt - lft] == s[lft]) rgt++;
      Z[i] = rgt - lft;
    } else {
      int nw = i - lft;
      if (Z[nw] < rgt - i)
        Z[i] = Z[nw];
      else {
        lft = i;
        while (rgt < len && s[rgt - lft] == s[lft]) rgt++;
        Z[i] = rgt - lft;
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  cin >> s;
  len = s.size();
  z_fun();
  int pos[m + 2];
  for (int i = 0; i < m; i++) {
    cin >> pos[i];
    pos[i]--;
    cum[pos[i]]++;
    cum[pos[i] + len]--;
  }
  for (int i = 1; i < m; i++) {
    int nw = pos[i - 1] + len - pos[i];
    if (nw <= 0) continue;
    if (Z[len - nw] < nw) cout << "0\n", exit(0);
  }
  int res = 1;
  for (int i = 0; i < n; i++) {
    if (i) cum[i] += cum[i - 1];
    if (cum[i] == 0) res = (res * 26LL) % inf;
  }
  cout << res << "\n";
}
