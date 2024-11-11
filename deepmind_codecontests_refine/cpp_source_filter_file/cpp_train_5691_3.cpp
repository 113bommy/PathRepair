#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long Mul(long long a, long long b) { return a * b % MOD; }
void Add(long long &a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
long long gt[1001000], rev_gt[1001000];
long long POW(long long a, long long k) {
  if (k == 0) return 1;
  long long temp = POW(a, k >> 1);
  temp = Mul(temp, temp);
  if (k % 2) temp = Mul(temp, a);
  return temp;
}
long long C(int k, int n) { return Mul(gt[n], Mul(rev_gt[k], rev_gt[n - k])); }
long long f(int n, int k) {
  if (n < k) return 0;
  int hs = 1;
  if (k % 2) hs = -1;
  long long ans = 0;
  for (int i = (1); i <= (k); ++i) {
    hs = -1 * hs;
    long long now = Mul(C(i, k), POW(i, n));
    if (hs == -1) now = MOD - now;
    ans += now;
  }
  return Mul(ans, rev_gt[k]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  gt[0] = 1;
  for (int i = (1); i <= (n); ++i) gt[i] = Mul(gt[i - 1], i);
  rev_gt[n] = POW(gt[n], MOD - 2);
  for (int i = (n - 1); i >= (0); --i) rev_gt[i] = Mul(rev_gt[i + 1], i + 1);
  long long sum = 0;
  for (int i = (1); i <= (n); ++i) {
    int x;
    cin >> x;
    Add(sum, x);
  }
  long long ans = f(n, k);
  Add(ans, Mul(n - 1, f(n - 1, k)));
  cout << Mul(ans, sum);
}
