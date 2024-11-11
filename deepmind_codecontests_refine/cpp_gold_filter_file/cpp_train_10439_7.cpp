#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
long long random2() { return (1ll << 31ll) * eng() + eng(); }
long long n, m, k, q, T;
const long long big = 1000000007;
const long long big2 = 1000000009;
const long long mod = 998244353;
const int MAXN = 200001;
vector<vector<vector<int> > > C(10, vector<vector<int> >());
vector<long long> A, B;
bool evil() {
  if (n % 2 == 0) return 0;
  long long mi = big;
  long long ma = -big;
  for (int c1 = 0; c1 < (n); ++c1) {
    if (c1 % 2 == 0) mi = min(mi, A[c1]);
    if (c1 % 2 == 1) ma = max(ma, A[c1]);
  }
  if (mi > ma) return 1;
  return 0;
}
long long solve_evil() {
  long long mi = big;
  long long ma = -big;
  long long sum_a = 0;
  long long sum_b = 0;
  for (int c1 = 0; c1 < (n); ++c1) {
    if (c1 % 2 == 0) {
      mi = min(mi, A[c1]);
      sum_a += A[c1];
    }
    if (c1 % 2 == 1) {
      ma = max(ma, A[c1]);
      sum_b += A[c1];
    }
  }
  return sum_a - sum_b - 2 * mi + 2 * ma;
}
long long solve(long long pos) {
  long long res = 0;
  if (pos - 1 == n / 2 && evil()) {
    return solve_evil();
  }
  for (int c1 = 0; c1 < n; c1++) {
    if (c1 < pos) {
      res += B[c1];
    } else {
      res -= B[c1];
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b, c;
  cin >> n;
  for (int c1 = 0; c1 < (n); ++c1) {
    cin >> a;
    A.push_back(a);
    B.push_back(a);
  }
  if (n == 1) {
    cout << A[0] << "\n";
    return 0;
  }
  if (n == 2) {
    cout << -(A[0] + A[1]) << "\n";
    return 0;
  }
  long long mii = 0;
  for (int c1 = 0; c1 < (n); ++c1) {
    if (A[c1] > 0) mii++;
  }
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());
  int start = 2 - n % 3;
  long long ans = -big * big;
  for (int c1 = start; c1 <= n; c1 += 3) {
    if (abs(c1 - mii) <= 30) {
      long long temp = solve(c1);
      ans = max(temp, ans);
    }
  }
  cout << ans << "\n";
  return 0;
}
