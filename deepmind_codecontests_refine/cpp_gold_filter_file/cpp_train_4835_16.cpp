#include <bits/stdc++.h>
using namespace std;
int mp[110][110];
inline int cc(int x) {
  int res = 0;
  for (; x; x -= x & -x) res++;
  return res;
}
int main() {
  int m, n, kk;
  scanf("%d%d%d", &m, &n, &kk);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) scanf("%d", &mp[i][j]);
  if (m == 1 || n == 1) {
    puts("0");
    return 0;
  }
  int ans = 20, t0, t1, t2;
  if (m <= 10) {
    for (int i = 0; i < 1 << m; i++) {
      t1 = 0;
      for (int j = 0; j < n; j++) {
        t0 = 0;
        for (int k = 0; k < m; k++) t0 = t0 * 2 + mp[k][j];
        t1 += min(cc(i ^ t0), cc(((1 << m) - 1 - i) ^ t0));
      }
      ans = min(ans, t1);
    }
  } else {
    for (int i = 0; i < m; i++) {
      t2 = 0;
      for (int j = 0; j < m; j++) {
        t0 = t1 = 0;
        for (int k = 0; k < n; k++) {
          t0 += (mp[j][k] == mp[i][k]);
          t1 += mp[j][k] != mp[i][k];
        }
        t2 += min(t0, t1);
      }
      ans = min(ans, t2);
    }
  }
  if (ans <= kk)
    printf("%d\n", ans);
  else
    puts("-1");
  return 0;
}
