#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int vis[MAXN], p[MAXN], maxn[MAXN];
int cnt = 0;
void prime(int n) {
  for (int i = 2; i <= n; i++) {
    if (vis[i] == 0) p[++cnt] = i;
    for (int j = 1; j <= cnt && i * p[j] < n; j++) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  prime(n);
  vis[1] = 0;
  int k = 0;
  for (int i = 2; i <= n; i++) {
    if (vis[i] == 1) {
      int temp = sqrt(i);
      for (int j = 2; j <= temp; j++) {
        if (i % j == 0) {
          maxn[++k] = i / j;
          break;
        }
      }
    }
  }
  sort(maxn + 1, maxn + 1 + k);
  int ans = 1;
  k = 0;
  for (int i = 2; i <= n; i++) {
    if (i <= cnt + 1)
      ans = 1;
    else
      ans = max(ans, maxn[++k]);
    printf("%d%c", ans, i == n ? '\n' : ' ');
  }
  return 0;
}
