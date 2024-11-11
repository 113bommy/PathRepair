#include <bits/stdc++.h>
using namespace std;
int a[2000001];
int n;
long long f[2000001], ni[2000001];
long long ans;
bool cmp(int x, int y) { return x > y; }
long long calc(long long x, long long y) {
  long long s = 1;
  while (y) {
    if (y & 1) (s *= x) %= 1000000007;
    (x *= x) %= 1000000007, y /= 2;
  }
  return s;
}
long long C(int x, int y) {
  return f[x] * ni[y] % 1000000007 * ni[x - y] % 1000000007;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1, cmp);
  f[0] = 1;
  for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % 1000000007;
  ni[n] = calc(f[n], 1000000007 - 2);
  for (int i = n - 1; i >= 0; i--) ni[i] = ni[i + 1] * (i + 1) % 1000000007;
  int l = 1;
  for (int i = 2; i <= n + 1; i++)
    if (i == n + 1 || a[i] != a[i - 1]) {
      if (l == 1) {
        if (i != 2) ans = f[i - 1] * a[i - 1] % 1000000007;
        l = i;
      } else {
        ans =
            ans * C(l - 1 + i - l, i - l) % 1000000007 * f[i - l] % 1000000007;
        for (int j = 1; j <= i - l; j++)
          (ans += f[l - 1] * C(l - 1 + i - l - j - 1, i - l - j) % 1000000007 *
                  f[i - l] % 1000000007 * a[i - 1] % 1000000007) %= 1000000007;
        l = i;
      }
    }
  printf("%d", (int)ans);
  return 0;
}
