#include <bits/stdc++.h>
using namespace std;
const int block = 318;
const int maxn = 101124 + 9;
const int inf = 1l << 30;
int n, m, q, dn[maxn], f[maxn][block], dp[maxn][block];
vector<int> up[maxn];
inline void proc() {
  memset((f), (0), sizeof(f));
  for (register int(i) = (0); (i) < (maxn); ++(i)) {
    for (register int(j) = (0); (j) < (up[i].size()); ++(j))
      (f[i][(int)ceil((double)up[i][j] / block)]) =
          ((f[i][(int)ceil((double)up[i][j] / block)]) > (up[i][j])
               ? (f[i][(int)ceil((double)up[i][j] / block)])
               : (up[i][j]));
    for (register int(j) = (1); (j) < (block); ++(j))
      (f[i][j]) = ((f[i][j]) > (f[i][j - 1]) ? (f[i][j]) : (f[i][j - 1]));
  }
  for (register int(i) = (block)-1; (i) >= (0); --(i)) {
    stack<int> stk;
    for (register int(j) = (i * block + 1) - 1; (j) >= (0); --(j)) {
      dp[j][i] = f[j][i];
      while (stk.size() && dp[j][i] >= stk.top())
        (dp[j][i]) =
            ((dp[j][i]) > (dp[stk.top()][i]) ? (dp[j][i]) : (dp[stk.top()][i])),
        stk.pop();
      stk.push(j);
    }
  }
}
int main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (register int(i) = (0); (i) < (maxn); ++(i))
    dn[i] = i, up[i].push_back(i);
  for (register int(i) = (0); (i) < (m); ++(i)) {
    int l, r;
    cin >> l >> r;
    dn[r] = l, up[l].push_back(r);
  }
  proc();
  cin >> q;
  while (q--) {
    int x, y, res, po;
    cin >> x >> y;
    if (x / block != y / block)
      res = dp[x][y / block], po = y / block * block;
    else
      res = po = x;
    while (po++ < y)
      if (x <= dn[po] && dn[po] <= res) res = po;
    cout << res << '\n';
  }
}
