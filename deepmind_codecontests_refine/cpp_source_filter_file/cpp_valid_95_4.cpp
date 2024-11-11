#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, s;
    cin >> x >> s;
    if (s == 1) {
      cout << x << "\n";
      continue;
    }
    long long a = 1000000000;
    while (s - 1) {
      while (a > x) a /= 10;
      if (x - a < s)
        a /= 10;
      else {
        cout << a << " ";
        x -= a;
        s--;
      }
    }
    cout << x << "\n";
  }
}
