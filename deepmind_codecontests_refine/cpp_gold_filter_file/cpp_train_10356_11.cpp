#include <bits/stdc++.h>
using namespace std;
int mark[5000000 * 4], n, m;
long long num(long long x) {
  long long g = (int)sqrt(x * 1.0);
  while (((g) * (g)) <= x) g++;
  while (((g) * (g)) > x) g--;
  return g;
}
int main() {
  scanf("%d%d", &n, &m);
  long long ans = 0;
  for (int b = 1; b <= n; b++) {
    long long max_c = min((long long)m, (((long long)b) * ((long long)b)));
    ans += max_c * 2;
    long long x = (((long long)b) * ((long long)b)) - max_c,
              y = (((long long)b) * ((long long)b)) - 1;
    long long l = num(x), r = num(y);
    if (((l) * (l)) < x) l++;
    ans -= (r - l + 1) * 2;
    mark[-b - r + n * 3]++;
    mark[-b - l + 1 + n * 3]--;
    mark[-b + l + n * 3]++;
    mark[-b + r + 1 + n * 3]--;
  }
  for (int i = 0, k = 0; i < n * 4; i++) {
    k += mark[i];
    if (k) ans++;
  }
  printf("%I64d\n", ans);
}
