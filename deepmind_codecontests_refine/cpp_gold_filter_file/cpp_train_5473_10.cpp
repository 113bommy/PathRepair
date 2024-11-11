#include <bits/stdc++.h>
using namespace std;
FILE *in;
FILE *out;
struct State {
  int p1, p2, dir, idx;
};
int n;
int len;
char a[256];
int dyn[64][64][2][256];
int recurse(int p1, int p2, int dir, int idx) {
  if (idx >= len) return 999666333;
  if (dyn[p1][p2][dir][idx] != -1) return dyn[p1][p2][dir][idx];
  if (p1 == p2) return dyn[p1][p2][dir][idx] = 0;
  int ans = 0;
  int npos = p2, ndir = dir;
  if (dir == 0)
    npos--;
  else
    npos++;
  if (npos == 0) {
    npos = 2;
    ndir = !ndir;
  }
  if (npos == n + 1) {
    npos = n - 1;
    ndir = !ndir;
  }
  ans = max(ans, recurse(p1, npos, ndir, idx + 1) + 1);
  if (a[idx] == '0') {
    if (p1 - 1 >= 1 && p1 - 1 <= n && p1 - 1 != p2)
      ans = max(ans, recurse(p1 - 1, npos, ndir, idx + 1) + 1);
    if (p1 + 1 >= 1 && p1 + 1 <= n && p1 + 1 != p2)
      ans = max(ans, recurse(p1 + 1, npos, ndir, idx + 1) + 1);
  } else {
    for (int i = 1; i <= n; i++)
      ans = max(ans, recurse(i, npos, ndir, idx + 1) + 1);
  }
  return dyn[p1][p2][dir][idx] = ans;
}
int main(void) {
  in = stdin;
  out = stdout;
  int p1, p2, dir;
  fscanf(in, "%d %d %d", &n, &p1, &p2);
  char buff[8];
  fscanf(in, "%s", buff);
  fscanf(in, "%s", buff);
  if (buff[0] == 'h')
    dir = 0;
  else
    dir = 1;
  fscanf(in, "%s", a);
  len = (int)strlen(a);
  memset(dyn, -1, sizeof(dyn));
  int ans = recurse(p1, p2, dir, 0);
  if (ans >= 999666333)
    fprintf(out, "Stowaway\n");
  else
    fprintf(out, "Controller %d\n", ans);
  return 0;
}
