#include <bits/stdc++.h>
const int maxn = 1e3 + 7;
long long a, b, t;
int n;
int main() {
  scanf("%d", &n);
  for (int o = 0; o < n; o++) {
    scanf("%lld%lld", &a, &b);
    long double t1 = (long double)a * b;
    long double c = pow(t1, 1 / 3.0);
    long long ans = (long long)(c + 0.5);
    if (ans * ans * ans == a * b && a % ans == 0 && b % ans == 07) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
  return 0;
}
