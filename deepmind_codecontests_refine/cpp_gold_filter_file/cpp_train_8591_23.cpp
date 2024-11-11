#include <bits/stdc++.h>
using namespace std;
const int E = INT_MAX;
int x[5], y[5], ansx[4], ansy[4], nx[4], ny[4];
int calc(int x[], int y[], int nx[], int ny[], int ans[]) {
  int p[4] = {0, 1, 2, 3}, ret = INT_MAX;
  do {
    int cur = 0;
    for (int i = 0; i < 4; i++)
      if (x[i] == nx[p[i]])
        cur = max(cur, abs(y[i] - ny[p[i]]));
      else if (y[i] == ny[p[i]])
        cur = max(cur, abs(x[i] - nx[p[i]]));
      else
        cur = INT_MAX;
    if (cur < ret) {
      for (int i = 0; i < 4; i++) ans[i] = p[i];
      ret = cur;
    }
  } while (next_permutation(p, p + 4));
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    for (int i = 0; i < 4; i++) cin >> x[i] >> y[i];
    int ans = INT_MAX;
    x[4] = 1;
    y[4] = 0;
    auto upd = [&]() {
      int p[4] = {0, 1, 2, 3}, tmp = calc(x, y, nx, ny, p);
      if (tmp < ans) {
        ans = tmp;
        if (x[4] == 1)
          for (int i = 0; i < 4; i++) ansx[i] = nx[p[i]], ansy[i] = ny[p[i]];
        else if (x[4] == 0)
          for (int i = 0; i < 4; i++) ansx[i] = ny[p[i]], ansy[i] = nx[p[i]];
      }
    };
    for (int msk = 0; msk < 16; msk++) {
      int xx[] = {E, E, E, E}, yy[] = {E, E, E, E};
      for (int i = 0; i < 4; i++) {
        int *tt = ((msk >> i) & 1) == x[4] ? xx : yy;
        int v = ((msk >> i) & 1) == x[4] ? x[i] : y[i], j = 0;
        while (tt[j] != E && tt[j] != v) ++j;
        tt[j] = v;
      }
      if (xx[2] != E || yy[2] != E) continue;
      if (xx[1] == E && yy[1] == E) continue;
      if (yy[0] == E) swap(x, y), swap(xx, yy);
      if (xx[0] == E) {
        int d = abs(yy[0] - yy[1]);
        ny[0] = ny[2] = yy[0];
        ny[1] = ny[3] = yy[1];
        for (int i = 0; i < 4; i++) {
          int t[] = {i >> 1, i & 1}, l = INT_MAX, r = INT_MIN;
          for (int j = 0; j < 4; j++) {
            int c = y[j] == yy[1], v = t[c] ? x[j] + d : x[j];
            t[c] ^= 1;
            l = min(l, v);
            r = max(r, v);
          }
          int mid = (l + r + 1) >> 1;
          nx[0] = nx[1] = mid;
          nx[2] = nx[3] = mid - d;
          upd();
        }
        continue;
      }
      if (yy[1] == E) swap(x, y), swap(xx, yy);
      if (xx[1] == E) {
        int d = abs(yy[0] - yy[1]);
        nx[0] = nx[1] = xx[0];
        ny[0] = ny[2] = yy[0];
        ny[1] = ny[3] = yy[1];
        nx[2] = nx[3] = xx[0] - d;
        upd();
        nx[2] = nx[3] = xx[0] + d;
        upd();
        continue;
      }
      if (abs(xx[0] - xx[1]) == abs(yy[0] - yy[1])) {
        nx[0] = nx[1] = xx[0];
        ny[0] = ny[2] = yy[0];
        nx[2] = nx[3] = xx[1];
        ny[1] = ny[3] = yy[1];
        upd();
      }
    }
    if (ans == INT_MAX) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
      for (int i = 0; i < 4; i++) cout << ansx[i] << ' ' << ansy[i] << endl;
    }
  }
  return 0;
}
