#include <bits/stdc++.h>
using namespace std;
template <typename _T>
inline void _DBG(const char *s, _T x) {
  cerr << s << " = " << x << "\n";
}
template <typename _T, typename... args>
void _DBG(const char *s, _T x, args... a) {
  while (*s != ',') cerr << *s++;
  cerr << " = " << x << ',';
  _DBG(s + 1, a...);
}
const int N = 3e5 + 7;
int n, de[N], pre[N], sz[N], bac[N], F[N];
long long ans[N];
vector<int> G[N];
vector<int> D[N];
vector<long long> SM[N];
int cnt = 0, mx;
int dfs(int v, int f, int d) {
  F[v] = f;
  de[v] = d;
  pre[v] = ++cnt;
  D[de[v]].push_back(pre[v]);
  bac[cnt] = v;
  mx = max(mx, d);
  for (auto u : G[v]) {
    if (u != f) {
      sz[v] += dfs(u, v, d + 1);
    }
  }
  return ++sz[v];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1, 0, 0);
  for (int i = 0; i <= mx; i++) {
    D[i].push_back(n + 100);
    SM[i].resize((int)(D[i]).size(), 0);
  }
  int m;
  cin >> m;
  while (m--) {
    int v, d;
    cin >> v >> d;
    long long x;
    cin >> x;
    auto it = lower_bound((D[de[v]]).begin(), (D[de[v]]).end(), pre[v]);
    SM[de[v]][it - D[de[v]].begin()] += x;
    SM[de[v]][it - D[de[v]].begin() + 1] -= x;
    int tmp = de[v] + d + 1;
    if (tmp <= mx) {
      auto bg = lower_bound((D[tmp]).begin(), (D[tmp]).end(), pre[v]);
      SM[tmp][bg - D[tmp].begin()] -= x;
      auto en =
          upper_bound((D[tmp]).begin(), (D[tmp]).end(), pre[v] + sz[v] - 1);
      SM[tmp][en - D[tmp].begin()] += x;
    }
  }
  for (int i = 0; i <= mx; i++) {
    for (int j = 1; j < (int)(SM[i]).size(); j++) SM[i][j] += SM[i][j - 1];
    for (int j = 0; j < (int)(SM[i]).size(); j++) {
      int v = bac[D[i][j]];
      ans[v] = SM[i][j] + ans[F[v]];
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
