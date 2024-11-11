#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5, mod = 1e9 + 7;
long long n, l[N], r[N], p[N - 1];
long long quick_exp(long long a, int k) {
  if (k == 0) return 1;
  long long p = quick_exp(a, k / 2);
  return (k % 2 == 0 ? (p * p) % mod : (((p * p) % mod) * a) % mod);
}
long long inv(int a) { return quick_exp(a, mod - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> l[i];
  for (int i = 0; i < n; i++) cin >> r[i];
  for (int i = 0; i < n - 1; i++) {
    long long inter = max(min(r[i], r[i + 1]) - max(l[i], l[i + 1]) + 1, 0LL),
              den = (r[i] - l[i] + 1) * (r[i + 1] - l[i + 1] + 1) % mod;
    p[i] = inter * inv(den);
    p[i] = (mod + 1 - p[i]);
    if (p[i] >= mod) p[i] -= mod;
  }
  long long sol = 1, sum = 0;
  for (int i = 0; i < n - 1; i++) {
    sum += p[i];
    if (sum >= mod) sum -= mod;
  }
  sol += sum * (sum + 3);
  ;
  sol %= mod;
  for (int i = 0; i < n - 1; i++) {
    sol += mod - p[i] * p[i] % mod;
    if (sol >= mod) sol -= mod;
  }
  for (int i = 0; i < n - 2; i++) {
    long long x = p[i] + p[i + 1] - 1 + mod;
    long long inter = max(min(min(r[i], r[i + 1]), r[i + 2]) -
                              max(max(l[i], l[i + 1]), l[i + 2]) + 1,
                          0LL),
              den = (r[i] - l[i] + 1) * (r[i + 1] - l[i + 1] + 1) % mod *
                    (r[i + 2] - l[i + 2] + 1) % mod;
    x += inter * inv(den);
    x %= mod;
    x += mod - p[i] * p[i + 1] % mod;
    if (x >= mod) x -= mod;
    x += x;
    if (x >= mod) x -= mod;
    sol += x;
    if (sol >= mod) sol -= mod;
  }
  cout << sol << endl;
  return 0;
}
