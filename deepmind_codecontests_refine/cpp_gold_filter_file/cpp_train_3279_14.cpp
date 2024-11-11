#include <bits/stdc++.h>
using namespace std;
const int MN = 100005, inf = 1000000005, mod = 1000000007;
const long long INF = 1000000000000000005LL;
int per[MN], used[MN];
vector<int> cyc[MN];
void daj(int x, int kolor) {
  while (!used[x]) {
    cyc[kolor].push_back(x);
    used[x] = 1;
    x = per[x];
  }
}
int main() {
  int n, ile = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &per[i]);
  for (int i = 1; i <= n; ++i)
    if (!used[i]) daj(i, ++ile);
  int mini = inf, idx = -1, par = 1;
  for (int i = 1; i <= ile; ++i) {
    int cs = cyc[i].size();
    if (cs < mini) {
      mini = cs;
      idx = i;
    }
    if (cs & 1) par = 0;
  }
  if (mini == 1) {
    puts("YES");
    for (int i = 1; i <= n; ++i)
      if (i != cyc[idx][0]) printf("%d %d\n", i, cyc[idx][0]);
    return 0;
  }
  if (mini > 2 || !par) {
    puts("NO");
    return 0;
  }
  puts("YES");
  printf("%d %d\n", cyc[idx][0], cyc[idx][1]);
  for (int i = 1; i <= ile; ++i)
    if (i != idx) {
      int cs = cyc[i].size();
      for (int j = 0; j < cs; ++j)
        printf("%d %d\n", cyc[i][j], cyc[idx][(j & 1)]);
    }
}
