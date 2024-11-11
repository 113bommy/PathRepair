#include <bits/stdc++.h>
using namespace std;
void solve();
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) solve();
  return 0;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long fib[100000 + 2];
  fib[0] = 0, fib[1] = 1;
  for (long long i = 2; i <= 1e5 + 1; i++) {
    fib[i] = (fib[i - 2] + fib[i - 1]) % 1000000007LL;
  }
  cout << (2 * (fib[n + 1] + fib[m + 1] - 1) % 1000000007LL);
  cout << "\n";
  return;
}
