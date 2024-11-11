#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
int n, m, color[N];
vector<vector<int> > g(N);
bool v[N];
bool bipartite(int i, int c) {
  color[i] = c;
  for (int j : g[i]) {
    if (!color[j]) {
      if (!bipartite(j, (c == 1 ? 2 : 1))) return false;
    } else if (color[j] == c)
      return false;
  }
  return true;
}
pair<int, int> count(int i) {
  v[i] = true;
  pair<int, int> ret = make_pair(color[i] == 1, color[i] == 2);
  for (int j : g[i])
    if (!v[j]) {
      pair<int, int> p = count(j);
      ret.first += p.first;
      ret.second += p.second;
    }
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (int)(m); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (!m) return cout << 3 << " " << 1ll * n * (n - 1) * (n - 2) / 6, 0;
  int mx = 0, cnt = 0;
  for (int i = (1); i <= (int)(n); ++i)
    mx = max(mx, ((int)(g[i]).size())), cnt += ((int)(g[i]).size()) == 1;
  if (mx == 1) return cout << 2 << " " << cnt / 2ll * (n - 2), 0;
  bool bip = true;
  for (int i = (1); i <= (int)(n); ++i)
    if (!color[i]) bip &= bipartite(i, 1);
  if (!bip)
    cout << "0 1";
  else {
    long long ans = 0;
    for (int i = (1); i <= (int)(n); ++i)
      if (!v[i]) {
        pair<int, int> p = count(i);
        ans += p.first * (p.first - 1ll) / 2 + p.second * (p.second - 1ll) / 2;
      }
    cout << 1 << " " << ans;
  }
}
