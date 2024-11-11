#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar(), bz = 0;
  for (; c < 48 || c > 57; c = getchar())
    if (!(c ^ 45)) bz = 1;
  for (; c >= 48 && c <= 57; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  bz ? x = -x : x;
}
struct edge {
  int to, id, nxt;
} e[2000005];
int n, m, et, head[12505], id[12505], nx[12505];
int fr[1000005], tw[1000005], we[1000005], wp[12505], vl[12505];
char vs[1012505];
inline void adde(int x, int y, int id) {
  e[++et] = (edge){y, id, head[x]}, head[x] = et;
}
int main() {
  read(n), read(m);
  for (int i = 1; i <= m; i++) read(fr[i]), read(tw[i]);
  for (int i = 1; i <= m; i++)
    adde(fr[i], tw[i], i), adde(tw[i], fr[i], i), we[i] = 1, vl[fr[i]]++,
                                                  vl[tw[i]]++;
  for (int x = 1; x <= n; x++) {
    int tt = 0;
    for (int i = head[x]; i; i = e[i].nxt)
      if (e[i].to < x) id[++tt] = e[i].id, nx[tt] = e[i].to;
    for (int i = 1; i <= tt; i++)
      if (wp[nx[i]] == 0) wp[nx[i]]++, we[id[i]]--, vl[x]--;
    for (int i = 1; i <= tt; i++) vs[vl[nx[i]]] = 1;
    int nw = 0;
    while (vs[vl[x]]) nw++, vl[x]++, wp[nx[nw]]--, we[id[nw]]++;
    for (int i = 1; i <= tt; i++) vs[vl[nx[i]]] = 0;
  }
  int cn = 0;
  for (int i = 1; i <= n; i++) cn += wp[i];
  printf("%d\n", cn);
  for (int i = 1; i <= n; i++)
    if (wp[i]) printf("%d ", i);
  putchar('\n');
  for (int i = 1; i <= m; i++) printf("%d %d %d\n", fr[i], tw[i], we[i]);
  return 0;
}
