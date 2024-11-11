#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, d;
  cin >> n >> d;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long mn = 2e9;
  long long check = 0;
  for (long long i = 0; i < n - 1; i++) {
    for (long long j = n - 1; j > i; j--) {
      if (a[j] - a[i] <= d) {
        mn = min(n - j - 1 + i, mn);
        check = 1;
      }
    }
  }
  if (check == 0) mn = n - 1;
  cout << mn << "\n";
  return 0;
}
