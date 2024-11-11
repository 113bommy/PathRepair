#include <bits/stdc++.h>
using namespace std;
const int N = 2000100;
const int mod = 1e9 + 7;
int a[N], w[N], lg[N], n, x, y, z, num, nn, k, p;
long long ans, sum, ss[N], ss2[N], f[N];
int main() {
  scanf("%d%d%d", &n, &x, &y);
  p = x / y;
  nn = 2e6 + 10;
  for (int i = (1); i < (n + 1); i++) scanf("%d", &a[i]);
  for (int i = (1); i < (n + 1); i++) {
    w[a[i]]++;
    f[a[i]] = 1ll * w[a[i]] * a[i];
  }
  for (int i = (1); i < (nn + 1); i++)
    ss[i] = w[i] + ss[i - 1], ss2[i] = f[i] + ss2[i - 1];
  ans = 1ll << 61;
  for (int i = (2); i < (nn + 1); i++) {
    num = 0;
    sum = 0;
    k = 0;
    for (int j = i; j <= nn; j += i) {
      num += w[j];
      z = min(i - 1, p);
      sum +=
          1ll * j * (ss[j - 1] - ss[j - 1 - z]) - (ss2[j - 1] - ss2[j - z - 1]);
      k += ss[j - 1] - ss[j - 1 - z];
    }
    if (num == n)
      ans = 0;
    else {
      sum = 1ll * (n - num - k) * x + sum * y;
      ans = min(ans, sum);
    }
  }
  printf("%lld", ans);
  return 0;
}
