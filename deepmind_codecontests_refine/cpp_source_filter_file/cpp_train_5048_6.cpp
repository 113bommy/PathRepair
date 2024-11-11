#include <bits/stdc++.h>
using namespace std;
int n;
int x[2000];
int y[2000];
long long ans;
int cnt[250][450];
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void go(int pt) {
  for (int i = 0; i <= 200; i++) {
    for (int j = 200; j <= 400; j++) {
      cnt[i][j] = 0;
    }
  }
  for (int i = pt + 1; i < n; i++) {
    int dx = x[i] - x[pt];
    int dy = y[i] - y[pt];
    if (dx < 0) {
      dx *= -1;
      dy *= -1;
    }
    if (dx == 0) {
      dy = abs(dy);
    }
    int div = gcd(dx, abs(dy));
    dx /= div;
    dy /= div;
    dy += 200;
    ans -= cnt[dx][dy];
    cnt[dx][dy]++;
  }
}
int main() {
  scanf("%d", &n);
  ans = (long long)n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
  }
  for (int i = 0; i < n; i++) {
    go(i);
  }
  printf("%I64d", ans);
  return 0;
}
