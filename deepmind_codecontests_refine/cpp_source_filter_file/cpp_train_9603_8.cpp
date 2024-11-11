#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, d, rest = 0, val;
    cin >> a >> b >> c >> d;
    if (b >= a)
      cout << b << endl;
    else if (c <= d)
      cout << "-1" << endl;
    else {
      val = ((a - b) / (c - d)) + 1;
      rest = b + (c * val);
      cout << rest << endl;
    }
  }
}
