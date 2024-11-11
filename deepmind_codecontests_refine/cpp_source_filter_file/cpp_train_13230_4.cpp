#include <bits/stdc++.h>
using namespace std;
int n, m, tot, x, t, fw, rt, ans;
char str[200010];
int s[200010], st[200010], ed[200010], nt[200010], p[200010], w[200010],
    v[200010], pr[200010], fl[200010], q[200010], ss[200010];
void lk(int x, int y, int z) {
  if (!st[x])
    st[x] = ++tot;
  else
    nt[ed[x]] = ++tot;
  ed[x] = tot;
  p[tot] = y;
  w[tot] = z;
  if (!st[y])
    st[y] = ++tot;
  else
    nt[ed[y]] = ++tot;
  ed[y] = tot;
  p[tot] = x;
}
void dfs(int x) {
  v[x] = 1;
  for (int i = st[x]; i; i = nt[i])
    if (w[i] && (!v[p[i]])) {
      pr[p[i]] = i ^ 1;
      dfs(p[i]);
    }
}
int main() {
  for (scanf("%s", str); str[n]; n++) s[str[n] - 'a']++;
  scanf("%d", &m);
  tot = 1;
  for (int i = (1); i <= (m); i++) {
    for (int j = (0); j <= (5); j++) v[j] = 1;
    t = 0;
    scanf("%d", &x);
    scanf("%s", str);
    for (int j = 0; str[j]; j++) v[str[j] - 'a'] = 0;
    for (int j = (0); j <= (5); j++)
      if (v[j]) t += 1 << j;
    q[x] = t;
  }
  for (int i = (0); i <= (5); i++) v[i] = 0;
  for (int i = (1); i <= (n); i++) ss[q[i]]++;
  for (int i = (0); i <= (5); i++) lk(1, 2 + i, s[i]);
  for (int i = (0); i <= (62); i++) lk(8 + i, 71, ss[i]);
  for (int i = (0); i <= (5); i++)
    for (int j = (0); j <= (62); j++)
      if (!((j >> i) & 1)) lk(2 + i, 8 + j, 1000000000);
  for (;;) {
    for (int i = (1); i <= (71); i++) v[i] = fl[i] = 0;
    fl[1] = 1000000000;
    for (int o = (1); o <= (71); o++) {
      fw = 0;
      for (int i = (1); i <= (71); i++)
        if ((!v[i]) && (fl[i] > fw)) fw = fl[i], rt = i;
      if (!fw) break;
      v[rt] = 1;
      for (int i = st[rt]; i; i = nt[i])
        if (((w[i]) < (fw) ? (w[i]) : (fw)) > fl[p[i]]) {
          fl[p[i]] = ((w[i]) < (fw) ? (w[i]) : (fw));
          pr[p[i]] = i ^ 1;
        }
    }
    if (!fl[71]) break;
    ans += fl[71];
    for (int i = pr[71]; i; i = pr[p[i]]) w[i] += fl[71], w[i ^ 1] -= fl[71];
  }
  if (ans < n) {
    printf("Impossible");
    return 0;
  }
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (71); j++) v[j] = 0;
    pr[8 + q[i]] = 0;
    dfs(8 + q[i]);
    for (int j = (0); j <= (5); j++)
      if (v[2 + j] && (!((q[i] >> j) & 1))) {
        printf("%c", 'a' + j);
        for (int k = pr[2 + j]; k; k = pr[p[k]]) w[k ^ 1]--;
        break;
      }
  }
}
