#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
[[gnu::constructor]] void fast_iostream() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
}
int main() {
  while (1) {
    string s;
    cin >> s;
    if (s != "start") break;
    string a;
    cout << "? 0 1" << endl;
    cin >> a;
    if (a == "x") {
      cout << "! 1" << endl;
      continue;
    }
    long long x = 1, y = 2;
    while (a != "x") {
      cout << "? " << x << " " << y << endl;
      cin >> a;
      x *= 2;
      y *= 2;
    }
    x /= 2;
    y /= 2;
    int l = x + 1, r = y;
    while (l < r) {
      int m = (l + r) / 2;
      cout << "? " << x << " " << m << endl;
      cin >> a;
      if (a == "x")
        r = m;
      else
        l = m + 1;
    }
    cout << "! " << r << endl;
  }
  return 0;
}
