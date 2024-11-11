#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s, ca, pre;
  scanf("%d", &n);
  s = sqrt(n);
  int a[n], q, l, r, k, ans = 0, ls, rs;
  m = n / s + 1;
  int b[n][m];
  deque<int> c[n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) b[i][j] = 0;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    b[i / s][a[i]]++;
    c[i / s].push_back(a[i]);
  }
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &ca);
    if (ca == 1) {
      scanf("%d%d", &l, &r);
      l = 1 + (n + l + ans - 1) % n;
      r = 1 + (n + r + ans - 1) % n;
      if (l > r) swap(l, r);
      l--;
      r--;
      ls = l / s;
      rs = r / s;
      if (ls != rs) {
        pre = c[rs][0];
        for (int i = 0; i <= r % s; i++) swap(pre, c[rs][i]);
        c[rs].pop_front();
        b[ls][pre]++;
        b[rs][pre]--;
        for (int i = l % s; i < c[ls].size(); i++) swap(pre, c[ls][i]);
        b[ls][pre]--;
        for (int i = ls + 1; i < rs; i++) {
          b[i][pre]++;
          c[i].push_front(pre);
          pre = c[i].back();
          c[i].pop_back();
          b[i][pre]--;
        }
        b[rs][pre]++;
        c[rs].push_front(pre);
      } else {
        pre = c[rs][r % s];
        for (int i = l % s; i <= r % s; i++) swap(pre, c[rs][i]);
      }
    } else {
      scanf("%d%d%d", &l, &r, &k);
      l = 1 + (n + l + ans - 1) % n;
      r = 1 + (n + r + ans - 1) % n;
      k = 1 + (n + k + ans - 1) % n;
      if (l > r) swap(l, r);
      ans = 0;
      l--;
      r--;
      ls = l / s;
      rs = r / s;
      if (ls != rs) {
        for (int i = l % s; i < c[ls].size(); i++)
          if (c[ls][i] == k) ans++;
        for (int i = ls + 1; i < rs; i++) ans += b[i][k];
        for (int i = 0; i <= r % s; i++)
          if (c[rs][i] == k) ans++;
      } else {
        for (int i = l % s; i <= r % s; i++)
          if (c[ls][i] == k) ans++;
      }
      printf("%d\n", ans);
    }
  }
}
