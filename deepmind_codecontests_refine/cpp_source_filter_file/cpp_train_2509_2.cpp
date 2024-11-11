#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, base = 2333, mod = 20030731;
int n, m, a[N], b[N], pw[N], h1[N], h2[N], ans[N];
void init() {
  pw[0] = 1;
  for (int i = (1); i <= (n - 1); i++)
    pw[i] = (long long)base * pw[i - 1] % mod,
    h1[i] = (((long long)h1[i - 1] * base + b[i]) % mod + mod) % mod;
  for (int i = n - 1; i; i--)
    h2[i] = (((long long)h2[i + 1] * base + b[i]) % mod + mod) % mod;
}
int get1(int x, int y) {
  return (h1[y] + mod - (long long)h1[x - 1] * pw[y - x + 1] % mod) % mod;
}
int get2(int x, int y) {
  return (h2[x] + mod - (long long)h2[y + 1] * pw[y - x + 1] % mod) % mod;
}
bool chk(int x, int y) { return get1(x, y) == get2(y, x); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  for (int i = (1); i <= (n - 1); i++) b[i] = a[i + 1] - a[i];
  init();
  for (int i = (1); i <= (n); i++) {
    bool flag = 1;
    if (i > 1) flag &= chk(1, i - 1);
    if (i < n) {
      flag &= a[1] + a[i] + m == a[i + 1] + a[n];
      if (i < n - 1) flag &= chk(i + 1, n - 1);
    }
    if (flag) ans[++*ans] = (a[1] + a[i]) % m;
  }
  sort(ans + 1, ans + 1 + *ans);
  printf("%d\n", *ans);
  for (int i = (1); i <= (*ans); i++) printf("%d ", ans[i]);
  return 0;
}
