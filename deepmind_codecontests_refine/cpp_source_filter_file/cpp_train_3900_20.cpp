#include <bits/stdc++.h>
using namespace std;
const int MAX = 2005;
int n;
int t[MAX][MAX];
long long diag1[2 * MAX], diag2[2 * MAX];
int main() {
  scanf(" %d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf(" %d", &t[i][j]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i + j < n) diag1[i] += (long long)t[j][i + j];
      if (i - j >= 0) diag2[i] += (long long)t[j][i - j];
      if (i != 0 && i + j < n) {
        diag1[n + i - 1] += (long long)t[i + j][j];
        diag2[n + i - 1] += (long long)t[i + j][n - j - 1];
      }
    }
  }
  tuple<long long, int, int> bishop1, bishop2;
  get<1>(bishop1) = 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      long long aux = -t[i][j];
      if (i > j) {
        aux += diag1[n - 1 + (i - j)];
      } else {
        aux += diag1[j - i];
      }
      aux += diag2[i + j];
      if ((i + j) % 2 == 0 && aux > get<0>(bishop1))
        bishop1 = make_tuple(aux, i, j);
      if ((i + j) % 2 == 1 && aux > get<0>(bishop2))
        bishop2 = make_tuple(aux, i, j);
    }
  }
  long long b1, b2;
  int x1, x2, y1, y2;
  tie(b1, x1, y1) = bishop1;
  tie(b2, x2, y2) = bishop2;
  printf("%lld\n%d %d %d %d\n", b1 + b2, x1 + 1, y1 + 1, x2 + 1, y2 + 1);
}
