#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
priority_queue<pair<int, int> > que;
int sum[MAXN], col[MAXN], del[MAXN];
int cnt[2], ans, n;
int white, black;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &col[i], &sum[i]), black += col[i];
  white += black;
  for (int i = 1; i <= n; ++i) que.push(make_pair(-sum[i], i));
  cnt[0] = cnt[1] = 1;
  while (!que.empty()) {
    if (white == 1 || black == 1) {
      int t = (black == 1);
      int &u = cnt[t];
      while (col[u] != t || del[u]) ++u;
      for (int v = cnt[t ^ 1]; v <= n; ++v)
        if (col[v] == (t ^ 1) && !del[v]) printf("%d %d %d\n", u, v, sum[v]);
      break;
    }
    int u = que.top().second, t = -que.top().first;
    que.pop();
    if (t != sum[u] || del[u]) continue;
    int &v = cnt[col[u] ^ 1];
    while (col[v] != (col[u] ^ 1) || del[v]) ++v;
    printf("%d %d %d\n", u, v, t);
    del[u] = true;
    if (col[u] == 0)
      --white;
    else
      --black;
    sum[u] -= t, sum[v] -= t;
    que.push(make_pair(-sum[v], v));
    if (++ans == n - 1) break;
  }
  return 0;
}
