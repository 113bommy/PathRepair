#include <bits/stdc++.h>
using namespace std;
const int N = 1007;
const long long inf = N;
bool colour[N][N];
int main() {
  int x, y, x0, y0;
  cin >> x >> y >> x0 >> y0;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (colour[x0][y0])
      cout << 0 << " ";
    else
      cout << 1 << " ";
    colour[x0][y0] = true;
    if (s[i] == 'U') {
      if (x0 != 1) x0--;
    }
    if (s[i] == 'D') {
      if (x0 != x) x0++;
    }
    if (s[i] == 'L') {
      if (y0 != 1) y0--;
    }
    if (s[i] == 'R') {
      if (y0 != y) y0++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= x; i++)
    for (int j = 1; j <= y; j++) ans += colour[i][j];
  cout << ans << endl;
  return 0;
}
