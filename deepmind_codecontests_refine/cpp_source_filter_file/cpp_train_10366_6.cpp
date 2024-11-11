#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int MAXN = 1e3 + 7;
int flag;
int n;
int a[MAXN], mark[MAXN], ans[MAXN];
void ask() {
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (mark[i]) cnt++;
  if (cnt == n || cnt == 0) return;
  printf("%d\n", cnt);
  for (int i = 1; i <= n; i++)
    if (mark[i]) printf("%d ", i);
  fflush(stdout);
  for (int i = 1; i <= n; i++)
    if (mark[i])
      scanf("%d", &a[i]);
    else
      scanf("%*d");
  printf("%d\n", n - cnt);
  for (int i = 1; i <= n; i++)
    if (!mark[i]) printf("%d ", i);
  fflush(stdout);
  for (int i = 1; i <= n; i++)
    if (!mark[i])
      scanf("%d", &a[i]);
    else
      scanf("%*d");
}
void bfs() {
  queue<pair<int, int> > q[2];
  q[0].push(pair<int, int>(1, n));
  for (int i = 0; !q[i & 1].empty(); i++) {
    memset(mark, 0, sizeof(mark));
    while (!q[i & 1].empty()) {
      pair<int, int> fr = q[i & 1].front();
      q[i & 1].pop();
      int l = fr.first, r = fr.second;
      if (l >= r) continue;
      int mid = l + r >> 1;
      for (int j = l; j <= mid; j++) mark[j] = 1;
      q[(i + 1) & 1].push(pair<int, int>(l, mid));
      q[(i + 1) & 1].push(pair<int, int>(mid + 1, r));
    }
    ask();
    for (int i = 1; i <= n; i++) ans[i] = min(ans[i], a[i]);
  }
}
int main() {
  scanf("%d", &n);
  memset(ans, 0x3f, sizeof(ans));
  bfs();
  printf("-1\n");
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
