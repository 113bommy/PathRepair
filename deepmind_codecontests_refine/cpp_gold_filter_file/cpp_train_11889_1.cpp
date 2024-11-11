#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 10;
int f[Maxn], dis[Maxn];
int find(int x) {
  if (x != f[x]) {
    int last = f[x];
    f[x] = find(f[x]);
    dis[x] += dis[last];
  }
  return f[x];
}
bool vis[Maxn];
int value[Maxn];
int main() {
  int n;
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int a;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a);
      f[i] = a;
      vis[i] = false;
    }
    for (int i = 1; i <= n; i++) {
      int ans = 1;
      if (vis[i]) {
        if (i != n)
          printf("%d ", value[i]);
        else
          printf("%d\n", value[i]);
      } else if (!vis[i]) {
        int j = f[i];
        while (i != j) {
          j = f[j];
          ans++;
          vis[j] = true;
        }
        j = f[i];
        while (i != j) {
          j = f[j];
          value[j] = ans;
        }
        if (i != n)
          printf("%d ", ans);
        else
          printf("%d\n", ans);
      }
    }
  }
  return 0;
}
