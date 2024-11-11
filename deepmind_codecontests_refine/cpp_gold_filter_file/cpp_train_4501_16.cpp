#include <bits/stdc++.h>
using namespace std;
const int INF_I = 1e9;
const long long INF_LL = 1e18;
const long long MOD = 998244353;
const int N = 2 * 1e5 + 1;
vector<int> f(N);
int mul(int a, int b) { return (a * 1ll * b) % MOD; }
int fact(int a) { return f[a]; }
int pw(int a, int k) {
  if (k == 0) return 1;
  if (k % 2 == 0) {
    int b = pw(a, k / 2);
    return ((long long)b * b) % MOD;
  }
  return (pw(a, k - 1) * (long long)a) % MOD;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  if (m + 1 < n) {
    cout << "0\n";
    return 0;
  }
  if (n == 2) {
    cout << 0 << "\n";
    return 0;
  }
  f[0] = 1;
  for (int i = 1; i < N; i++) f[i] = mul(f[i - 1], i);
  int res = mul(mul(fact(m), pw(mul(fact(m - (n - 1)), fact(n - 1)), MOD - 2)),
                mul(n - 2, pw(2, n - 3)));
  cout << res << "\n";
  return 0;
}
