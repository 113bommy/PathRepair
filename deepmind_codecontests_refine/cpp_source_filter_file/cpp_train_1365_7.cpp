#include <bits/stdc++.h>
using namespace std;
long long po(long long a, long long b) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2) {
      x = x * y;
      x %= 1000000007;
    }
    y = y * y;
    y %= 1000000007;
    b /= 2;
  }
  return x;
}
int main() {
  if (0) {
    freopen("/Users/mohibmanva/Desktop", "r", stdin);
    freopen("/Users/mohibmanva/Desktop", "w", stdout);
  }
  int T = 1;
  while (T--) {
    int n, d;
    scanf("%d %d", &n, &d);
    static int a[200005], b[200005];
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &b[i]);
    }
    d--;
    a[d] += b[0];
    int curr = n - 1;
    for (int i = 0; i < n; i++) {
      if (i == d || (a[i] + b[curr] >= a[d])) {
        if (i != d) {
          a[i] = 1e9;
        }
        continue;
      }
      a[i] += b[curr];
      curr--;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1e9) {
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
