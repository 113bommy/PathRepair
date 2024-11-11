#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n, m;
int f[N][205];
int tot;
int l[N];
int ans;
struct lq {
  int nxt;
  int to;
} node[N];
int head[N];
void add(int u, int v) {
  node[++tot].nxt = head[u];
  node[tot].to = v;
  head[u] = tot;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) head[i] = 0;
    tot = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      add(a[i], i);
      for (int j = 1; j <= 200; j++) f[i][j] = f[i - 1][j];
      f[i][a[i]]++;
    }
    int ans = 1;
    for (int k = 1; k <= 200; k++) {
      int cnt = 0;
      for (int i = head[k]; i; i = node[i].nxt) {
        int v = node[i].to;
        l[++cnt] = v;
      }
      int p = cnt / 2;
      for (int i = 1; i <= p; i++) {
        int maxn = 0;
        for (int j = 1; j <= 200; j++)
          maxn = max(maxn, f[l[i] - 1][j] - f[l[cnt - i + 1]][j]);
        ans = max(ans, maxn + i * 2);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
