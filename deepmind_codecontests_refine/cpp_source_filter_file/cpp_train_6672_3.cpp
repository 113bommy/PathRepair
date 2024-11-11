#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  long long w[n], h[n];
  long long maxcurr;
  for (long long i = 0; i < n; i++) {
    cin >> w[i] >> h[i];
    maxcurr = max(w[i], h[i]);
  }
  for (long long i = 1; i < n; i++) {
    if (max(w[i], h[i]) <= maxcurr) {
      maxcurr = max(w[i], h[i]);
    } else if (min(w[i], h[i]) <= maxcurr) {
      maxcurr = min(w[i], h[i]);
    } else {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
