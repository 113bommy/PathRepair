#include <bits/stdc++.h>
using namespace std;
int binpow(int x, int n) {
  int ans = 1;
  while (n > 0) {
    if (n & 1) ans *= x;
    x *= x;
    n >>= 1;
  }
  return ans;
}
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) cin >> s[i];
  vector<bool> visited(h * w, false);
  int lx = -1, ly = -1;
  for (int i = 1; i + 1 < h; i++) {
    for (int j = 1; j + 1 < w; j++) {
      if (s[i][j] == '*' && s[i - 1][j] == '*' && s[i + 1][j] == '*' &&
          s[i][j - 1] == '*' && s[i][j + 1] == '*') {
        lx = i, ly = j;
        visited[i * w + j] = true;
        break;
      }
    }
  }
  if (lx == -1) {
    cout << "NO\n";
    return 0;
  }
  for (int i = lx, j = ly; i >= 0 && s[i][ly] == '*'; i--)
    visited[i * w + j] = true;
  for (int i = lx, j = ly; i < h && s[i][ly] == '*'; i++)
    visited[i * w + j] = true;
  for (int j = ly, i = lx; j >= 0 && s[lx][j] == '*'; j--)
    visited[i * w + j] = true;
  for (int j = ly, i = lx; i < w && s[lx][j] == '*'; j++)
    visited[i * w + j] = true;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '*' && !visited[i * w + j]) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
}
