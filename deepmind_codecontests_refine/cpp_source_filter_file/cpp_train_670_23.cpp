#include <bits/stdc++.h>
using namespace std;
int n, T;
vector<double> p(5005);
vector<int> t(5005);
double mm[5005][5005], pw[5005];
int main() {
  scanf("%d%d", &n, &T);
  for (int i = 0; i < (n); ++i) {
    scanf("%d%d", &p[i], &t[i]);
    p[i] /= 100.0;
    pw[i] = pow(1 - p[i], t[i] - 1);
  }
  memset(mm, 0, sizeof(mm));
  for (int i = (n - 1); i >= (0); --i) {
    for (int j = (T - 1); j >= (0); --j) {
      mm[i][j] = p[i] * (mm[i + 1][j + 1] + 1);
      double tmp = mm[i][j + 1];
      if (j + t[i] <= T) tmp += pw[i] * (mm[i + 1][j + t[i]] + 1);
      if (j + t[i] + 1 <= T) tmp -= pw[i] * (mm[i + 1][j + t[i] + 1] + 1);
      mm[i][j] += tmp * (1 - p[i]);
    }
  }
  cout << setprecision(10) << mm[0][0] << endl;
  return 0;
}
