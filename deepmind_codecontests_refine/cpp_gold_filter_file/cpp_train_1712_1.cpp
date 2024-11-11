#include <bits/stdc++.h>
using namespace std;
inline long long bigmod(long long p, long long e, long long M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return ret;
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
const int N = 1e5 + 5;
long long a[N];
vector<long long> g[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> a[i];
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    if (i - 1 >= 0) ans += abs(a[i] - a[i - 1]);
    if (i - 1 >= 0 && a[i - 1] != a[i]) g[a[i]].push_back(a[i - 1]);
    if (i + 1 < m && a[i + 1] != a[i]) g[a[i]].push_back(a[i + 1]);
  }
  for (int i = 1; i <= n; i++) sort((g[i]).begin(), (g[i]).end());
  long long fans = ans;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 0) continue;
    long long med = g[i][g[i].size() / 2];
    long long v = ans;
    for (int j = 0; j < g[i].size(); j++)
      v += abs(g[i][j] - med) - abs(g[i][j] - i);
    fans = min(fans, v);
  }
  printf("%lld\n", fans);
  return 0;
}
