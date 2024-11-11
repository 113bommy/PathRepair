#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, x, y, m = -1, p;
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    if (x * 100 + y <= s * 100) {
      p = ((s * 100) - (x * 100 + y)) % 100;
      if (p > m) m = p;
    }
  }
  if (m == 0)
    cout << "-1";
  else
    cout << m;
  return 0;
}
