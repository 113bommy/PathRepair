#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
inline int read() {
  int x = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return w == 1 ? x : -x;
}
int n, cnt, tot, l[800005], r[800005], a[800005 << 1], lx[800005], rx[800005],
    p[800005], t[800005], p2[800005], h[800005];
int main() {
  int T = read();
  while (T--) {
    n = read();
    cnt = 0;
    tot = 0;
    for (int i = 1; i <= n; i++) {
      l[i] = read(), r[i] = read();
      a[++cnt] = l[i], a[++cnt] = r[i];
    }
    sort(a + 1, a + cnt + 1);
    tot = unique(a + 1, a + cnt + 1) - a - 1;
    for (int i = 1; i <= n; i++) {
      lx[i] = lower_bound(a + 1, a + tot + 1, l[i]) - a;
      rx[i] = lower_bound(a + 1, a + tot + 1, r[i]) - a;
      lx[i] <<= 1;
      rx[i] <<= 1;
    }
    int tmp = 0;
    for (int i = 1; i <= tot * 2; i++) p2[i] = 0, h[i] = 0, p[i] = 0;
    for (int i = 1; i <= tot * 2; i++) t[i] = 0;
    for (int i = 1; i <= n; i++) t[lx[i]]++, t[rx[i] + 1]--;
    for (int i = 1; i <= tot * 2; i++) tmp += t[i], p[i] = tmp;
    for (int i = 1; i <= tot * 2; i++)
      if (p[i] != p[i - 1] && p[i] == 1) p2[i] = 1;
    for (int i = 1; i <= tot * 2; i++) h[i] = h[i - 1] + p2[i];
    int ans = 0, ans1 = 0;
    for (int i = 1; i <= tot * 2 + 1; i++)
      if (p[i] != 0 && p[i - 1] == 0) ans1++;
    for (int i = 1; i <= n; i++) {
      int q = h[rx[i]] - h[lx[i] - 1];
      q -= (p[rx[i]] == 1), q -= (p[lx[i]] == 1);
      ans = max(ans, q);
    }
    cout << ans1 + ans << endl;
  }
  return 0;
}
