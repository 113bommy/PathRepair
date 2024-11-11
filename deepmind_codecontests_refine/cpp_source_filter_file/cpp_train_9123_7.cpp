#include <bits/stdc++.h>
using namespace std;
int main() {
  int in, iw, im;
  double n, w, m;
  scanf("%lf%lf%lf", &n, &w, &m);
  in = n;
  iw = w;
  im = m;
  double each = (n * w) / m;
  int used[in];
  fill(used, used + in, 0);
  double left[in];
  fill(left, left + in, w);
  vector<int> bn[im];
  vector<double> an[im];
  bool has_sol = true;
  int next_n = 0;
  for (int next_m = 0; next_m < im; ++next_m) {
    double am = each;
    while (am > 0) {
      if (used[next_n] == 2) {
        next_n++;
      }
      if (left[next_n] <= 1e-9) next_n++;
      if (next_n == in) {
        has_sol = false;
        goto PRINT;
      }
      used[next_n]++;
      double rem = min(am, left[next_n]);
      bn[next_m].push_back(next_n + 1);
      an[next_m].push_back(rem);
      left[next_n] -= rem;
      am -= rem;
    }
  }
PRINT:
  if (has_sol) {
    printf("YES\n");
    for (int i = 0; i < im; ++i) {
      for (int j = 0; j < bn[i].size(); ++j) {
        printf("%d %.9lf", bn[i][j], an[i][j]);
        if (j + 1 != bn[i].size()) {
          printf(" ");
        }
      }
      printf("\n");
    }
  } else
    printf("NO\n");
  return 0;
}
