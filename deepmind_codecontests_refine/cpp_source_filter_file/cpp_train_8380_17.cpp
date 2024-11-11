#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int x, y, x0, y0;
  cin >> x >> y >> x0 >> y0;
  string s;
  cin >> s;
  cout << 1 << " ";
  vector<vector<int> > vis(x + 1, vector<int>(y + 1, 0));
  vis[x0][y0] = 1;
  for (int i = 0; i < s.length(); i++) {
    bool mov = false;
    if (s[i] == 'U') {
      if (x0 != 1) {
        mov = true;
        x0--;
      }
    } else if (s[i] == 'D') {
      if (x0 != x) {
        mov = true;
        x0++;
      }
    } else if (s[i] == 'L') {
      if (y0 != 0) {
        mov = true;
        y0--;
      }
    } else if (s[i] == 'R') {
      if (y0 != y) {
        mov = true;
        y0++;
      }
    }
    if (i == s.length() - 1) {
      int cnt = 0;
      for (int j = 1; j < x + 1; j++)
        for (int k = 1; k < y + 1; k++) {
          if (vis[j][k] == 0) cnt++;
        }
      cout << cnt << endl;
      return 0;
    }
    if (vis[x0][y0])
      cout << 0 << " ";
    else {
      vis[x0][y0] = 1;
      cout << 1 << " ";
    }
  }
  return 0;
}
