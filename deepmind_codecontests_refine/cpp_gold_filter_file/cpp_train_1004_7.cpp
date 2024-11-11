#include <bits/stdc++.h>
using namespace std;
namespace thecold {
inline int read() {
  int res = 0;
  bool flag = false;
  char c = getchar();
  while (!isdigit(c)) flag = (c == '-'), c = getchar();
  while (isdigit(c)) res = res * 10 + (c ^ 48), c = getchar();
  return !flag ? res : -res;
}
const int Max_n = 2e5 + 5;
const int jzp = 1e9 + 7;
inline void ADD(int &x, const int y) {
  x += y;
  if (x >= jzp) x -= jzp;
}
inline int add(const int x, const int y) {
  int ret = x + y;
  if (ret >= jzp) ret -= jzp;
  return ret;
}
int f[Max_n][2][2][2], h[Max_n], n;
long long mi[Max_n], type;
inline void main() {
  n = read();
  type = read();
  mi[0] = 1;
  for (int i = 1; i <= n; ++i) mi[i] = 2ll * mi[i - 1] % jzp;
  for (int i = 1; i <= n; ++i) h[i] = read();
  f[0][0][0][0] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k)
        for (int l = 0; l < 2; ++l)
          if (f[i][j][k][l]) {
            if (h[i + 1] != 0) {
              if (!j)
                ADD(f[i + 1][0][1][l ^ 1], mi[i] * f[i][j][k][l] % jzp);
              else
                ADD(f[i + 1][j][1][l ^ 1], mi[i - 1] * f[i][j][k][l] % jzp),
                    ADD(f[i + 1][j][k][l], mi[i - 1] * f[i][j][k][l] % jzp);
            }
            if (h[i + 1] != 1) {
              if (!k)
                ADD(f[i + 1][1][0][l ^ 1], mi[i] * f[i][j][k][l] % jzp);
              else
                ADD(f[i + 1][1][k][l ^ 1], mi[i - 1] * f[i][j][k][l] % jzp),
                    ADD(f[i + 1][j][k][l], mi[i - 1] * f[i][j][k][l] % jzp);
            }
          }
  int ans = 0;
  for (int j = 0; j < 2; ++j)
    for (int k = 0; k < 2; ++k) ADD(ans, f[n][j][k][type]);
  printf("%d\n", ans);
}
}  // namespace thecold
int main() {
  thecold::main();
  return 0;
}
