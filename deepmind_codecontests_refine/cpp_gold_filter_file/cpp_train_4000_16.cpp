#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
long long f[maxn], n, m, ans, p, x;
bool cmp(int x, int y) { return x > y; }
long long find() {
  for (long long i = 1; i <= m; i++) {
    if ((i & 1) && i * i - i > 2 * n - 2) return i - 1;
    if (!(i & 1) && i * i - 2 > 2 * n - 2) return i - 1;
  }
  return m;
}
int main() {
  scanf("%I64d%I64d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%I64d%I64d", &x, &f[i]);
  p = find();
  sort(f + 1, f + m + 1, cmp);
  if (n == 1) {
    printf("%I64d\n", f[1]);
    return 0;
  }
  ans = 0;
  for (int i = 1; i <= p; i++) ans += f[i];
  printf("%I64d\n", ans);
  return 0;
}
