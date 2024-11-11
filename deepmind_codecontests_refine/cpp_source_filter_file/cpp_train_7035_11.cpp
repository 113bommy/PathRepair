#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 1000005;
const long long MOD = 1e9 + 7;
const double eps = 1e-9;
int n, k, a[N], last[N], nxt[N][27];
bool f[N];
char s[N], t[N];
bool check(int m) {
  memset(f, 1, sizeof f);
  for (int i = 0; i < m; i++) f[a[i]] = 0;
  memset(last, -1, sizeof last);
  for (int i = n - 1; i >= 0; i--) {
    if (!f[i]) continue;
    for (int j = 0; j < 26; j++) nxt[i][j] = last[j];
    last[s[i] - 'a'] = i;
  }
  int i = 0;
  int cur = last[t[i] - 'a'];
  while (i < k) {
    if (cur == -1) return 0;
    i++;
    if (i == k) break;
    cur = nxt[cur][t[i] - 'a'];
  }
  return 1;
}
int main() {
  scanf("%s%s", s, t);
  n = strlen(s);
  k = strlen(t);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  int l = 0, r = n - 1, m, best = -1;
  while (l <= r) {
    m = (l + r) / 2;
    if (check(m)) {
      best = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  printf("%d\n", best);
  return 0;
}
