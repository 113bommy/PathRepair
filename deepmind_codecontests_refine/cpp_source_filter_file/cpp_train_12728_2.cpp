#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chmin(T &a, const T &val) {
  if (a > val) a = val;
}
template <class T>
inline void chmax(T &a, const T &val) {
  if (a < val) a = val;
}
template <class T>
long long sqr(T a) {
  return 1ll * a * a;
}
template <class T>
void compress(T &a) {
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
}
const double pi = acos(-1.00);
const double eps = 1e-6;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const int N = 2e5 + 1;
int n, m, k, ans, deg[N];
long long mask[10][10], P[N], base;
vector<pair<int, int> > a[N];
void Try(int i, long long pre = 0) {
  for (int j = 1; j <= i; j++) {
    long long cur = pre + mask[i][j];
    if (i < k)
      Try(i + 1, cur);
    else {
      ans += (cur == base);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  P[0] = 1;
  for (int i = 1; i <= n; i++) P[i] = P[i - 1] * 234567 % MOD;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    a[u].push_back({v, w});
    deg[u]++;
  }
  for (int u = 1; u <= n; u++) {
    sort(a[u].begin(), a[u].end(), [&](pair<int, int> x, pair<int, int> y) {
      return x.second < y.second;
    });
    for (int i = 0; i < a[u].size(); i++) {
      int v = a[u][i].first;
      (mask[deg[u]][i + 1] += 1ll * v * P[v - 1]) %= MOD;
    }
  }
  for (int i = 1; i <= n; i++) base = (base + 1ll * i * P[i - 1]) % MOD;
  Try(1);
  cout << ans;
  return 0;
}
