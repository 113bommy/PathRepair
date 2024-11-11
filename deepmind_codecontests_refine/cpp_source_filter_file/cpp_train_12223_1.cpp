#include <bits/stdc++.h>
using namespace std;
const long long INF = 1ll << 40;
long long n, ans;
long long a[100005];
long long w[100005];
long long mul[100005];
vector<int> G[100005];
long long gcd(long long x, long long y) {
  if (x < y) swap(x, y);
  while (y != 0) {
    long long c = x % y;
    x = y;
    y = c;
  }
  return x;
}
long long lcm(long long x, long long y) {
  long long g = gcd(x, y);
  if (x * y > g * INF) return 0;
  return x / g * y;
}
bool dfs(int v, int par) {
  int deg = 0;
  for (int i = 0; i < G[v].size(); i++) {
    int to = G[v][i];
    if (to == par) continue;
    if (!dfs(to, v)) return false;
    deg++;
  }
  if (deg == 0) {
    w[v] = a[v];
    mul[v] = 1;
    return true;
  }
  long long x = 1;
  for (int i = 0; i < G[v].size(); i++) {
    int to = G[v][i];
    if (to == par) continue;
    x = lcm(x, mul[to]);
    if (x == 0) return false;
  }
  long long z = INF;
  for (int i = 0; i < G[v].size(); i++) {
    int to = G[v][i];
    if (to == par) continue;
    z = min(z, w[to] / x * x);
  }
  w[v] = deg * z;
  mul[v] = deg * x;
  return true;
}
void solve() {
  memset(w, 0, sizeof(w));
  memset(mul, 0, sizeof(mul));
  long long ans = accumulate(a, a + n, 0ll);
  if (dfs(0, -1)) ans -= w[0];
  cout << ans << endl;
}
void coding() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      scanf("%I64d", a + i);
      G[i].clear();
    }
    int from, to;
    for (int i = 0; i < n - 1; i++) {
      scanf("%d%d", &from, &to);
      from--;
      to--;
      G[from].push_back(to);
      G[to].push_back(from);
    }
    solve();
  }
}
int main() { coding(); }
