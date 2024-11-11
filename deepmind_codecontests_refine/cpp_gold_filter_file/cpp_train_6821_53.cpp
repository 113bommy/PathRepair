#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double PI = 3.14159265359;
const long long MOD = 998244353;
void i_o() {}
void help(int n, int d, int h) {
  if (d > 2 * h || (d == h && h == 1 && n > 2)) {
    cout << -1;
    return;
  }
  for (int i = 1; i <= h; i++) cout << i << " " << i + 1 << '\n';
  int rem = d - h;
  int x = 1, y = h + 2;
  if (!rem) {
    rem = n - 1 - d;
    while (rem--) {
      cout << h << " " << y << '\n';
      y++;
    }
    return;
  } else {
    while (rem--) {
      cout << x << " " << y << '\n';
      int temp = y;
      x = y;
      y = temp + 1;
    }
    rem = n - 1 - d;
    while (rem--) {
      cout << 1 << " " << y << '\n';
      y++;
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  i_o();
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> A(n + 1, vector<int>(m + 1, 0));
  map<int, pair<int, int>> mr, mc;
  for (int i = 0; i < k; i++) {
    int w, j, c;
    cin >> w >> j >> c;
    if (w == 1) {
      mr[j] = make_pair(c, i);
    } else
      mc[j] = make_pair(c, i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int ne = 0, op = -1;
      if (mr.count(i)) {
        ne = mr[i].first, op = mr[i].second;
      }
      if (mc.count(j)) {
        if (mc[j].second > op) ne = mc[j].first;
      }
      A[i][j] = ne;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << A[i][j] << " ";
    cout << '\n';
  }
  return 0;
}
