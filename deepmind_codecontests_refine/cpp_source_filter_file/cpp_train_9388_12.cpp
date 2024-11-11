#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, x;
    cin >> n >> x;
    long long d[n], h[n];
    for (long long i = 0; i < n; i++) cin >> d[i] >> h[i];
    long long net[n];
    for (long long i = 0; i < n; i++) net[i] = d[i] - h[i];
    long long netmax = LONG_MIN, dmax = LONG_MIN;
    for (long long i = 0; i < n; i++)
      if (net[i] > netmax) netmax = net[i];
    for (long long i = 0; i < n; i++)
      if (d[i] > dmax) dmax = d[i];
    if (netmax <= 0 && dmax <= 0)
      cout << -1 << endl;
    else {
      long long res = 0;
      if (x > dmax) {
        if ((x - dmax) % netmax == 0)
          res = 1 + (x - dmax) / netmax;
        else
          res = 2 + (x - dmax) / netmax;
      } else
        res = 1;
      cout << res << endl;
    }
  }
  return 0;
}
