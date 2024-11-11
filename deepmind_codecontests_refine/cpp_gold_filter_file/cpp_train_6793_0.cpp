#include <bits/stdc++.h>
using namespace std;
int n, p, a[2010], ans[2010], anscnt = 0, d[2010];
bool isGood(int x) {
  long long ans = 1;
  for (int i = 1; i <= n; ++i) {
    if (x <= 2000)
      ans *= d[x] - i + 1;
    else
      ans *= d[2000] - i + 1;
    ans %= p;
    if (!ans) return false;
    ++x;
  }
  return true;
}
int main() {
  cin >> n >> p;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ++d[a[i]];
  }
  for (int i = 1; i <= 2000; ++i) d[i] += d[i - 1];
  for (int i = 1; i <= 2000; ++i) {
    if (isGood(i)) ans[anscnt++] = i;
  }
  printf("%d\n", anscnt);
  for (int i = 0; i < anscnt; ++i) {
    printf("%d ", ans[i]);
  }
}
