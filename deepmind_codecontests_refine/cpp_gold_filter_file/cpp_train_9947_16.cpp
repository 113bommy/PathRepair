#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, s, x;
  cin >> t >> s >> x;
  if (t > x)
    cout << "NO\n";
  else if (t == x)
    cout << "YES\n";
  else if (t + s > x)
    cout << "NO\n";
  else if (t + s == x || t + s + 1 == x)
    cout << "YES\n";
  else {
    long long u = (x - t) / s;
    if (u * s + t == x) {
      cout << "YES\n";
      return 0;
    }
    u = (x - t - 1) / s;
    if (u * s + t + 1 == x) {
      cout << "YES\n";
      return 0;
    }
    cout << "NO\n";
  }
}
