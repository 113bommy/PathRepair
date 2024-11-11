#include <bits/stdc++.h>
int m, n = 0, num[(20)];
long long f[(20)][(20)], cnt[(20)], ans = 0;
void CountBit(int m);
long long dfs(int bit, int value, bool limit);
void solve(int p, int s, int q, long long tot);
int main() {
  scanf("%d", &m);
  CountBit(m);
  memset(f, 0xff, sizeof(f));
  for (int i = 0; i <= n; i++) cnt[i] = dfs(n, i, true);
  cnt[0]--;
  for (int i = 1; i <= n; i++) solve(0, 1, i, cnt[i]);
  printf(
      "%I64d"
      "\n",
      ans);
  return 0;
}
void solve(int p, int s, int q, long long tot) {
  if (p >= q) return;
  if (s == 7) {
    if (q > p) ans += tot, ans %= (1000000007LL);
    return;
  }
  for (int i = 0; i < q; i++) {
    if (cnt[i]) {
      cnt[i]--;
      solve(p + i, s + 1, q, tot * (cnt[i] + 1) % (1000000007LL));
      cnt[i]++;
    }
  }
}
long long dfs(int bit, int value, bool limit) {
  long long ret = 0, &save = f[bit][value];
  if (!bit) {
    if (!value) return save = 1;
    return 0;
  }
  if (!limit && (save)) return save;
  int border = limit ? num[bit] : 9;
  for (int i = 0; i <= border; i++)
    ret += dfs(bit - 1, value - (i == 4 || i == 7), limit && i == border);
  if (!limit) save = ret;
  return ret;
}
void CountBit(int m) {
  while (m) num[++n] = m % 10, m /= 10;
}
