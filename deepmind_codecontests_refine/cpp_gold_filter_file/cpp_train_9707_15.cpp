#include <bits/stdc++.h>
int read() {
  static int c, x;
  while ((c = getchar()) < 48) {
  }
  x = c & 15;
  while ((c = getchar()) >= 48) x = x * 10 + (c & 15);
  return x;
}
long long readll() {
  static int c;
  static long long x;
  while ((c = getchar()) < 48) {
  }
  x = c & 15;
  while ((c = getchar()) >= 48) x = x * 10 + (c & 15);
  return x;
}
int a[100010], b[100010];
long long val[100010];
inline long long calc(const int &i, const int &x) {
  return a[i] - 3ll * x * (x + 1) - 1;
}
int main() {
  const int n = read();
  const long long k = readll();
  long long lf = 0, rg = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    lf = std::min(lf, calc(i, a[i] - 1));
    rg = std::max(rg, 0ll + a[i]);
  }
  while (lf + 1 < rg) {
    const long long m = (lf + rg) >> 1;
    long long tot = 0;
    for (int i = 1; i <= n; ++i) {
      if (m >= a[i]) continue;
      int l = 0, r = a[i];
      while (l + 1 < r) {
        const int mid = (l + r) >> 1;
        if (calc(i, mid) >= m) {
          l = mid;
        } else {
          r = mid;
        }
      }
      tot += r;
      if (tot >= k) break;
    }
    if (tot >= k) {
      lf = m;
    } else {
      rg = m;
    }
  }
  const long long m = lf;
  long long tot = 0;
  for (int i = 1; i <= n; ++i) {
    if (m >= a[i]) continue;
    int l = 0, r = a[i];
    while (l + 1 < r) {
      const int mid = (l + r) >> 1;
      if (calc(i, mid) >= m) {
        l = mid;
      } else {
        r = mid;
      }
    }
    tot += r;
    b[i] = r;
    val[i] = calc(i, r - 1);
  }
  for (int i = 1; i <= n && tot > k; ++i) {
    if (b[i] && val[i] == lf) {
      --b[i];
      --tot;
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", b[i]);
  }
  return 0;
}
