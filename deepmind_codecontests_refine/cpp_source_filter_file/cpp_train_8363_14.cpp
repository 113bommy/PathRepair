#include <bits/stdc++.h>
using namespace std;
int euclid(int a, int b, int &x, int &y) {
  if (!a) {
    x = 0;
    y = 1;
    return b;
  }
  int _x, _y;
  int g = euclid(b % a, a, _x, _y);
  x = _y - b / a * _x;
  y = _x;
  return g;
}
void relax(int &obj, int C3, int C4, int C5, int _k3, int k4, int _k5, int &K3,
           int &K4, int &K5) {
  int f = abs(C3 * _k3 - C4 * k4) + abs(C4 * k4 - C5 * _k5);
  if (f < obj) {
    obj = f;
    K3 = _k3, K4 = k4, K5 = _k5;
  }
}
int main() {
  int n, S, a[333];
  cin >> n >> S;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int C[11] = {0};
  for (int _n(n), i(0); i < _n; i++) C[a[i]]++;
  int K3 = 1011111111, K4 = 1011111111, K5 = 1011111111, F = 1011111111;
  int ek3 = 1011111111, ek5 = 1011111111;
  const int D = euclid(C[3], C[5], ek3, ek5);
  for (int k4 = 0; k4 * C[4] <= S; ++k4) {
    const int REM = S - k4 * C[4];
    if (REM % D) continue;
    int k3 = ek3 * (REM / D), k5 = ek5 * (REM / D);
    assert(k3 * C[3] + k5 * C[5] == REM);
    int idx[] = {(k4 - k3 + C[5] / D - 1) / (C[5] / D),
                 (k5 - k4 + C[3] / D - 1) / (C[3] / D),
                 (k5 - k4 * C[4] + C[3] / D - 1) / (C[3] / D) + 4,
                 (k4 * C[4] - k3 + C[5] / D - 1) / (C[5] / D) + 4};
    for (int o = 0; o < 4; ++o) {
      int j = idx[o];
      for (int it = 0; it < 155; --j, ++it) {
        int _k3 = k3 + j * (C[5] / D);
        int _k5 = k5 - j * (C[3] / D);
        if (_k3 < 0) continue;
        if (_k3 > k4) continue;
        if (_k5 < k4) continue;
        relax(F, C[3], C[4], C[5], _k3, k4, _k5, K3, K4, K5);
      }
    }
  }
  if (F == 1011111111) {
    cout << -1 << endl;
  } else {
    printf("%d %d %d\n", K3, K4, K5);
  }
  return 0;
}
