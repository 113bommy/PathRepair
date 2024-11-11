#include <bits/stdc++.h>
using namespace std;
int n, m, q, mp[1200][1200], x1, x2, x3, ans;
int u[1200][1200], d[1200][1200], l[1200][1200], r[1200][1200], num[1200];
inline int calc(int cnt, int pos) {
  int res = 0;
  for (int i = pos + 1; i <= cnt; i++) {
    num[i] = min(num[i - 1], num[i]);
  }
  for (int i = pos - 1; i >= 1; i--) {
    num[i] = min(num[i + 1], num[i]);
  }
  int lp = pos, rp = pos;
  for (int i = num[pos]; i >= 1; i--) {
    while (num[lp - 1] >= i && lp > 1) lp--;
    while (num[rp + 1] >= i && rp < cnt) rp++;
    res = max(res, (rp - lp + 1) * i);
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> mp[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mp[i][j] == 0) {
        u[i][j] = l[i][j] = 0;
      } else {
        u[i][j] = u[i - 1][j] + 1;
        l[i][j] = l[i][j - 1] + 1;
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      if (mp[i][j] == 0) {
        d[i][j] = r[i][j] = 0;
      } else {
        d[i][j] = d[i + 1][j] + 1;
        r[i][j] = r[i][j + 1] + 1;
      }
    }
  }
  for (int ip = 1; ip <= q; ip++) {
    cin >> x1 >> x2 >> x3;
    if (x1 == 1) {
      mp[x2][x3] = 1 - mp[x2][x3];
      for (int i = 1; i <= n; i++) {
        if (mp[i][x3] == 0)
          u[i][x3] = 0;
        else
          u[i][x3] = u[i - 1][x3] + 1;
      }
      for (int i = 1; i <= m; i++) {
        if (mp[x2][i] == 0)
          l[x2][i] = 0;
        else
          l[x2][i] = l[x2][i - 1] + 1;
      }
      for (int i = n; i >= 1; i--) {
        if (mp[i][x3] == 0)
          d[i][x3] = 0;
        else
          d[i][x3] = d[i + 1][x3] + 1;
      }
      for (int i = m; i >= 1; i--) {
        if (mp[x2][i] == 0)
          r[x2][i] = 0;
        else
          r[x2][i] = r[x2][i + 1] + 1;
      }
    } else {
      ans = 0;
      for (int i = 1; i <= n; i++) num[i] = l[i][x3];
      ans = max(ans, calc(n, x3));
      for (int i = 1; i <= n; i++) num[i] = r[i][x3];
      ans = max(ans, calc(n, x3));
      for (int i = 1; i <= m; i++) num[i] = u[x2][i];
      ans = max(ans, calc(m, x2));
      for (int i = 1; i <= m; i++) num[i] = d[x2][i];
      ans = max(ans, calc(m, x2));
      cout << ans << endl;
    }
  }
  return 0;
}
