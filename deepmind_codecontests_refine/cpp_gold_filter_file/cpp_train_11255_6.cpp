#include <bits/stdc++.h>
using namespace std;
int const N = 1000;
char an[N][N + 1];
int x[N], n, mx[N];
bool vis1[N], vis2[N];
int gtmx(int v) {
  if (vis1[v]) return mx[v] = max(v, mx[v]);
  vis1[v] = true;
  return mx[v] = max(v, gtmx(x[v]));
}
int H, bait, bg;
void st(int i, int j) {
  if (i < j)
    an[H][i] = '/', an[H][j] = '/';
  else
    an[H][i] = '\\', an[H][j] = '\\';
}
void go(int v) {
  vis2[v] = true;
  int u = x[v];
  if (vis2[u]) {
    if (u == bait) return;
    an[H][v] = '/';
    an[H][bait] = '/';
    an[bg][bait] = '\\';
    ++H;
    return;
  }
  st(v, u);
  ++H;
  go(u);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) scanf("%d", x + i);
  for (int i = 0; i < (int)(n); ++i) --x[i];
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(n); ++j) an[i][j] = '.';
  bait = n - 1;
  while (bait >= 0 && x[bait] == bait) --bait;
  if (bait == -1) {
    printf("%d\n", n);
    for (int i = 0; i < (int)(n); ++i) printf("%s\n", an[i]);
    return 0;
  }
  for (int i = bait; i >= 0; --i)
    if (i != x[i]) {
      int t = gtmx(i);
      if (t == bait || vis2[i]) continue;
      bg = H;
      go(t);
    }
  go(bait);
  printf("%d\n", n - 1);
  for (int i = 0; i < (int)(n); ++i) printf("%s\n", an[i]);
}
