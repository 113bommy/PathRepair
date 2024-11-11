#include <bits/stdc++.h>
using namespace std;
const long long INF = 15;
const long long INFN = 105;
long long t, m, ll, vis[INFN], cnt;
char ch[INF];
bool check(long long l, long long r) {
  if (r > m) return false;
  for (long long i = l; i <= r; i++)
    if (vis[i] != 1e18) return false;
  return true;
}
signed main() {
  scanf("%lld %lld", &t, &m);
  ll = 1;
  for (long long i = 1; i <= m; i++) vis[i] = 1e18;
  for (long long i = 1; i <= t; i++) {
    scanf("%s", ch);
    if (ch[0] == 'a') {
      long long xx = 0;
      scanf("%lld", &xx);
      cnt++;
      bool fl = false;
      for (long long j = 1; j <= m - xx + 1; j++) {
        if (check(j, j + xx - 1)) {
          for (long long k = j; k <= j + xx - 1; k++) vis[k] = cnt;
          fl = true;
          break;
        }
      }
      if (!fl)
        cout << "NULL\n", cnt--;
      else
        cout << cnt << "\n";
    }
    if (ch[0] == 'e') {
      long long xx = 0;
      scanf("%lld", &xx);
      bool fl = false;
      for (long long i = 1; i <= m; i++)
        if (vis[i] == xx) {
          vis[i] = 1e18;
          fl = true;
        }
      if (!fl) cout << "ILLEGAL_ERASE_ARGUMENT\n";
    }
    if (ch[0] == 'd') {
      for (long long i = 1; i <= m; i++) {
        if (vis[i] == 1e18) continue;
        long long j = i;
        for (; j <= m; j++)
          if (vis[i] != vis[j]) break;
        j--;
        if (j > m) j = m;
        long long k = i - 1;
        for (; k >= 1; k--)
          if (vis[k] == 1e18) break;
        k++;
        if (k < 1) k = 1;
        long long tt = vis[i];
        if (k == i) continue;
        for (long long l = i; l <= j; l++) vis[l] = 1e18;
        for (long long l = k; l <= j - i + k; l++) vis[l] = tt;
      }
    }
  }
  return 0;
}
