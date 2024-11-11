#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;
int n;
char mp[N][N];
int mxd[N][N];
int pn[N];
bool used[N];
int mxatd[N], sum[N];
int cpucnt;
inline bool is_invalid(int fin) {
  for (int i = 1; i <= n; ++i) sum[i] = 0;
  for (int i = 1; i <= fin; ++i) ++sum[i];
  for (int i = 1; i <= n; ++i)
    if (!used[i]) ++sum[mxatd[i]];
  cpucnt += n;
  for (int i = 1; i <= n; ++i) {
    sum[i] += sum[i - 1];
    if (sum[i] > i) return true;
  }
  return false;
}
int *eat[N * N], efr[N * N], sze;
inline void edit(int &a, int b) {
  ++sze;
  eat[sze] = &a;
  efr[sze] = a;
  a = b;
}
inline void reste(int a) {
  while (sze > a) {
    *eat[sze] = efr[sze];
    --sze;
  }
}
bool dfs(int i) {
  if (i > n) return true;
  if (is_invalid(i - 1)) return false;
  for (int j = 1; j <= n; ++j)
    if (!used[j]) {
      int st = sze;
      for (int k = 1; k <= n; ++k)
        if (mxatd[k] > i + mxd[j][k]) edit(mxatd[k], i + mxd[j][k]);
      used[j] = true;
      pn[i] = j;
      if (dfs(i + 1)) return true;
      cpucnt += n;
      used[j] = false;
      reste(st);
      if (cpucnt > 10000000) return false;
    }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
  memset(mxd, 0x3f, sizeof(mxd));
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = 1; j <= n; ++j)
      if (mp[i][j] == '1') ++cnt;
    for (int j = 1; j <= n; ++j)
      if (mp[i][j] == '1')
        for (int k = j + 1; k <= n; ++k)
          if (mp[i][k] == '1') {
            mxd[j][k] = min(mxd[j][k], cnt - 1);
            mxd[k][j] = min(mxd[k][j], cnt - 1);
          }
  }
  for (int i = 1; i <= n; ++i) mxatd[i] = n;
  if (dfs(1)) {
    puts("YES");
    for (int i = 1; i <= n; ++i, putchar('\n'))
      for (int j = 1; j <= n; ++j) putchar(mp[i][pn[j]]);
  } else
    puts("NO");
  return 0;
}
