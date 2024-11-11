#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int C = 26;
void add(int &x, int y) {
  x += y;
  while (x >= MOD) x -= MOD;
  while (x < 0) x += MOD;
}
int fix(int x) {
  while (x >= MOD) x -= MOD;
  while (x < 0) x += MOD;
  return x;
}
int pw(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = 1ll * ret * a % MOD;
    b >>= 1;
    a = 1ll * a * a % MOD;
  }
  return ret;
}
const int MAXN = 1e4 + 10;
long long n, L, v1, v2, k;
void solve() {
  cin >> n >> L >> v1 >> v2 >> k;
  int groups = (n + k - 1) / k;
  long double T_f =
      (long double)L /
      (v1 * (groups - 1) * (1. + (long double)(v2 - v1) / (v2 + v1)) + v2);
  long double T_b = T_f * (v2 - v1) / (v2 + v1);
  cout << groups * T_f + (groups - 1) * T_b << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  int te = 1;
  for (int w = 1; w <= te; w++) {
    solve();
  }
  return 0;
}
