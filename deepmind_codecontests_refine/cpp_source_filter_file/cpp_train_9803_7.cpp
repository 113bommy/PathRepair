#include <bits/stdc++.h>
const int N = 1e5 + 5;
int main() {
  bool vis[N];
  int ans[N], n, cnt = 0;
  scanf("%d", &n);
  for (int i = 2; i * i <= n; ++i) {
    if (!vis[i]) {
      ans[i] = ++cnt;
      for (int j = i * i; j <= n; j += i) ans[j] = cnt, vis[j] = true;
    }
  }
  for (int i = 2; i <= n; ++i) printf("%d ", ans[i] ? ans[i] : ++cnt);
}
