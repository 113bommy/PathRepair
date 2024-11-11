#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 1;
const int N = 1000002;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long power(long long A, long long B, long long mod = 1000000007) {
  long long r = 1;
  while (B > 0) {
    if (B & 1LL) r = (r * A) % mod;
    A = (A * A) % mod;
    B >>= 1;
  }
  return r;
}
struct set_comp {
  bool operator()(const int& lhs, const int& rhs) { return lhs < rhs; }
};
int x[1001];
int b[1001];
int pv[1001];
double dp[1001];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
  int n, L, i, j;
  cin >> n >> L;
  for (i = 1; i <= n; i++) {
    cin >> x[i] >> b[i];
  }
  double l = 0, r = 1e3 + 1, m;
  while (r - l > 1e-9) {
    m = (l + r) / 2;
    for (i = 1; i <= n; i++) {
      dp[i] = 1e18;
      for (j = 0; j < i; j++) {
        if (dp[j] + sqrt(abs(x[i] - x[j] - L)) - m * b[i] < dp[i]) {
          dp[i] = dp[j] + sqrt(abs(x[i] - x[j] - L)) - m * b[i];
          pv[i] = j;
        }
      }
    }
    if (dp[n] < 0)
      r = m;
    else
      l = m;
  }
  int p = n;
  vector<int> v;
  while (p > 0) {
    v.push_back(p);
    p = pv[p];
  }
  reverse(v.begin(), v.end());
  for (int x : v) cout << x << " ";
  cout << endl;
  return 0;
}
