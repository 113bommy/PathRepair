#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.2e7 + 10;
int pri[maxn << 1];
int tot;
bool vis[maxn];
void pre() {
  for (int i = 2; i < maxn; i++) {
    if (!vis[i]) {
      pri[tot++] = i;
    }
    for (int j = 0; j < tot; j++) {
      if (i * pri[j] >= maxn) break;
      vis[i * pri[j]] = true;
      if (i % pri[j] == 0) break;
    }
  }
}
bool check(int n) {
  for (int i = 0; i < tot && pri[i] * pri[i] <= n; i++) {
    if (n % pri[i] == 0) return true;
  }
  return false;
}
int main() {
  pre();
  int n;
  scanf("%d", &n);
  for (int i = 1; i < maxn; i++) {
    if (vis[i] && n + i < maxn && vis[n + i]) {
      printf("%d %d\n", n + i, i);
      return 0;
    } else if (vis[i] && check(n + i)) {
      printf("%d %d\n", n + i, i);
      return 0;
    }
  }
}
