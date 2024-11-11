#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 50;
int n, m;
int a[maxn][maxn];
int b[maxn][maxn];
int t[maxn];
int mark[maxn][maxn];
bool check() {
  memset(mark, 0, sizeof mark);
  for (int i = 0, _n = (int)(n); i < _n; i++) {
    for (int j = 0, _n = (int)(t[i]); j < _n; j++)
      for (int k = (int)(j + 1), _n = (int)(t[i]); k < _n; k++) {
        if (mark[b[i][j]][b[i][k]]) return true;
        mark[b[i][j]][b[i][k]] = 1;
      }
  }
  return false;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0, _n = (int)(n); i < _n; i++)
    for (int j = 0, _n = (int)(n); j < _n; j++) scanf("%d", &a[i][j]);
  int lo = 0, hi = 1e9 + 5;
  while (hi - lo > 1) {
    int md = (lo + hi) / 2;
    for (int i = 0, _n = (int)(n); i < _n; i++) {
      t[i] = 0;
      for (int j = 0, _n = (int)(m); j < _n; j++)
        if (a[i][j] >= md) b[i][t[i]++] = j;
    }
    if (check())
      lo = md;
    else
      hi = md;
  }
  printf("%d\n", lo);
  {
    int _;
    cin >> _;
    return 0;
  }
}
