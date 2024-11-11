#include <bits/stdc++.h>
using namespace std;
long long i, j, k, l, n, m, x, X, Y, ans;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &x);
    X += x % 2;
  }
  Y = n - X;
  ans += min(Y, X);
  X -= min(X, Y);
  ans += X / 3;
  printf("%I64d", ans);
}
