#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
int k, n, a[maxn], f[maxn];
bool vis[maxn];
int main() {
  scanf("%d %d", &n, &k);
  int temp, cnt = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < k; i++) {
    scanf("%d", &temp);
    if (!vis[temp]) {
      a[++cnt] = temp;
      vis[temp] = 1;
    }
  }
  memset(f, -1, sizeof(f));
  queue<int> q;
  q.push(1000);
  f[1000] = 0;
  while (!q.empty()) {
    int from = q.front();
    q.pop();
    for (int i = 1; i <= cnt; i++) {
      int to = from + a[i] - n;
      if (to == 1000) {
        printf("%d\n", f[from]);
        return 0;
      }
      if (to >= 0 && to <= maxn && f[to] == -1) {
        f[to] = f[from] + 1;
        q.push(to);
      }
    }
  }
  printf("-1\n");
  return 0;
}
