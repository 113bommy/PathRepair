#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long double eps = 1e-9;
const long long maxn = 31;
const long long inf = 5e18;
const long long minf = -inf;
long long ans = minf, n, u, r;
vector<long long> a(maxn), b(maxn), k(maxn), p(maxn);
void recur(long long op, long long flag, vector<long long> v) {
  if ((u - op) % 2 == 0) {
    long long res = 0;
    for (long long i = 0; i < n; ++i) {
      res += v[i] * k[i];
    }
    ans = max(ans, res);
  }
  if (op == u) return;
  vector<long long> here(maxn);
  for (long long i = 0; i < n; ++i) {
    here[i] = v[p[i] - 1] + r;
  }
  recur(op + 1, 0, here);
  if (flag) return;
  for (long long i = 0; i < n; ++i) {
    here[i] = v[i] ^ b[i];
  }
  recur(op + 1, 1, here);
  return;
}
bool solve() {
  cin >> n >> u >> r;
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = 0; i < n; ++i) cin >> b[i];
  for (long long i = 0; i < n; ++i) cin >> k[i];
  for (long long i = 0; i < n; ++i) cin >> p[i];
  recur(0, 0, a);
  cout << ans << "\n";
  return true;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    if (solve()) {
    } else {
    }
  }
  return 0;
}
