#include <bits/stdc++.h>
using namespace std;
void _fill_int(int* p, int val, int rep) {
  int i;
  for (i = 0; i < rep; i++) p[i] = val;
}
int N, M;
int X[1001];
int mat[501][501];
void solve() {
  int f, i, j, k, l, x, y;
  _fill_int((int*)mat, -1, sizeof(mat) / 4);
  cin >> N >> M;
  for (i = 0; i < N; i++) cin >> X[i];
  double ma = 0;
  for (i = 0; i < M; i++) {
    cin >> x >> y >> j;
    ma = max(ma, (X[x] + X[y] + 0.0) / j);
  }
  (void)printf("%.12lf\n", ma);
}
int main(int argc, char** argv) {
  string s;
  if (argc == 1) ios::sync_with_stdio(false);
  for (int i = 1; i < argc; i++) s += argv[i], s += '\n';
  for (int i = s.size() - 1; i >= 0; i--) ungetc(s[i], stdin);
  solve();
  return 0;
}
