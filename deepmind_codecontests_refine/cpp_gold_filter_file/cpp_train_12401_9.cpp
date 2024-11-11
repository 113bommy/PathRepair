#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, c, a[500005], pre[500005], suf[500005], ans;
vector<int> G[500005];
int main() {
  n = read();
  c = read();
  for (int i = 1; i <= n; i++) a[i] = read(), G[a[i]].push_back(i);
  for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (a[i] == c);
  for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + (a[i] == c);
  for (int i = 1; i <= 500000; i++) {
    if (!G[i].size()) continue;
    int siz = G[i].size(), pos = 0, maxn = pre[G[i][0] - 1];
    ans = max(ans, 1 + maxn + suf[G[i][0] + 1]);
    for (int j = 1; j < siz; j++) {
      if ((j - pos + 1) + maxn >= 1 + pre[G[i][j] - 1])
        ans = max(ans, (j - pos + 1) + maxn + suf[G[i][j] + 1]);
      else
        pos = j, maxn = pre[G[i][j] - 1],
        ans = max(ans, 1 + pre[G[i][j] - 1] + suf[G[i][j] + 1]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
