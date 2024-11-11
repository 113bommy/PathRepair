#include <bits/stdc++.h>
int k, L, R, tot, x, a[100010], c[510], l[510], r[510], p[26][100010], e[26];
char s[100010], n, ch[2];
long long ans;
void Modify(int l, int r, int d) {
  for (int i = l; i <= r; i++) {
    if (a[i] >= L && a[i] <= R) tot--;
    a[i] += d;
    if (a[i] >= L && a[i] <= R) tot++;
  }
}
int main() {
  scanf("%s", s + 1);
  scanf("%d%d%d\n", &k, &L, &R);
  for (int i = 1; i <= k; i++) {
    scanf("%s%d%d", &ch, &l[i], &r[i]);
    c[i] = ch[0] - 'a';
  }
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    if (!L) tot++;
    x = s[i] - 'a';
    p[x][++e[x]] = i;
    for (int j = 1; j <= k; j++) {
      if (c[j] == x) {
        if (e[x] >= l[j] && l[j])
          Modify(p[x][e[x] - l[j]] + 1, p[x][e[x] - l[j] + 1], 1);
        if (e[x] > r[j])
          Modify(p[x][e[x] - r[j] - 1] + 1, p[x][e[x] - r[j]], -1);
      }
      if (!l[j]) Modify(i, i, 1);
    }
    ans += tot;
  }
  printf("%I64d\n", ans);
  return 0;
}
