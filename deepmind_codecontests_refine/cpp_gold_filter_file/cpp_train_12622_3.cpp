#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (d - b) * (c - a) + 1 << endl;
  }
  return 0;
}
