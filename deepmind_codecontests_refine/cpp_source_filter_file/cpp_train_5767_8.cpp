#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, a, b, x, y;
  cin >> n >> a >> b >> x >> y;
  string s;
  cin >> s;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'E' && a < x)
      a++;
    else if (s[i] == 'W' && a > x)
      a--;
    else if (s[i] == 'N' && b < y)
      b++;
    else if (s[i] == 'S' && b > y)
      y--;
    if (x == a && y == b) {
      cout << i + 1;
      return 0;
    }
  }
  cout << -1;
}
