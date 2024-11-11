#include <bits/stdc++.h>
using namespace std;
int te, tv, re, hv, le, lv, rv, pe, pv, he;
vector<vector<double> > fv, fe;
void calc(int h, int t, int l, int r, double p, vector<vector<double> > &f,
          int res) {
  if (p == 100) {
    printf("%d", res);
    exit(0);
  }
  p = 1 - p / 100;
  f.assign(3100 + 4, vector<double>(h + 1, 0));
  f[0][h] = 1;
  for (int i = 0; i < (3100); i++)
    for (int j = 0; j < (h + 1); j++) {
      for (int x = (l); x < (r + 1); x++)
        f[i + 1][max(0, j - x)] += f[i][j] * p / (r - l + 1);
      f[i + 1][j] += f[i][j] * (1 - p);
    }
}
int main() {
  cin >> hv >> tv >> lv >> rv >> pv >> he >> te >> le >> re >> pe;
  calc(he, tv, lv, rv, pv, fe, 0);
  calc(hv, te, le, re, pe, fv, 1);
  double ans = 0;
  for (int i = (1); i < (3100); i++) {
    int j = ((i - 1) * tv + te - 1) / te;
    if (j > 3100) break;
    ans += (fe[i][0] - fe[i - 1][0]) * (1 - fv[j][0]);
  }
  printf("%.5lf", ans);
}
