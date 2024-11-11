#include <bits/stdc++.h>
using namespace std;
const int MaxN = 3000, MaxM = 3000 * 1000;
int n, K, all, a[MaxM + 5], b[MaxN + 5];
int pre[MaxM + 5], last[MaxN + 5], other[MaxM + 5];
bool vis[MaxN + 5];
pair<int, int> seq[MaxN + 5];
void Build(int x, int y) {
  pre[++all] = last[x];
  last[x] = all;
  other[all] = y;
}
void Init() {
  all = -1;
  memset(last, -1, sizeof(last));
  for (int i = 1; i <= K; i++) {
    int x;
    scanf("%d", &x);
    a[i] = x - n;
  }
  sort(a + 1, a + K + 1);
  a[0] = -(1 << 30);
  int tot = 0;
  for (int i = 1; i <= K; i++)
    if (a[i] != a[i - 1]) b[++tot] = a[i];
  K = tot;
  for (int i = 1; i <= K; i++) a[i] = b[i];
  for (int i = 0; i <= 2002; i++) {
    for (int j = 1; j <= K; j++) {
      if (i + a[j] < 0) continue;
      if (i + a[j] > 2002) continue;
      Build(i, i + a[j]);
    }
  }
}
void Solve() {
  memset(vis, 0, sizeof(vis));
  int head = 1, tail = 0, s = 1001;
  seq[++tail] = make_pair(s, 0);
  vis[s] = true;
  int ans = 1 << 30;
  while (head <= tail) {
    pair<int, int> now = seq[head];
    int ed = last[now.first], dr;
    while (ed != -1) {
      dr = other[ed];
      if (!vis[dr]) {
        vis[dr] = true;
        seq[++tail] = make_pair(dr, now.second + 1);
      } else if (dr == s)
        ans = min(ans, now.second + 1);
      ed = pre[ed];
    }
    head++;
  }
  if (ans == 1 << 30)
    printf("-1\n");
  else
    printf("%d\n", ans);
}
int main() {
  while (~scanf("%d%d", &n, &K)) {
    Init();
    Solve();
  }
  return 0;
}
