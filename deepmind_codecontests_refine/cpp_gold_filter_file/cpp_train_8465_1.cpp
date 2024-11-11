#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T maxer(T &a, T b) {
  a = max(a, b);
}
template <typename T>
inline T miner(T &a, T b) {
  a = min(a, b);
}
void iOS() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void fin() { freopen("in", "r", stdin); }
void fout() { freopen("out", "w", stdout); }
const int inf = ~0u / 10;
const long long linf = ~0ull / 2;
const int maxn = 1e6 + 20, base = 709;
long long h[2][maxn], b[maxn];
int main() {
  iOS();
  long long ans = 0;
  int n, m;
  cin >> n >> m;
  b[0] = 1;
  for (int i = 1; i <= n; i++) b[i] = b[i - 1] * base, h[1][i - 1] += b[i - 1];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    h[0][u] += b[v];
    h[1][u] += b[v];
    h[0][v] += b[u];
    h[1][v] += b[u];
  }
  for (int j = 0; j < 2; j++) {
    sort(h[j], h[j] + n);
    long long cnt = 1ll;
    for (int i = 1; i < n; i++)
      if (h[j][i] == h[j][i - 1])
        cnt++;
      else {
        ans += (cnt * (cnt - 1)) / 2;
        cnt = 1ll;
      }
    ans += (cnt * (cnt - 1)) / 2;
  }
  cout << ans;
  return 0;
}
