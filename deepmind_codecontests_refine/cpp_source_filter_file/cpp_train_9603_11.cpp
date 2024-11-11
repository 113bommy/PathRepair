#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b > a) {
      cout << b << "\n";
      continue;
    }
    long long time = b;
    if (d >= c) {
      cout << "-1\n";
      continue;
    }
    time += ((a - b + c - d - 1) / (c - d)) * c;
    cout << time << "\n";
  }
  return 0;
}
