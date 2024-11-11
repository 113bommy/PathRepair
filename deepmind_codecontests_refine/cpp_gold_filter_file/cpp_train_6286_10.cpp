#include <bits/stdc++.h>
using namespace std;
const int MXM = 10000 + 10;
const int MXN = 500 + 10;
short int e[MXM][2];
short int sz[MXN], par[MXN];
short int bs[MXN], bp[MXN];
short int d[MXM][MXM];
int n, m;
int ci, cj;
int root(int x);
int merg(int x);
inline void to_b();
inline void b_back();
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d%d", &e[i][0], &e[i][1]);
  for (int i = 0; i < n; i++) {
    sz[i] = 1;
    par[i] = -1;
  }
  ci = n;
  for (int i = 0; i < m; i++) {
    cj = ci;
    to_b();
    for (int j = m - 1; j >= i; j--) {
      d[i][j] = cj;
      if (merg(j)) cj--;
    }
    b_back();
    if (merg(i)) ci--;
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int s, e;
    scanf("%d%d", &s, &e);
    printf("%d\n", d[s - 1][e - 1]);
  }
  return 0;
}
int root(int x) {
  if (par[x] == -1)
    return x;
  else
    return par[x] = root(par[x]);
}
int merg(int x) {
  int p1 = root(e[x][0]);
  int p2 = root(e[x][1]);
  if (p1 == p2) return 0;
  if (sz[p1] < sz[p2]) swap(p1, p2);
  par[p2] = p1;
  sz[p1] += sz[p2];
  return 1;
}
inline void to_b() {
  for (int i = 0; i < MXN; i++) {
    bs[i] = sz[i];
    bp[i] = par[i];
  }
}
inline void b_back() {
  for (int i = 0; i < MXN; i++) {
    sz[i] = bs[i];
    par[i] = bp[i];
  }
}
