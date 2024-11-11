#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
}
int n, las[1000011], cnt, pos, ans = -1, f[1000011], moL[1000011];
map<int, int> Mp[1000011];
void SoL(int x) {
  if (las[x]) SoL(las[x]);
  moL[++cnt] = x;
}
int main() {
  read(n);
  int w, p, l, r;
  for (register int i = 1; i <= n; ++i) {
    read(w), read(p), read(l), read(r);
    int now = l + r + p;
    if (!l)
      f[i] = w;
    else
      f[i] = -2e9;
    if (Mp[now].find(l) != Mp[now].end()) {
      f[i] = f[Mp[now][l]] + w, las[i] = Mp[now][l];
    }
    if (Mp[now].find(l + p) != Mp[now].end()) {
      if (f[Mp[now][l + p]] < f[i]) Mp[now][l + p] = i;
    } else if (~f[i])
      Mp[now][l + p] = i;
    if ((!r) && f[i] > ans) pos = i, ans = f[i];
  }
  if (!pos) {
    puts("0");
    return 0;
  }
  cnt = 0, SoL(pos);
  printf("%d\n%d\n", ans, cnt);
  for (int i = 1; i <= cnt; ++i) printf("%d ", moL[i]);
}
