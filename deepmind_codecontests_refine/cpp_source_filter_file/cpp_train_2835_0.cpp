#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long ecount = 0, ocount = 0;
    for (long long i = 0; i < n; i++) {
      if (arr[i] % 2 == 0)
        ecount++;
      else
        ocount++;
    }
    if ((ecount == n && ocount == 0) || (ocount == n && ecount == 0))
      cout << "YES"
           << "\n";
    else {
      cout << "N0"
           << "\n";
    }
  }
  return 0;
}
