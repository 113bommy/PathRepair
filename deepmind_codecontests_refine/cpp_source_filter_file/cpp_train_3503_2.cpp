#include <bits/stdc++.h>
using namespace std;
const long mod = 1e9 + 7;
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
void solve() {
  long long n, k, a, b;
  cin >> n;
  cin >> k;
  cin >> a;
  cin >> b;
  if (k == 1) {
    cout << a * n << "\n";
    return;
  } else {
    long long ans = 0;
    while (n > 1) {
      if (n >= k) {
        long long mod = n % k;
        long long ne = n / k;
        ans += min(b + mod * a, (n - ne) * a);
        n = ne;
      } else {
        ans += a * (n - 1);
        n = 1;
      }
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  int i = 1;
  while (t--) {
    solve();
    i++;
  }
  return 0;
}
