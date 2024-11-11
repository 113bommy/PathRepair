#include <bits/stdc++.h>
const long long mod = 1e9 + 9;
using namespace std;
void fail() {
  cout << "0\n";
  exit(0);
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, cnt = 0;
    cin >> n >> k;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      a[i] %= 2;
      if (a[i]) cnt++;
    }
    if ((cnt % 2 != k % 2) || (k > cnt) || (cnt == 0))
      cout << "NO\n";
    else {
      cout << "YES\n";
      for (long long i = 0; i < n && k > 1; i++) {
        if (a[i] % 2) {
          cout << i + 1 << ' ';
          k--;
        }
      }
      cout << n << '\n';
    }
  }
  return 0;
}
