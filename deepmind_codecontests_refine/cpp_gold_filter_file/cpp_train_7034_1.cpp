#include <bits/stdc++.h>
using namespace std;
int n, a[300005], b[300005], f[2][300005];
char s[10005];
struct num {
  int len, a[10005];
  void read() {
    scanf("%s", s);
    int l = strlen(s), ss = 1000000000;
    for (int i = l - 1; i >= 0; i--) {
      if (ss == 1000000000) {
        len++;
        ss = 1;
      }
      a[len] += ss * (s[i] - '0');
      ss *= 10;
    }
  }
  int div(int x) {
    int s = 0;
    for (int i = len; i; i--) {
      long long ss = 1LL * s * 1000000000 + a[i];
      a[i] = ss / x;
      s = ss % x;
    }
    if ((len) && (!a[len])) len--;
    return s;
  }
} m;
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  m.read();
  int lst = 0;
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int p = (i & 1), c = 0;
    if (i == n) {
      if (m.len > 1)
        c = 1000000000;
      else
        c = m.a[1];
    } else {
      if (a[i] > 1) c = m.div(a[i]);
    }
    for (int j = 1; j <= lst; j++)
      f[p ^ 1][j] = (f[p ^ 1][j] + f[p ^ 1][j - 1]) % 1000000007;
    if (i == n) {
      int l = max(c - b[i], 0), r = min(c, lst);
      if (l > r)
        printf("0");
      else {
        if (!l)
          printf("%d", f[p ^ 1][r]);
        else
          printf("%d",
                 (f[p ^ 1][r] - f[p ^ 1][l - 1] + 1000000007) % 1000000007);
      }
      continue;
    }
    for (int j = 0; j * a[i] + c - b[i] <= lst; j++) {
      int l = max(j * a[i] + c - b[i], 0), r = min(j * a[i] + c, lst);
      if (!l)
        f[p][j] = f[p ^ 1][r];
      else
        f[p][j] = (f[p ^ 1][r] - f[p ^ 1][l - 1] + 1000000007) % 1000000007;
    }
    if (lst + b[i] - c < 0) {
      printf("0");
      return 0;
    }
    lst = (lst + b[i] - c) / a[i];
  }
}
