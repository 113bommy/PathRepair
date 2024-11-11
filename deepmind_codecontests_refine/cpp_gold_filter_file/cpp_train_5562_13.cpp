#include <bits/stdc++.h>
using namespace std;
int n, a[35], len, f[35][35][2], ans;
void upd(int &x, int y) { x = (x + y) % 1000000007; }
void dp() {
  f[1][0][1] = f[1][1][0] = 1;
  for (int i = 1; i < len; i++)
    for (int j = 0; j <= i; j++)
      for (int o = 0; o <= 1; o++) {
        if (f[i][j][o] == 0) continue;
        if (a[i + 1] == 1 || o == 1) upd(f[i + 1][j + 1][o], f[i][j][o]);
        if (o)
          upd(f[i + 1][j][o], (long long)f[i][j][o] * (1ll << j) % 1000000007);
        else {
          upd(f[i + 1][j][0],
              (long long)f[i][j][0] * (1ll << (j - 1)) % 1000000007);
          if (a[i + 1])
            upd(f[i + 1][j][1],
                (long long)f[i][j][0] * (1ll << (j - 1)) % 1000000007);
        }
      }
}
int main() {
  scanf("%d", &n);
  if (n == 0) {
    printf("1\n");
    return 0;
  }
  int t = n;
  while (t) {
    a[++len] = t % 2;
    t /= 2;
  }
  for (int i = 1; i <= len / 2; i++) swap(a[i], a[len - i + 1]);
  dp();
  for (int i = 0; i <= len; i++)
    for (int j = 0; j <= 1; j++) upd(ans, f[len][i][j]);
  printf("%d\n", ans);
  return 0;
}
