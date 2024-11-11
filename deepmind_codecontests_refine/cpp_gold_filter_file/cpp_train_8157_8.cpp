#include <bits/stdc++.h>
using namespace std;
const int MN = 105;
const int MM = 10005;
int n, m;
int con[MN][MN], dg[MN];
int s[MM], sn;
int id1 = -1, id2 = -1;
int p[MM], pn, st;
bool Euler_cir() {
  int u, v;
  sn = pn = 0;
  if (!m) return 1;
  int sum = 0;
  for (u = 0; u < n; u++) {
    dg[u] = 0;
    for (v = 0; v < n; v++) dg[u] += con[u][v];
    sum += (dg[u] & 1);
  }
  if (sum != 0 && sum != 2) return 0;
  if (sum == 2) {
    for (u = 0; u < n; u++) {
      if (dg[u] & 1)
        if (id1 == -1)
          id1 = u;
        else
          id2 = u;
    }
    dg[id1]++, dg[id2]++;
    con[id1][id2]++, con[id2][id1]++;
    m++;
    st = id1;
  }
  for (u = 0; u < n; u++) {
    if (dg[u]) break;
  }
  s[++sn] = u;
  while (sn) {
    u = s[sn];
    for (v = 0; v < n; v++) {
      if (con[u][v]) break;
    }
    if (v < n) {
      con[u][v]--, con[v][u]--;
      s[++sn] = v;
    } else {
      p[pn++] = u;
      sn--;
    }
  }
  pn--;
  return pn == m;
}
vector<int> edge[100];
bool chk[MN];
int pq[MN];
int main() {
  int hbi;
  st = 0;
  n = 7;
  scanf("%d", &m);
  hbi = m;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    pq[i] = u * 10 + v;
    con[u][v]++;
    con[v][u]++;
  }
  if (!Euler_cir()) return puts("No solution"), 0;
  int now = 0;
  for (int i = 0; i < pn; i++)
    if ((p[i] == id1 && p[i + 1 < pn ? i + 1 : 0] == id2) ||
        (p[i] == id2 && p[i + 1 < pn ? i + 1 : 0] == id1)) {
      now = i + 1;
      break;
    }
  if (now == pn) now = 0;
  for (int i = 0; i < hbi; i++) {
    if (now == pn) now = 0;
    int nxt = now + 1;
    if (nxt == pn + 1) nxt = 0;
    int id = -100;
    for (int j = 0; j < hbi; j++) {
      if (chk[j]) continue;
      if ((p[now] == pq[j] / 10 && p[nxt] == pq[j] % 10)) {
        printf("%d +\n", j + 1);
        chk[j] = 1;
        break;
      }
      if ((p[nxt] == pq[j] / 10 && p[now] == pq[j] % 10)) {
        printf("%d -\n", j + 1);
        chk[j] = 1;
        break;
      }
    }
    now++;
  }
  return 0;
}
