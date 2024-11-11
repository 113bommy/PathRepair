#include <bits/stdc++.h>
using namespace std;
int tp;
long long n;
int ask(long long i, long long j) {
  cout << i << ' ' << j << endl;
  fflush(stdout);
  cin >> tp;
  if (tp == 0) exit(0);
  return tp;
}
void dfs1(long long la, long long ra, long long lb, long long rb);
void dfs2(long long la, long long ra, long long lb, long long rb,
          long long limx, long long limy) {
  if (la > limx) dfs1(la, ra, lb, limy);
  if (lb > limy) dfs1(la, limx, lb, rb);
  long long x = la + (limx - la) * 2 / 3;
  long long y = lb + (limy - lb) * 2 / 3;
  int res = ask(x, y);
  if (res == 1) dfs2(x + 1, ra, lb, rb, limx, limy);
  if (res == 2) dfs2(la, ra, y + 1, rb, limx, limy);
  if (res == 3) dfs2(la, ra, lb, rb, x, y);
}
void dfs1(long long la, long long ra, long long lb, long long rb) {
  if (la == ra && lb == rb) ask(la, lb);
  long long x = la + (ra - la) / 3;
  long long y = lb + (rb - lb) / 3;
  int res = ask(x, y);
  if (res == 1) dfs1(x + 1, ra, lb, rb);
  if (res == 2) dfs1(la, ra, y + 1, rb);
  if (res == 3) dfs2(la, ra, lb, rb, x, y);
}
int main() {
  cin >> n;
  dfs1(1, n, 1, n);
  return 0;
}
