#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
long long a[N];
const long long INF = 1e18;
long long mul(long long a, int b) {
  long long res = 1;
  for (int i = 0; i < b; i++) {
    res *= a;
  }
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
  }
  sort(a, a + n);
  long long res = 0;
  if (n >= 32) {
    for (int i = 0; i < n; i++) res += a[i] - 1;
  } else if (n == 2) {
    res = a[1] - 1;
  } else if (n == 1) {
    res = a[1] - 1;
  } else {
    res = INF;
    long long l = 1;
    while (a[n - 1] >= mul(l, n - 1)) {
      l++;
    }
    for (int i = 1; i <= l; i++) {
      long long minn = 0;
      for (int j = 0; j < n; j++) {
        minn += abs(mul(i, j) - a[j]);
      }
      res = min(res, minn);
    }
  }
RES:
  printf("%lld\n", res);
}
