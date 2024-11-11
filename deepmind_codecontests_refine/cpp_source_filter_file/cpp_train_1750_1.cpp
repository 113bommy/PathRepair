#include <bits/stdc++.h>
using namespace std;
int main() {
  do {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  } while (false);
  int n, m, len, sx, sy;
  cin >> n >> m >> len;
  cin >> sx >> sy;
  string S, T;
  cin >> S >> T;
  int lx = 1, rx = n, ly = 1, ry = m;
  for (int i = len - 1; i >= 0; i--) {
    if (T[i] == 'D') {
      lx = max(1, lx - 1);
    } else if (T[i] == 'U') {
      rx = min(n, rx + 1);
    } else if (T[i] == 'L') {
      ly = max(1, ly - 1);
    } else {
      ry = min(m, ry + 1);
    }
    if (S[i] == 'D') {
      rx--;
    } else if (S[i] == 'U') {
      lx++;
    } else if (S[i] == 'L') {
      ry--;
    } else {
      ly++;
    }
    if (lx > rx || ly > ry) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << (lx <= sx && sx <= rx && ly <= sy && sy <= ry ? "YES" : "NO") << endl;
  return 0;
}
