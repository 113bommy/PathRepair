#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20 | 1;
int flag[N], a[N], b[N], n, m, x, y, id[N], cnt, in[N], out[N];
vector<int> v[N], g[N];
void dfs1(int x) {
  flag[x] = 1;
  if (!v[x].size()) id[x] = ++cnt;
  for (int i : v[x]) {
    in[i]--;
    if (!in[i]) dfs1(i);
  }
}
void dfs2(int x) {
  flag[x] = 1;
  if (id[x]) a[x] = 1 << (id[x] - 1);
  for (int i : g[x]) {
    out[i]--;
    a[i] |= a[x];
    if (!out[i]) dfs2(i);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    g[y].push_back(x);
    in[y]++;
    out[x]++;
  }
  for (int i = 1; i <= n; i++)
    if (!in[i] && !flag[i]) dfs1(i);
  memset(flag, 0, sizeof flag);
  for (int i = 1; i <= n; i++)
    if (!out[i] && !flag[i]) dfs2(i);
  cnt = 0;
  for (int i = 1; i <= n; i++)
    if (!g[i].size()) b[cnt++] = a[i];
  for (int i = 0; i < 1 << cnt; i++) {
    int s = 0, num1 = 0, num2 = 0;
    for (int j = 0; j < cnt; j++)
      if ((1 << j) & i) s |= b[j];
    for (int j = 0; j < cnt; j++)
      if ((1 << j) & i) num1++;
    for (int j = 0; j < cnt; j++)
      if ((1 << j) & s) num2++;
    if (num2 < num1) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
}
