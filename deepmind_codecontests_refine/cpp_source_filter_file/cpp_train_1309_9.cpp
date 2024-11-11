#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N], b[N];
int d;
int tot;
int n, m;
map<int, int> mp;
bool cmp(int aa, int bb) { return aa < bb; }
int quick(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1, x = 1ll * x * x % m) {
    if (y & 1) ret = 1ll * ret * x % m;
  }
  return ret;
}
void getd() {
  int cnt = 0;
  int i;
  int k;
  if (tot == 1) {
    d = 1;
    return;
  }
  d = b[2] - b[1];
  for (i = 1; i <= tot; i++) {
    k = (b[i] + d) % m;
    if (mp[k]) cnt++;
  }
  d = d * quick(tot - cnt, m - 2) % m;
}
void check() {
  int k;
  int cnt = 1;
  k = (a[1] + d) % m;
  while (mp[k]) {
    cnt++;
    k = (k + d) % m;
  }
  k = (a[1] - d + m) % m;
  while (mp[k]) {
    cnt++;
    k = (k - d + m) % m;
  }
  k = (k + d) % m;
  if (cnt == n)
    printf("%d %d", k, d);
  else
    printf("-1");
}
int main() {
  int i;
  scanf("%d%d", &m, &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n, cmp);
  if (n == m || n == 1) {
    printf("%d 1", a[1]);
    return 0;
  }
  if (2 * n > m) {
    for (i = 0; i <= m - 1; i++) mp[i] = 1;
    for (i = 1; i <= n; i++) mp[a[i]] = 0;
    for (i = 0; i <= m - 1; i++)
      if (mp[i]) b[++tot] = i;
  } else {
    for (i = 1; i <= n; i++) mp[a[i]] = 1;
    for (i = 1; i <= n; i++) b[++tot] = a[i];
  }
  getd();
  if (2 * n > m) {
    for (i = 0; i <= m - 1; i++) mp[i] = 0;
    for (i = 1; i <= n; i++) mp[a[i]] = 1;
  }
  check();
}
