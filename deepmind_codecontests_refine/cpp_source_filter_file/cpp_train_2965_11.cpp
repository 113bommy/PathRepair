#include <bits/stdc++.h>
using namespace std;
int per[30];
double mat[2][30][30];
pair<int, int> convert(int l, int r, int x, int y) {
  int cl = l, cr = r;
  int len = y - x + 1;
  if (x <= l && l <= y) {
    cl = x + len - 1 - (l - x);
  }
  if (x <= r && r <= y) {
    cr = x + len - 1 - (r - x);
  }
  return {cl, cr};
}
void solve() {
  int n, k;
  scanf("%d %d ", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d ", &per[i]);
    --per[i];
  }
  int pos = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (per[i] < per[j]) {
        mat[pos][i][j] = 1;
      }
    }
  }
  int cl, cr;
  pair<int, int> tmp;
  double prob = 1.0 / ((n * (n - 1)));
  while (k--) {
    int npos = pos ^ 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        mat[npos][i][j] = 0;
      }
    }
    double sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) {
          continue;
        }
        for (int l = 0; l < n; ++l) {
          for (int r = l; r < n; ++r) {
            tmp = convert(i, j, l, r);
            double val = mat[pos][i][j] * prob;
            mat[npos][tmp.first][tmp.second] += val;
            sum += val;
          }
        }
      }
    }
    pos = npos;
  }
  double expOut = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      expOut += mat[pos][i][j];
    }
  }
  printf("%0.10lf\n", expOut);
}
int main() {
  solve();
  return 0;
}
