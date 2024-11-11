#include <bits/stdc++.h>
using namespace std;
int n, w, h, cx = 0, cy = 0, a[200010], f[200010], pos[200010], g[200010];
struct point {
  int p, t, id, x;
  inline bool operator<(const point &b) const { return p < b.p; }
} px[200010], py[200010];
inline bool cmp(point a, point b) {
  return ((a.p - a.t < b.p - b.t) || (a.p - a.t == b.p - b.t && a.p < b.p));
}
template <class Aqua>
inline void read(Aqua &s) {
  s = 0;
  Aqua f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) s = s * 10 + c - '0', c = getchar();
  s *= f;
}
int main() {
  read(n);
  read(w), read(h);
  for (int i = 1; i <= n; i++) {
    read(g[i]);
    if (g[i] == 1)
      read(px[++cx].p), read(px[cx].t),
          px[cx].id = i, px[cx].x = px[cx].p - px[cx].t, pos[i] = px[cx].p;
    else
      read(py[++cy].p), read(py[cy].t),
          py[cy].id = i, py[cy].x = py[cy].p - py[cy].t, pos[i] = py[cy].p;
  }
  sort(px + 1, px + cx + 1, cmp);
  sort(py + 1, py + cy + 1, cmp);
  int j = 1, las, l, cnt, o, s;
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= cx; i++) {
    las = i;
    while (i < cx && px[i].x == px[i + 1].x) i++;
    while (j <= cy && py[j].x < px[i].x) j++;
    if (j > cy) break;
    if (py[j].x == px[i].x) {
      l = j;
      while (j < cy && py[j + 1].x == px[i].x) j++;
      cnt = 0;
      for (int k = j; k >= l; k--) a[++cnt] = py[k].id;
      o = cnt;
      for (int k = las; k <= i; k++) a[++cnt] = px[k].id;
      s = cnt;
      for (int k = j; k >= l; k--) a[++cnt] = py[k].id;
      for (int k = las; k <= i; k++) a[++cnt] = px[k].id;
      for (int k = 1; k <= s; k++) f[a[s - o + k]] = a[k];
      j++;
    }
  }
  for (int i = 1; i <= n; i++)
    if (g[f[i]] == 1)
      printf("%d %d\n", pos[f[i]], h);
    else
      printf("%d %d\n", w, pos[f[i]]);
  return 0;
}
