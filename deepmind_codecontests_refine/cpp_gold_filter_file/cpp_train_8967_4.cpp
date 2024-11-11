#include <bits/stdc++.h>
using namespace std;
long long n, a[15][15], ans[15], tmp, sum;
long long gets() {
  long long v = 0;
  char ch;
  bool f = 0;
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = 1;
  v = ch - 48;
  while (isdigit(ch = getchar())) v = (v << 1) + (v << 3) + ch - 48;
  return f ? -v : v;
}
long long fast(long long x, long long k) {
  long long tmp = 1;
  while (k) {
    if (k % 2 == 1) tmp = tmp * x % 1000003;
    x = x * x % 1000003;
    k >>= 1;
  }
  return tmp;
}
long long inv(long long x) { return fast(x, 1000003 - 2); }
int main() {
  n = 11;
  for (int i = 1; i <= n; i++) cout << "? " << i << endl, a[i][n + 1] = gets();
  for (int i = 1; i <= n; i++) {
    a[i][1] = 1;
    for (int j = 2; j <= n; j++) a[i][j] = a[i][j - 1] * i % 1000003;
  }
  for (int i = 1; i <= n; i++) {
    if (!a[i][i]) {
      for (int j = i + 1; j <= n; j++) {
        if (a[j][i]) {
          for (int k = 1; k <= n + 1; k++) swap(a[i][k], a[j][k]);
          break;
        }
      }
    }
    if (!a[i][i]) continue;
    for (int j = i + 1; j <= n; j++)
      if (a[j][i]) {
        for (int k = i + 1; k <= n + 1; k++)
          a[j][k] =
              (a[j][k] - a[i][k] * a[j][i] % 1000003 * inv(a[i][i]) % 1000003 +
               1000003) %
              1000003;
        a[j][i] = 0;
      }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++)
      a[i][n + 1] =
          (a[i][n + 1] - ans[j] * a[i][j] % 1000003 + 1000003) % 1000003;
    ans[i] = a[i][n + 1] * inv(a[i][i]) % 1000003;
  }
  for (int i = 0; i <= 1000003 - 1; i++) {
    tmp = 1;
    sum = 0;
    for (int j = 1; j <= n; j++) {
      sum += tmp * ans[j] % 1000003, tmp = tmp * i % 1000003, sum %= 1000003;
    }
    if (sum == 0) {
      cout << "! " << i << endl;
      return 0;
    }
  }
  cout << "! -1" << endl;
  return 0;
}
