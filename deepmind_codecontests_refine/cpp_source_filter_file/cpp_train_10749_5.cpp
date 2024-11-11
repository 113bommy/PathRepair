#include <bits/stdc++.h>
using namespace std;
int t, n;
char a[100010], b[100010];
int mapp[25][25], mask[25];
int f[1 << 20], g[1 << 20];
bool u[20];
void print_bits(const int b) {
  for (int i = 0; i < 20; i++) printf("%d", !!((1 << i) & b));
}
void dfs(const int x) {
  if (u[x]) return;
  u[x] = true;
  for (int i = 0; i < 20; i++)
    if (mapp[x][i] || mapp[i][x]) dfs(i);
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %s %s", &n, a, b);
    memset(mapp, 0, sizeof(mapp));
    memset(mask, 0, sizeof(mask));
    memset(u, 0, sizeof(u));
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) continue;
      mapp[a[i] - 'a'][b[i] - 'a'] = 1;
      mask[a[i] - 'a'] |= 1 << (b[i] - 'a');
    }
    int ccnt = 0;
    for (int i = 0; i < 20; i++)
      if (!u[i]) {
        dfs(i);
        ccnt++;
      }
    for (int i = 1; i < (1 << 20); i++) {
      f[i] = 0x3FFFFFFF;
      for (int j = 0; j < 20; j++) {
        if (!((1 << j) & i)) continue;
        int u = i ^ (1 << j);
        int c = 1;
        if (g[u] & (1 << j)) c++;
        f[i] = min(f[i], f[u] + c);
        g[i] = (g[u] | mask[j]) & (~(1 << j));
      }
      if ((i & (-i)) == i) f[i] = 0;
    }
    printf("%d\n", f[(1 << 20) - 1] - ccnt);
  }
  return 0;
}
