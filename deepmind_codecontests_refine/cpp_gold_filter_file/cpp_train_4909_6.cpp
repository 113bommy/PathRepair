#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N], l, r;
bitset<300000001> vis;
int p[20000005];
int main() {
  cin >> l >> r;
  int tot = 0, cnt = 0, ans = 0;
  for (int i = 1; i * i <= r; ++i) a[i] = i * i, ++cnt;
  vis[1] = 1;
  for (int i = 2; i <= r; ++i) {
    if (!vis[i]) p[++tot] = i;
    for (int j = 1; i * p[j] <= r && j <= tot; ++j) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
  for (int i = 1; i <= cnt; ++i) {
    for (int j = i; j <= cnt; ++j) {
      if (a[i] + a[j] >= l && a[i] + a[j] <= r && !vis[a[i] + a[j]]) ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}
