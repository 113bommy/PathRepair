#include <bits/stdc++.h>
using namespace std;
double extra(const vector<int> &pos, int n) {
  double ret = 0;
  for (int i = (0); i < (((int)(pos).size())); ++i)
    if (pos[i] != -1) {
      ret += pos[i] * (n - pos[i] - 1);
      bool ul2lr = true, ur2ll = true;
      for (int j = (i + 1); j < (((int)(pos).size())); ++j) {
        if (pos[j] == -1) break;
        if (pos[j - 1] <= pos[j]) ur2ll = false;
        if (pos[j - 1] >= pos[j]) ul2lr = false;
        if (ul2lr) ret += pos[i] * (n - pos[j] - 1);
        if (ur2ll) ret += pos[j] * (n - pos[i] - 1);
      }
    }
  return ret * 4;
}
void run() {
  int R, C;
  scanf("%d%d", &R, &C);
  int total = R * C;
  vector<int> rows(R, -1), cols(C, -1);
  for (int r = (0); r < (R); ++r)
    for (int c = (0); c < (C); ++c) {
      char x;
      scanf(" %c", &x);
      if (x == 'X') rows[r] = c, cols[c] = r, --total;
    }
  double ret = 0;
  for (int r1 = (0); r1 < (R); ++r1)
    for (int r2 = (0); r2 < (R); ++r2)
      ret += (rows[r1] == -1 ? C : C - 1) * (rows[r2] == -1 ? C : C - 1) *
             abs(r1 - r2);
  for (int c1 = (0); c1 < (C); ++c1)
    for (int c2 = (0); c2 < (C); ++c2)
      ret += (cols[c1] == -1 ? R : R - 1) * (cols[c2] == -1 ? R : R - 1) *
             abs(c1 - c2);
  ret += extra(rows, C) + extra(cols, R);
  ret /= total * total;
  printf("%.9lf\n", ret);
}
int main() {
  run();
  return 0;
}
