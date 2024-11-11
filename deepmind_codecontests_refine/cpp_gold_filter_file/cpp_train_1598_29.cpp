#include <bits/stdc++.h>
using namespace std;
double opt[205][205][205];
struct NODE {
  int p, a;
};
bool cmp(const NODE &a, const NODE &b) {
  if (a.a != b.a) return a.a > b.a;
  return a.p > b.p;
}
int main() {
  int n, l, b;
  NODE nlist[205];
  scanf("%d%d%d", &n, &l, &b);
  for (int i = 1; i <= n; i++) scanf("%d", &nlist[i].p);
  for (int i = 1; i <= n; i++) scanf("%d", &nlist[i].a);
  sort(nlist + 1, nlist + n + 1, cmp);
  memset(opt, 0, sizeof(opt));
  opt[0][0][min(b, n)] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= n; k++) {
        if (nlist[i + 1].a == -1) {
          if (k >= 1) {
            opt[i + 1][j + 1][k - 1] += opt[i][j][k] * nlist[i + 1].p / 100;
          }
          opt[i + 1][j][k] += opt[i][j][k] * (100 - nlist[i + 1].p) / 100;
        } else {
          opt[i + 1][j + 1][min(k + nlist[i + 1].a, n)] +=
              opt[i][j][k] * nlist[i + 1].p / 100;
          opt[i + 1][j][k] += opt[i][j][k] * (100 - nlist[i + 1].p) / 100;
        }
      }
    }
  }
  double ans = 0;
  for (int j = l; j <= n; j++) {
    for (int k = 0; k <= n; k++) {
      ans += opt[n][j][k];
    }
  }
  printf("%.12lf\n", ans);
  return 0;
}
