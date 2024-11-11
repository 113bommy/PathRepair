#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
struct matr {
  const static int n = 52;
  int a[n][n];
  static matr tmp, tmp2;
  matr() {}
  void ONE() {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) a[i][j] = (i == j);
  }
  void operator*=(const matr &m) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        int &cur = tmp.a[i][j];
        cur = 0;
        for (int y = 0; y < n; y++)
          cur = (cur + (long long)a[i][y] * m.a[y][j]) % MOD;
      }
    memcpy(a, tmp.a, sizeof(a));
  }
  void operator^=(long long pw) {
    tmp2 = *this;
    ONE();
    for (; pw; pw >>= 1) {
      if (pw & 1) *this *= tmp2;
      tmp2 *= tmp2;
    }
  }
  void print() {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) printf("%d%c", a[i][j], " \n"[j == n - 1]);
  }
};
matr matr::tmp = matr();
matr matr::tmp2 = matr();
matr ma;
int main() {
  long long n;
  int m, k;
  while (scanf("%lld"
               "%d%d",
               &n, &m, &k) >= 1) {
    memset(ma.a, 0, sizeof(ma.a));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++) ma.a[i][j] = 1;
    for (int i = 0; i < k; i++) {
      char ch1, ch2;
      scanf(" %c%c", &ch1, &ch2);
      int c1 = (ch1 >= 'A' && ch1 <= 'Z') ? ch1 - 'A' + 27 : ch1 - 'a';
      int c2 = (ch2 >= 'A' && ch2 <= 'Z') ? ch2 - 'A' + 27 : ch2 - 'a';
      ma.a[c1][c2] = 0;
    }
    ma ^= n - 1;
    long long res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++) res += ma.a[i][j];
    printf("%d\n", (int)(res % MOD));
  }
  return 0;
}
