#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], cnt[N], ans, c[N], mx, nw, tot;
int ape[2 * N];
void add(int x, int y) {
  if (cnt[x] == nw) tot--;
  cnt[x] += y;
  if (cnt[x] == nw) tot++;
}
void work(int x) {
  memset(ape, -1, sizeof(ape));
  ape[n] = 0;
  for (register int i = (1); i <= (n); ++i) {
    if (a[i] == x)
      c[i] = 1;
    else if (a[i] == mx)
      c[i] = -1;
    else
      c[i] = 0;
    c[i] += c[i - 1];
    if (ape[c[i] + n] == -1)
      ape[c[i] + n] = i;
    else
      ans = max(ans, i - ape[c[i] + n]);
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (register int i = (1); i <= (n); ++i) cin >> a[i], cnt[a[i]]++;
  int lim = sqrt(n), l;
  for (register int i = (1); i <= (n); ++i)
    if (cnt[mx] < cnt[i]) mx = i;
  for (register int i = (1); i <= (n); ++i)
    if (cnt[i] > lim) work(i);
  for (register int j = (1); j <= (lim); ++j) {
    memset(cnt, 0, sizeof(cnt));
    l = 1;
    nw = j;
    tot = 0;
    for (register int i = (1); i <= (n); ++i) {
      add(a[i], 1);
      while (cnt[a[i]] > nw) add(a[l++], -1);
      if (tot >= 2) ans = max(ans, i - l + 1);
    }
  }
  cout << ans << '\n';
  return 0;
}
