#include <bits/stdc++.h>
int sum(int x, int y) { return (((long long)x) + y) % 1000000007; }
int mul(int x, int y) { return (((long long)x) * y) % 1000000007; }
int pw(int c, int x) {
  if (!x) return 1;
  if (x % 2) return mul(c, pw(c, x - 1));
  int b = pw(c, x / 2);
  return mul(b, b);
}
int inv(int c) { return pw(c, 1000000007 - 2); }
int n, k;
int a[2048];
int w[2048];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  w[0] = 1;
  for (int i = 1; i < n; ++i) {
    w[i] = mul(mul(w[i - 1], k + i - 1), inv(i));
  }
  for (int i = 0; i < n; ++i) {
    int s = 0;
    for (int j = 0; j <= i; ++j) {
      s = sum(s, w[i - j] * a[j]);
    }
    if (i) putchar(' ');
    printf("%d", s);
  }
  puts("");
  return 0;
}
