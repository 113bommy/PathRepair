#include <bits/stdc++.h>
using namespace std;
int n, k, y, h, ym;
int v[302][302];
double s[302];
int D = 2500;
inline int quickMax(int a, int b) { return a > b ? a : b; }
int main() {
  cin >> n >> k;
  for (int i = 0, _n = (n); i < _n; i++)
    for (int j = 0, _n = (k + 1); j < _n; j++) cin >> v[i][j];
  for (int x = 0, _n = (k); x < _n; x++) {
    for (int d = 0, _n = (D + 1); d < _n; d++) {
      ym = 0;
      for (int i = 0, _n = (n); i < _n; i++) {
        y = v[i][x] * (D - d) + v[i][x + 1] * d;
        h = quickMax(0, y - ym);
        ym = quickMax(ym, y);
        s[i] += h;
        if (d != 0 && d != D) s[i] += h;
      }
    }
  }
  for (int i = 0, _n = (n); i < _n; i++) cout << s[i] / D / 5000 << endl;
  return 0;
}
