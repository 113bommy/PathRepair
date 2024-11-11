#include <bits/stdc++.h>
int n, d, sum, node, num[5001], now, son[5001], fa[5001], cnt, lst, fi[5001];
inline int min(int a, int b) { return a < b ? a : b; }
inline void solve() {
  memset(son, 0, sizeof(son));
  memset(fa, 0, sizeof(fa));
  memset(fi, 0x3f, sizeof(fi));
  scanf("%d %d", &n, &d);
  node = 0;
  sum = 0;
  for (int i = 0; i <= 31; i++) {
    if ((n - node) <= (1 << i)) {
      sum += (n - node) * i;
      break;
    }
    node += (1 << i);
    sum += (i * (1 << i));
  }
  if (sum > d) {
    puts("NO");
    return;
  }
  if (d > ((n * (n - 1)) >> 1)) {
    puts("NO");
    return;
  }
  sum = 0;
  for (int i = 0; i <= n - 1; i++) num[i] = 1, sum += i;
  now = 1;
  for (int i = n - 1; i >= 0; i--) {
    if ((sum - (i - now)) <= d) {
      num[i - (sum - d)]++;
      num[i]--;
      break;
    }
    num[i]--;
    num[now]++;
    sum -= (i - now);
    if (num[now] == (1 << now)) now++;
  }
  cnt = 1;
  lst = 1;
  for (int i = 1; i <= n - 1; i++) {
    if (!num[i]) break;
    for (int j = 1; j <= num[i]; j++) {
      son[lst]++;
      fa[++cnt] = lst;
      fi[i] = min(fi[i], cnt);
      if (son[lst] == 2) lst++;
    }
    lst = fi[i];
  }
  puts("YES");
  for (int i = 2; i <= n; i++) printf("%d ", fa[i]);
  puts("");
}
int main() {
  int TEST;
  scanf("%d", &TEST);
  while (TEST--) solve();
}
