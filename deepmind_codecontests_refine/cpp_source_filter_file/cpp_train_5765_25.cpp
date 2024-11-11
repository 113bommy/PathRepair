#include <bits/stdc++.h>
using namespace std;
const int maxn = 1111;
double E0[maxn], E1[maxn], F[maxn];
int n, m, a, b;
double c[maxn][2];
int main() {
  while (cin >> n >> m) {
    cin >> a >> b;
    if (b == 1) {
      F[b] = (n - a) * 2;
    } else {
      for (int i = 1; i <= m; ++i) F[i] = 0.0;
      for (int i = n - 1; i >= a; --i) {
        for (int j = 1; j <= m; ++j) E0[j] = E1[j] = 0.0;
        int ty = 100;
        while (ty--) {
          E1[1] = 0.5 + 0.5 * (E0[2] + 1) + 0.5 * (F[1] + 1);
          E1[m] = 0.5 + 0.5 * (E0[m - 1] + 1) + 0.5 * (F[m] + 1);
          for (int j = 2; j < m; ++j)
            E1[j] = 1.0 / 3 * (4 + F[j] + E1[j - 1] + E1[j + 1]);
          for (int j = 1; j <= m; ++j) E0[j] = E1[j];
        }
        for (int j = 1; j <= m; ++j) F[j] = E0[j];
      }
    }
    printf("%.10f\n", F[b]);
  }
  return 0;
}
