#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> r;
int find_max(int x, int y, int direct) {
  if (direct == 1) {
    int c = y;
    for (int i = m - 1; i >= y; i--) {
      if (r[x][i] == 'W') {
        c = i;
        break;
      }
    }
    if (x != (r.size() - 1)) {
      for (int i = m - 1; i >= c; i--) {
        if (r[x + 1][i] == 'W') {
          c = i;
          break;
        }
      }
    }
    return c;
  } else {
    int c = y;
    for (int i = 0; i <= y; i++) {
      if (r[x][i] == 'W') {
        c = i;
        break;
      }
    }
    if (x != (r.size() - 1)) {
      for (int i = 0; i <= c; i++) {
        if (r[x + 1][i] == 'W') {
          c = i;
          break;
        }
      }
    }
    return c;
  }
}
int Abs(int x) { return x > 0 ? x : -x; }
int main() {
  cin >> n >> m;
  r.resize(n);
  int n_g = 0;
  for (int i = 0; i < n; i++) {
    cin >> r[i];
    if (r[i].find('G') != string::npos) n_g = i + 1;
  }
  int ans = 0;
  int x = 0, y = 0;
  int direct = 1;
  for (int i = 0; i < n_g; i++) {
    int c = find_max(x, y, direct);
    ans = ans + (Abs(y - c));
    y = c;
    direct = -direct;
    if (i != (n_g - 1)) {
      x = x + 1;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
