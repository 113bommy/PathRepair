#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a <= b)
      cout << b << endl;
    else {
      if (d >= c)
        cout << -1 << endl;
      else {
        long long int val = c - d;
        long long int f = ceil((a - b) / float(val));
        cout << (b + c * f) << endl;
      }
    }
  }
  return 0;
}
