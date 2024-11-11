#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int ans[N];
bool vis[555][555];
int main() {
  int n, m, x0, y0;
  ios::sync_with_stdio(false);
  cin >> n >> m >> x0 >> y0;
  string s;
  cin >> s;
  int Len = s.size(), cnt = 1;
  ans[0] = 1;
  vis[x0][y0] = true;
  for (int i = 0; i < Len; i++) {
    if (s[i] == 'U') {
      if (x0 != 1) x0--;
    } else if (s[i] == 'D') {
      if (x0 != n) x0++;
    } else if (s[i] == 'R') {
      if (y0 != m) y0++;
    } else if (s[i] == 'L') {
      if (y0 != 1) y0--;
    }
    if (vis[x0][y0])
      ans[i + 1] = 0;
    else {
      cnt++;
      ans[i + 1] = 1;
      vis[x0][y0] = true;
    }
  }
  ans[Len] = n * m - cnt + 1;
  for (int i = 0; i <= Len; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
