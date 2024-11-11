#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    T t = bigmod(p, e / 2, M);
    return (t * t) % M;
  }
  return (bigmod(p, e - 1, M) * p) % M;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T multimod(T a, T b, T m) {
  T ans = 0ll;
  a %= m, b %= m;
  while (b) {
    if (b & 1ll) ans = m - ans > a ? (ans + a) : (ans + a - m);
    b >>= 1ll;
    a = (m - a) > a ? a + a : a + a - m;
  }
  return (T)ans;
}
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
pair<long long, long long> res[1000];
vector<int> V[(200000 + 7)];
void DFS(int u, int p, long long x, long long y, int d, long long r) {
  d = (d + 3) % 4;
  res[u].first = x;
  res[u].second = y;
  int sz = V[u].size();
  for (int i = 0; i < sz; i++) {
    int v = V[u][i];
    if (v == p) continue;
    DFS(v, u, x + (long long)dr[d] * r, (long long)dc[d] * r, d, r >> 1ll);
    d = (d + 1) % 4;
  }
  return;
}
int main() {
  int i, j, x, y, k;
  int a, b, l, n, m, u, v, w;
  cin >> n;
  int sz = 0;
  for (i = 1; i < n; i++) {
    cin >> u >> v;
    V[u].push_back(v);
    V[v].push_back(u);
    (sz = max(sz, (int)V[u].size()));
    (sz = max(sz, (int)V[v].size()));
  }
  if (sz > 4) {
    cout << "NO" << endl;
    return 0;
  }
  DFS(1, 0, 0ll, 0ll, 0, 1ll << 40);
  cout << "YES" << endl;
  for (i = 1; i <= n; i++) cout << res[i].first << " " << res[i].second << endl;
  return 0;
}
