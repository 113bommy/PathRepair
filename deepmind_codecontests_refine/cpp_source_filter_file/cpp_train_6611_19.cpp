#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = maxn * 4 + 10;
const int inf = 1e9;
const long long mod = 1e9 + 7;
int getint() {
  char c;
  while ((c = getchar()) && !(c >= '0' && c <= '9') && c != '-')
    ;
  int ret = c - '0', sgn = 0;
  if (c == '-') sgn = 1, ret = 0;
  while ((c = getchar()) && c >= '0' && c <= '9') ret = ret * 10 + c - '0';
  if (sgn) ret = -ret;
  return ret;
}
int f[maxn], b[maxn], vis[maxn], cnt[maxn];
int ans[maxn];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    int i;
    for (i = 1; i <= n; i++) f[i] = getint();
    for (i = 1; i <= m; i++) b[i] = getint();
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) vis[f[i]] = i, cnt[f[i]]++;
    int flag = 1;
    for (int i = 1; i <= m; i++) {
      if (cnt[f[i]] > 1) {
        flag = 0;
      }
      if (vis[b[i]] > 0)
        ans[i] = vis[b[i]];
      else {
        flag = -1;
        break;
      }
    }
    if (flag == 1) {
      puts("Possible");
      for (int i = 1; i <= m; i++) cout << ans[i] << " ";
      cout << endl;
    } else if (flag == -1) {
      puts("Impossible");
    } else
      puts("Ambiguity");
  }
  return 0;
}
