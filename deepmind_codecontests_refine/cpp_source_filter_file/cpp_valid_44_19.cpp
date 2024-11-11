#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long c, d;
    cin >> c >> d;
    if (c == 0 && d == 0) {
      cout << 0 << endl;
      continue;
    }
    if (abs(c) == abs(d)) {
      cout << 1 << endl;
      continue;
    }
    if (abs(c - d) == 1) {
      cout << -1 << endl;
      continue;
    }
    cout << 2 << endl;
  }
}
