#include <bits/stdc++.h>
using namespace std;
map<long long, int> ha;
long long n, m, mm;
int ans;
int a[20], s, vis[20];
long long p[10000];
long long ch[20];
void dfs(int k, long long t) {
  long long tt;
  if (k == 10) return;
  tt = t * 10 + 4;
  p[++s] = tt;
  ha[tt] = 1;
  dfs(k + 1, tt);
  tt = t * 10 + 7;
  p[++s] = tt;
  ha[tt] = 1;
  dfs(k + 1, tt);
}
void work() {
  int i, j, len, k;
  memset(vis, 0, sizeof(vis));
  ch[0] = 1;
  for (i = 1; i <= 13; i++) ch[i] = ch[i - 1] * i;
  m--;
  for (i = 1; i <= 13; i++) {
    k = 13 - i;
    for (j = 1; j <= 13; j++) {
      if (vis[j]) continue;
      if (m >= ch[k])
        m -= ch[k];
      else {
        a[i] = j;
        vis[j] = 1;
        break;
      }
    }
  }
}
void solve() {
  int i, j, k;
  ans = 0;
  if (n > 13) {
    for (i = 1; i <= s; i++)
      if (p[i] < n - 13)
        ans++;
      else
        break;
    for (i = 1; i <= 13; i++)
      if (ha[a[i] + n - 13] > 0 && ha[n - 13 + i] > 0) ans++;
  } else {
    if (ch[n] < mm) {
      printf("-1\n");
      return;
    }
    k = 13 - n;
    for (i = 1; i <= n; i++)
      if (ha[a[i + k] - k] && ha[i]) ans++;
  }
  printf("%d\n", ans);
}
int main() {
  int i, j, k;
  s = 0;
  ha.clear();
  dfs(0, 0);
  sort(p + 1, p + s + 1);
  scanf("%I64d%I64d", &n, &m);
  mm = m;
  work();
  solve();
  return 0;
}
