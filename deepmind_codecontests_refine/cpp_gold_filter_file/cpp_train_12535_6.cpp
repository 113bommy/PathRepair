#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<long long, int> > q;
struct node {
  int l;
  int r;
  int to;
  int nx;
} e[200000];
int cabeza[100000];
int ecnt;
int respuesta[100000];
void agregarvertices(int x, int y, int l, int r) {
  e[ecnt].l = l;
  e[ecnt].r = r;
  e[ecnt].to = y;
  e[ecnt].nx = cabeza[x];
  cabeza[x] = ecnt++;
}
long long d1[100000], d2[100000];
int n, m, k, s1, s2, f;
void gao(int bo) {
  while (!q.empty()) q.pop();
  memset(respuesta, -1, sizeof(respuesta));
  for (int i = 0; i <= n; ++i) d1[i] = d2[i] = 1e15;
  d1[s1] = d2[s2] = 0;
  q.push(make_pair(0, s1));
  q.push(make_pair(0, s2));
  while (!q.empty()) {
    pair<long long, int> ee = q.top();
    q.pop();
    long long va = -ee.first;
    int id = ee.second;
    if (va > d1[id] && va > d2[id]) continue;
    bool ok;
    if (bo == 1) {
      if (d1[id] < d2[id])
        ok = true;
      else
        ok = false;
    } else {
      if (d1[id] <= d2[id])
        ok = true;
      else
        ok = false;
    }
    for (int i = cabeza[id]; i != -1; i = e[i].nx) {
      int u = e[i].to;
      long long agregar;
      if (ok)
        agregar = e[i].l;
      else
        agregar = e[i].r;
      respuesta[i] = agregar;
      if (d1[u] > d1[id] + agregar) {
        d1[u] = d1[id] + agregar;
        q.push(make_pair(-d1[u], u));
      }
      if (d2[u] > d2[id] + agregar) {
        d2[u] = d2[id] + agregar;
        q.push(make_pair(-d2[u], u));
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%d%d%d", &s1, &s2, &f);
  memset(cabeza, -1, sizeof(cabeza));
  ecnt = 0;
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    agregarvertices(x, y, z, z);
  }
  for (int i = 0; i < k; ++i) {
    int x, y, l, r;
    scanf("%d%d%d%d", &x, &y, &l, &r);
    agregarvertices(x, y, l, r);
  }
  gao(1);
  if (d1[f] < d2[f]) {
    printf("WIN\n");
    for (int i = m; i < m + k; ++i) {
      if (respuesta[i] == -1) respuesta[i] = e[i].l;
      printf("%d", respuesta[i]);
      if (i == m + k - 1)
        puts("");
      else
        printf(" ");
    }
    return 0;
  }
  gao(0);
  if (d1[f] == d2[f]) {
    printf("DRAW\n");
    for (int i = m; i < m + k; ++i) {
      if (respuesta[i] == -1) respuesta[i] = e[i].l;
      printf("%d", respuesta[i]);
      if (i == m + k - 1)
        puts("");
      else
        printf(" ");
    }
    return 0;
  }
  printf("LOSE\n");
  return 0;
}
