#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 2000000000;
const long long BIG = 1446803456761533460LL;
const int maxn = 200010;
const int maxnlg = 20;
int n;
int B[maxn];
pair<int, int> A[maxn];
int poww(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = (1LL * (r) * (a)) % MOD;
    a = (1LL * (a) * (a)) % MOD;
    b >>= 1;
  }
  return r;
}
pair<int, int> inter(pair<int, int> &a, pair<int, int> &b) {
  return {max(a.first, b.first), min(a.second, b.second)};
}
int length(pair<int, int> a) { return max(0, a.second - a.first + 1); }
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i].first;
  for (int i = 0; i < n; ++i) cin >> A[i].second;
  int ps = 0;
  int f = 0, f2 = 0;
  for (int i = 0; i < n - 1; ++i) {
    int a = length(inter(A[i], A[i + 1]));
    int b = poww(1LL * length(A[i]) * length(A[i + 1]) % MOD, MOD - 2);
    B[i] = 1 - 1LL * a * b % MOD + MOD;
    f = ((f) + (B[i])) % MOD;
    if (i >= 2) {
      ps = ((ps) + (B[i - 2])) % MOD;
      f2 = ((f2) + (1LL * B[i] * ps % MOD)) % MOD;
    }
  }
  for (int i = 0; i < n - 2; ++i) {
    pair<int, int> a = inter(A[i], A[i + 1]);
    pair<int, int> b = inter(A[i + 1], A[i + 2]);
    pair<int, int> c = inter(a, b);
    int s = (1LL * length(a) * length(A[i + 2]) +
             1LL * length(b) * length(A[i]) - length(c)) %
            MOD;
    int t = poww(
        1LL * length(A[i]) * length(A[i + 1]) % MOD * length(A[i + 2]) % MOD,
        MOD - 2);
    f2 = ((f2) + (1 - 1LL * s * t % MOD + MOD)) % MOD;
  }
  int ans = (1LL * f2 * 2 + 1LL * f * 3 + 1) % MOD;
  cout << ans << '\n';
}
