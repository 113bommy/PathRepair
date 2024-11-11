#include <bits/stdc++.h>
using namespace std;
long long int min(long long int a, long long int b) { return (a < b) ? a : b; }
long long int max(long long int a, long long int b) { return (a > b) ? a : b; }
long long int fp(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int x = fp(a, b / 2);
  x = (x * x) % 1000000007;
  if (b & 1) x = (x * a) % 1000000007;
  return x;
}
long long int factorial(long long int n) {
  long long int fact = 1;
  for (long long int i = 2; i <= n; i++) fact = fact * i;
  return fact;
}
long long int ncr(long long int n, long long int r) {
  return factorial(n) / (factorial(r) * factorial(n - r));
}
void c_p_c() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
}
signed main() {
  c_p_c();
  vector<long long int> a(3);
  for (long long int i = 0; i < 3; i++) cin >> a[i];
  long long int full = min({a[0] / 3, a[1] / 2, a[2] / 2});
  a[0] -= (full * 3);
  a[1] -= (full * 2);
  a[2] -= (full * 2);
  long long int ans = 0;
  vector<long long int> idx = {0, 1, 2, 0, 2, 1, 0};
  for (long long int start = 0; start < 7; start++) {
    long long int day = start;
    vector<long long int> b = a;
    long long int cur = 0;
    while (b[idx[day]] > 0) {
      b[idx[day]]--;
      day = (day + 1) % 7;
      cur++;
    }
    ans = max(ans, 7 * full + cur);
  }
  cout << ans << "\n";
}
