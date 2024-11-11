#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, maxn = 1300005;
int p[maxn], res;
bool vis[maxn];
void get_prime(int n = 1300000) {
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) p[res++] = i;
    for (int j = 0; j < res && i * p[j] <= n; j++) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
}
int n, x, a[maxn], mark[maxn];
int main() {
  get_prime();
  while (~scanf("%d%d", &n, &x)) {
    memset(mark, 0, sizeof(mark));
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] == 1) flag = 1;
    }
    if (x == 2)
      printf("0\n");
    else if (flag)
      printf("1\n");
    else if (x >= 1300000)
      printf("-1\n");
    else {
      for (int i = 1; i <= n; i++)
        if (a[i] < x) mark[a[i]] = 1;
      int ans = 0;
      for (int i = 0; i < res && p[i] < x; i++)
        if (!mark[p[i]]) {
          ans = -1;
          break;
        } else
          ans++;
      printf("%d\n", ans);
    }
  }
  return 0;
}
