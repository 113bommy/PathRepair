#include <bits/stdc++.h>
using namespace std;
long long n, k, C = 1, ans = 0, M = 1e9 + 7;
long long mod_pow(long long a, long long k) {
  if (!k) return 1;
  long long t = mod_pow(a, k >> 1);
  t = t * t % M;
  if (k & 1) t = t * a % M;
  return t;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i <= n; i++) {
    C = i ? C * (n - i + 1) % M * mod_pow(i, M - 2) % M : 1;
    long long b =
        (M + mod_pow(k, n - i) * mod_pow(k - 1, i) % M - mod_pow(k - 1, n)) % M;
    b = C * mod_pow(b, n);
    ans = i % 2 == 0 ? (ans + b) % M : (M + ans - b) % M;
  }
  cout << ans << endl;
  return 0;
}
