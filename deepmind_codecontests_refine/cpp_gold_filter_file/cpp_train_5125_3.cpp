#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long i1 = 0; i1 < t; ++i1) {
    long long n, d;
    cin >> n >> d;
    long long a[n];
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (long long i = 1; i < n; ++i) {
      if (i * a[i] <= d) {
        a[0] += a[i];
        d -= i * a[i];
      } else {
        a[0] = a[0] + d / i;
        d = 0;
      }
      if (d == 0) break;
    }
    cout << a[0] << endl;
  }
  return 0;
}
