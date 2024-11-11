#include <bits/stdc++.h>
using namespace std;
long long n, k, a[200005], d[200005];
long long mx = 10000000000000000;
int main() {
  int c;
  scanf("%lld %lld", &n, &k);
  n++;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    d[i] = a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == 0) continue;
    int j = i;
    long long b = a[i];
    while (b % 2 == 0 && j < n - 1) {
      b >>= 1;
      j++;
    }
    a[i] = 0;
    a[j] += b;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] != 0) {
      c = i;
      break;
    }
  }
  for (int i = n - 2; i >= c; i--) {
    a[i] += a[i + 1] + a[i + 1];
    a[i + 1] = 0;
    if (abs(a[i]) > mx) {
      printf("0\n");
      return 0;
    }
  }
  int ans = 0;
  for (int i = c; i >= 0; i--) {
    if (abs(d[i] - a[i]) <= k && (i != n - 1 || d[i] - a[i] != 0)) {
      ans++;
    }
    if (i) {
      a[i - 1] = a[i] + a[i];
      if (a[i - 1] > mx) break;
    }
  }
  printf("%d\n", ans);
}
