#include <bits/stdc++.h>
template <typename T>
inline void read(T& x) {
  char cu = getchar();
  x = 0;
  bool fla = 0;
  while (!isdigit(cu)) {
    if (cu == '-') fla = 1;
    cu = getchar();
  }
  while (isdigit(cu)) x = x * 10 + cu - '0', cu = getchar();
  if (fla) x = -x;
}
template <typename T>
inline void printe(const T x) {
  if (x >= 10) printe(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void print(const T x) {
  if (x < 0)
    putchar('-'), printe(-x);
  else
    printe(x);
}
template <typename T>
inline T min(const T a, const T b) {
  return a < b ? a : b;
}
template <typename T>
inline T max(const T a, const T b) {
  return a > b ? a : b;
}
template <typename T>
inline T gcd(const T a, const T b) {
  if (!b) return a;
  return gcd(b, a % b);
}
template <typename T>
inline void maxd(T& a, const T b) {
  a = a > b ? a : b;
}
template <typename T>
inline T abs(const T a) {
  return a > 0 ? a : -a;
}
int n, m, a[1000001], b[1000001], k[1000001], all, pl[1000001];
int main() {
  read(n), read(m);
  for (register int i = 1; i <= m; i++) read(a[i]), b[i] = a[i], all += a[i];
  for (register int i = 1; i <= m; i++) {
    k[i] = a[i] % n;
    if (k[i]) {
      int las = n - k[i];
      for (int j = i + 1; j <= m + 1; j++)
        if (a[j] < las && j != m + 1) {
          k[j] = k[j - 1] + a[j];
          las -= a[j];
        } else {
          i = j - 1;
          a[j] -= las;
          break;
        }
    }
  }
  std::sort(k + 1, k + m);
  print((all + n - 1) / n), putchar('\n');
  k[m] = n;
  for (register int i = 1; i <= m; i++)
    print(k[i] - k[i - 1]), putchar(' '), pl[k[i]] = i;
  putchar('\n');
  for (register int i = 1; i <= m; i++) a[i] = b[i];
  for (register int i = 1; i <= m; i++) {
    while (a[i] >= n) {
      a[i] -= n;
      for (register int j = 1; j <= m; j++) print(i), putchar(' ');
      putchar('\n');
    }
    k[i] = a[i];
    if (k[i] >= 0 && i == m) {
      for (register int j = 1; j <= m; j++) print(i), putchar(' ');
      putchar('\n');
    } else if (k[i] >= 0) {
      int las = n - k[i], zq = 0;
      while (zq < pl[k[i]]) zq++, print(i), putchar(' ');
      for (int j = i + 1; j <= m; j++)
        if (j == m) {
          i = j - 1;
          a[j] -= las;
          while (zq < m) zq++, print(j), putchar(' ');
          break;
        } else if (a[j] < las) {
          k[j] = k[j - 1] + a[j];
          las -= a[j];
          while (zq < pl[k[j]]) zq++, print(j), putchar(' ');
        } else {
          i = j - 1;
          a[j] -= las;
          while (zq < m) zq++, print(j), putchar(' ');
          break;
        }
      putchar('\n');
    }
  }
  return 0;
}
