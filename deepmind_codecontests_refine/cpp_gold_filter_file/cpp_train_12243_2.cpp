#include <bits/stdc++.h>
using namespace std;
void fast() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  string s;
  cin >> s;
  int x = s[0] - '0', y = s[1] - '0', m = s[3] - '0', n = s[4] - '0';
  int c = 0;
  while (!(x == n && y == m)) {
    int g = m * 10 + n;
    if (g != 59) {
      g++;
      m = g / 10;
      n = g % 10;
    } else {
      m = 0;
      n = 0;
      int z = x * 10 + y;
      if (z != 23) {
        z++;
        x = z / 10;
        y = z % 10;
      } else {
        x = 0;
        y = 0;
      }
    }
    c++;
  }
  cout << c << "\n";
}
int main() {
  fast();
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
