#include <bits/stdc++.h>
using namespace std;
const int MEGA_CONST = 3;
int n, m;
int v[MEGA_CONST];
int so1() { return 1; }
int so2() {
  int w[333][333];
  memset(w, 0, sizeof(w));
  for (int i = 0; i <= v[0]; ++i)
    for (int j = 0; j <= v[1]; ++j) {
      int &r = w[i][j];
      r = -1;
      for (int x = 1; x <= i; ++x) r = max(r, -w[i - x][j]);
      for (int x = 1; x <= j; ++x) r = max(r, -w[i][j - x]);
      for (int x = 1; x <= j && x <= i; ++x) r = max(r, -w[i - x][j - x]);
    }
  return w[v[0]][v[1]];
}
char w[303][303][303];
char ma[303][303][303];
char mb[303][303][303];
char mc[303][303][303];
char mabc[303][303][303];
int so3() {
  memset(w, 0, sizeof(w));
  memset(ma, 0, sizeof(ma));
  memset(mb, 0, sizeof(mb));
  memset(mc, 0, sizeof(mc));
  memset(mabc, 0, sizeof(mabc));
  for (int a = 0; a <= v[0]; ++a)
    for (int b = 0; b <= v[1]; ++b)
      for (int c = 0; c <= v[2]; ++c) {
        char &r = w[a][b][c];
        r = -1;
        if (a) r = ((r) < (-ma[a - 1][b][c]) ? (-ma[a - 1][b][c]) : (r));
        if (b) r = ((r) < (-mb[a][b - 1][c]) ? (-mb[a][b - 1][c]) : (r));
        if (c) r = ((r) < (-mc[a][b][c - 1]) ? (-mc[a][b][c - 1]) : (r));
        if (a && b && c)
          r = ((r) < (-mabc[a - 1][b - 1][c - 1]) ? (-mabc[a - 1][b - 1][c - 1])
                                                  : (r));
        ma[a][b][c] = a ? min(ma[a - 1][b][c], r) : r;
        mb[a][b][c] = b ? min(mb[a][b - 1][c], r) : r;
        mc[a][b][c] = c ? min(mc[a][b][c - 1], r) : r;
        mabc[a][b][c] = (a && b && c) ? min(mabc[a - 1][b - 1][c - 1], r) : r;
      }
  return w[v[0]][v[1]][v[2]];
}
int i, j, k, l;
int main() {
  cin >> n;
  for (int _ = 0; _ < n; ++_) cin >> (v)[_];
  ;
  int res = 0;
  if (n == 1) res = so1();
  if (n == 2) res = so2();
  if (n == 3) res = so3();
  cout << ((res == 1) ? "BitLGM" : "BitAryo") << endl;
  return 0;
}
