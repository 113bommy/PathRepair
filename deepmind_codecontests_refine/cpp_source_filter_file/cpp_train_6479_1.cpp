#include <bits/stdc++.h>
using namespace std;
const int SIZ = 100100;
const int INF = (1 << 29);
const double EPS = 1e-11;
int N, caseno = 0;
char st[200];
int mem[102][204][2][52];
int f(int i, int dist, int dir, int change) {
  if (i == N) return change == 0 ? abs(N - dist) : 0;
  int &ret = mem[i][dist][dir][change];
  if (ret != -1) return ret;
  int res = 0, ndist, ndir;
  if (change > 0) {
    ndist = dist;
    ndir = dir;
    if (st[i] == 'T') {
      if (dir == 0)
        ndist++;
      else
        ndist--;
    } else
      ndir ^= 1;
    res = f(i + 1, ndist, ndir, change - 1);
  }
  ndist = dist;
  ndir = dir;
  if (st[i] == 'F') {
    if (dir == 0)
      ndist++;
    else
      ndist--;
  } else
    ndir ^= 1;
  res = max(res, f(i + 1, ndist, ndir, change));
  return ret = res;
}
int main() {
  int cases, i, j, res;
  memset(mem, -1, sizeof(mem));
  scanf("%s", st);
  scanf("%d", &j);
  N = strlen(st);
  int lim;
  if (j % 2 == 0)
    lim = 0;
  else
    lim = 1;
  res = 0;
  for (i = j; i >= lim; i--) {
    res = max(res, max(f(0, N, 0, j), f(0, N, 1, j)));
  }
  printf("%d\n", res);
  return 0;
}
