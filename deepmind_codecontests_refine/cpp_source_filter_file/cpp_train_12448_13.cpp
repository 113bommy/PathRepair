#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000001;
int n, k, x, cnt[maxn];
bool vis[maxn];
vector<int> a;
bitset<maxn> dp;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n && scanf("%d", &x); i++) a.push_back(x - 1);
  int tot = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    int len = 0, cur = i;
    while (vis[cur] == 0) {
      len++;
      vis[cur] = 1;
      cur = a[cur];
    }
    tot += len / 2;
    cnt[len]++;
  }
  dp.set(0);
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) continue;
    for (int j = 0; (1 << j) <= cnt[i]; j++) {
      dp |= (dp << (i << j));
      cnt[i] -= (1 << j);
    }
    dp |= (dp << (i * cnt[i]));
  }
  printf("%d ", k + !dp[k]);
  if (k <= tot)
    printf("%d\n", 2 * k);
  else
    printf("%d\n", n, tot + k);
  return 0;
}
