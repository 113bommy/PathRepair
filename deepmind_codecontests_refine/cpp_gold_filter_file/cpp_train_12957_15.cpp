#include <bits/stdc++.h>
using namespace std;
const long long int logx = 30;
const long long int N = 1e5 + 5;
const long long int INF = 1e18 + 5;
const long long int mod = 1e9 + 7;
const double PI = 3.14159265358979323846;
inline long long int mul(long long int a, long long int b) {
  return (a * 1ll * b) % mod;
}
inline long long int sub(long long int a, long long int b) {
  long long int c = a - b;
  if (c < 0) c += mod;
  return c;
}
inline long long int add(long long int a, long long int b) {
  long long int c = a + b;
  if (c > mod) c -= mod;
  return c;
}
template <typename T>
T power(T x, T y, long long int m) {
  T ans = 1;
  while (y > 0) {
    if (y & 1LL) ans = (ans * x) % m;
    y >>= 1ll;
    x = (x * x) % m;
  }
  return ans % m;
}
vector<long long int> g[N];
long long int n, m, d, root, a[N];
long long int DFS(long long int cur, long long int par, long long int val) {
  long long int res = 1;
  if (a[cur] < val || a[cur] > val + d || a[cur] == val && cur > root) {
    return 0;
  }
  for (auto i : g[cur]) {
    if (i == par) {
      continue;
    }
    long long int ans = DFS(i, cur, val);
    if (ans == 0) {
      continue;
    }
    res = mul(res, ans + 1);
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> d >> n;
  m = n - 1;
  long long int ans = 0;
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (m--) {
    long long int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (long long int i = 1; i <= n; i++) {
    root = i;
    long long int cur = DFS(i, 0, a[i]);
    ans = add(ans, cur);
  }
  cout << ans << endl;
}
