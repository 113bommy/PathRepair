#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int val[1005], jl[1005], vis[1005];
int tot, head[1005], nx[4005], to[4005];
int read() {
  char aa = getchar();
  int pp = 1, kk = 0;
  while (aa < '0' || aa > '9') {
    if (aa == '-') pp = -1;
    aa = getchar();
  }
  while (aa >= '0' && aa <= '9') {
    kk = kk * 10 + aa - '0';
    aa = getchar();
  }
  return kk * pp;
}
void write(int z) {
  if (z < 0) {
    putchar('-');
    z = -z;
  }
  if (z >= 10) {
    write(z / 10);
  }
  putchar(z % 10 + '0');
}
void jia(int aa, int bb) {
  tot++;
  nx[tot] = head[aa];
  to[tot] = bb;
  head[aa] = tot;
  return;
}
bool cmp(int aa, int bb) { return val[aa] > val[bb]; }
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) val[i] = read(), jl[i] = i;
  for (int i = 1; i <= m; ++i) {
    int x = read(), y = read();
    jia(x, y);
    jia(y, x);
  }
  sort(jl + 1, jl + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    for (int j = head[jl[i]]; j; j = nx[j]) {
      int yy = to[j];
      if (vis[yy]) continue;
      ans += val[yy];
    }
    vis[jl[i]] = 1;
  }
  printf("%d", ans);
  return 0;
}
