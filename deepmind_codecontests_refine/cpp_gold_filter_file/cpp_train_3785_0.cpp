#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000007, mn = 125;
int n, m, lm, t, v, i, j, ans;
int s[mn];
int dfs(int r, bitset<mn> now) {
  if (r > lm) return 1;
  int res = dfs(r + 1, now);
  if (s[r] && !now[r]) {
    bitset<mn> next =
        now | (now >> r) | (now << r) | (now >> (m - r)) | (now << (m - r));
    res = (res + (long long)s[r] * dfs(r + 1, next)) % mo;
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &v);
    v = v % m;
    ++s[min(v, m - v)];
  }
  lm = (m + 1) / 2;
  while (s[lm] == 0 && lm) --lm;
  bitset<mn> now;
  now[0] = 1;
  ans = dfs(1, now);
  printf("%d\n", ans);
  return 0;
}
