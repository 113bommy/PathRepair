#include <bits/stdc++.h>
int Kx[1000];
int Ky[1000];
int n, m, k;
struct wall {
  int R, x, y;
};
wall C[10000];
double hypot(double x, double y) { return sqrt(x * x + y * y); }
int G[2000][2000];
int P[2000];
int aa[1000];
int bb[1000];
void build_graph() {
  for (int i = 0; i < m; i++) {
    bool flag = true;
    int nn = 0;
    G[i][i] = 0;
    for (int j = i + 1; j < m; j++)
      if (hypot(C[i].x - C[j].x, C[i].y - C[j].y) < C[i].R + C[j].R) {
        nn++;
        G[i][j] = nn;
        flag = false;
      }
    P[i] = nn;
  }
  for (int j = 0; j < n; j++) {
    aa[j] = -1;
    for (int i = 0; i < m; i++)
      if (hypot(C[i].x - Kx[j], C[i].y - Ky[j]) < C[i].R) {
        aa[j] = i;
        break;
      }
  }
  for (int j = 0; j < n; j++) {
    bb[j] = -1;
    for (int i = 0; i < m; i++)
      if (hypot(C[i].x - Kx[j], C[i].y - Ky[j]) < C[i].R) {
        bb[j] = i;
        break;
      }
  }
}
int set[10000] = {0};
int path(int a, int b, int i) {
  a--;
  b--;
  int ai = aa[a];
  int bi = bb[b];
  if (ai == -1 && bi == -1) return 0;
  if (ai == -1) return P[bi] + 1;
  if (bi == -1) return P[ai] + 1;
  int min = 111111;
  int m = ai;
  if (bi > m) m = bi;
  for (int i = bi; i < m; i++) {
    if (G[ai][i] != -1 && G[bi][i] != -1)
      if (G[ai][i] + G[bi][i] < min) min = G[ai][i] + G[bi][i];
  }
  if (min == 111111) min = P[ai] + P[bi] + 2;
  return min;
}
int main() {
  memset(G, 0xFF, sizeof(G));
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%d%d", Kx + i, Ky + i);
  for (int i = 0; i < m; i++) scanf("%d%d%d", &C[i].R, &C[i].x, &C[i].y);
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++)
      if (C[i].R > C[j].R) {
        wall t;
        t = C[i];
        C[i] = C[j];
        C[j] = t;
      }
  build_graph();
  for (int i = 0; i < k; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", path(a, b, i));
  }
}
