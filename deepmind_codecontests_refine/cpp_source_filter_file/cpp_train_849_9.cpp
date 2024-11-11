#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 5e5 + 10;
long long a[N];
long long p[N], t1[N], t2[N], ans1, ans2;
int main() {
  long long t, n, a1, a2, k1, k2;
  scanf("%lld", &n);
  a1 = a2 = 0;
  p[0] = 1;
  t = 0;
  p[t++] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    if (a[i] < 0) {
      p[t++] = i;
    }
  }
  p[t++] = n + 1;
  ans1 = ans2 = 0;
  for (int i = 1; i < t; i++) {
    t1[i - 1] = p[i] - p[i - 1];
  }
  for (int i = 1; i < t; i++) {
    if (i % 2) {
      ans1 += t1[i];
    } else {
      ans2 += t1[i];
    }
  }
  long long res = 0;
  for (int i = 0; i < t; i++) {
    if (i % 2 == 0) {
      res += t1[i] * ans1;
      ans1 -= t1[i + 1];
    } else {
      res += t1[i] * ans2;
      ans2 -= t1[i + 1];
    }
  }
  printf("%d ", res);
  printf("%d\n", (n + 1) * n / 2 - res);
  return 0;
}
