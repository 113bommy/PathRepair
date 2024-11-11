#include <bits/stdc++.h>
const int N = 400010, P = 1000000007;
int n, m, w[N], l[N], r[N], p[N];
char s[N], t[N];
bool compare(int x, int ll) {
  if (x < ll) return (true);
  int left = (l[x] - l[x - ll] * p[ll]) * p[x - ll], right = r[x] - r[x - ll];
  return (left != right);
}
bool dfs(int d, int change) {
  if (d > n) return (true);
  for (t[d] = (change ? 'a' : s[d]); t[d] <= 'z'; t[d]++) {
    l[d] = l[d - 1] * P + t[d] - 'a';
    r[d] = r[d - 1] + (t[d] - 'a') * p[d - 1];
    if (compare(d, m) && compare(d, m + 1))
      if (dfs(d + 1, (change | (t[d] != s[d])))) return (true);
  }
  return (false);
}
int main() {
  int i;
  scanf("%d%s", &m, s + 1);
  n = strlen(s + 1);
  p[0] = 1;
  for (i = 1; i <= n; i++) p[i] = p[i - 1] * P;
  i = n;
  while (s[i] == 'z') {
    s[i] = 'a';
    i--;
  }
  if (i == 0) {
    printf("Impossible");
    return (0);
  }
  s[i]++;
  l[0] = r[0] = 0;
  if (!dfs(1, false))
    printf("Impossble");
  else
    for (i = 1; i <= n; i++) printf("%c", t[i]);
  return (0);
}
