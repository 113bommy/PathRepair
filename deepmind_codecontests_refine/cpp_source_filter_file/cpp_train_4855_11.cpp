#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  set<long long> second;
  long long x = 1;
  while (1) {
    long long n = (2 * x - 1) * (x);
    x *= 2;
    if (n <= 100000)
      second.insert(n);
    else
      break;
  }
  long long ans = 1;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      if (second.find(i) != second.end()) ans = max(ans, i);
      if (second.find(n / i) != second.end()) ans = max(ans, n / i);
    }
  }
  cout << ans;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  t = 1;
  while (t--) solve();
  return 0;
}
