#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
const int inf = 0x3f3f3f3f;
long long c[55][55];
int v[55];
long long solve(int now) {
  long long ans = 1;
  int num = 0;
  for (int i = now + 1; i >= 1; --i)
    if (v[i]) {
      ans *= c[now - i + 1 - num][v[i]];
      num += v[i];
    }
  return ans;
}
int main() {
  for (int i = 0; i < 55; ++i) c[i][i] = c[i][0] = 1;
  for (int i = 1; i < 55; ++i)
    for (int j = 1; j < i; ++j) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  int t;
  scanf("%d", &t);
  while (t--) {
    long long x;
    int now = 2, num = 0;
    scanf("%lld", &x);
    memset(v, 0, sizeof(v));
    while (x) {
      ++v[x % now];
      x /= now;
      ++now;
      ++num;
    }
    long long ans = solve(num);
    if (v[0]) ans -= solve(num - 1);
    printf("%lld\n", ans - 1);
  }
  return 0;
}
