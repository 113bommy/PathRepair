#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
long long qpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}
namespace Solver {
void InitOnce() {}
int x, y, n;
void Read() {
  int res = scanf("%d%d%d", &x, &y, &n);
  if (res == -1) exit(0);
}
void Solve() {
  bool suc = 0;
  for (int i = 1; i <= n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    int t1 = min(u, x + 1 - u);
    int t2 = min(v, y + 1 - v);
    int t3 = min(t1, t2);
    if (t3 <= 5) suc = 1;
  }
  puts(suc ? "YES" : "NO");
}
}  // namespace Solver
int main() {
  Solver::InitOnce();
  while (true) {
    Solver::Read();
    Solver::Solve();
  }
  return 0;
}
