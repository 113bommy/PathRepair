#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k, x, y;
  scanf("%lld %lld %lld %lld %lld", &n, &m, &k, &x, &y);
  long long int a[105][105] = {0};
  int start;
  if (n == 1) {
    long long maxi, mini, val;
    if (k % m == 0) {
      maxi = k / m;
      mini = k / m;
      val = maxi;
    } else {
      maxi = k / m + 1;
      mini = k / m;
      if (k % m >= y)
        val = maxi;
      else
        val = mini;
    }
    printf("%lld %lld %lld\n", maxi, mini, val);
    return 0;
  }
  if (k > (n * m)) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        a[i][j] += 1;
      }
    }
    k = k - n * m;
    long long int left = k / ((n - 1) * m);
    long long int rem = k % ((n - 1) * m);
    long long int last = 0, first;
    if (left % 2 == 0) {
      last = left / 2;
      start = n;
      first = left / 2;
    } else {
      last = left / 2;
      first = left / 2;
      start = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (i == n)
          a[i][j] += last;
        else if (i == 1)
          a[i][j] += first;
        else
          a[i][j] += left;
      }
    }
    if (start == 1) {
      for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (rem == 0) break;
          a[i][j] += 1;
          rem--;
        }
        if (rem == 0) break;
      }
    } else {
      for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
          if (rem == 0) break;
          a[i][j] += 1;
          rem--;
        }
        if (rem == 0) break;
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        a[i][j] += 1;
        k--;
        if (k == 0) break;
      }
      if (k == 0) break;
    }
  }
  long long maxi = 0, mini = 1e18 + 1, val = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == x && j == y) val = a[i][j];
      maxi = max(maxi, a[i][j]);
      mini = min(mini, a[i][j]);
    }
  }
  printf("%lld %lld %lld\n", maxi, mini, val);
  return 0;
}
