#include <bits/stdc++.h>
using namespace std;
const int maxn = 300030;
inline int read() {
  int x = 0, c = getchar(), f = 0;
  for (; c > '9' || c < '0'; f = c == '-', c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  return f ? -x : x;
}
inline bool scan_lf(double &num) {
  char in;
  double Dec = 0.1;
  bool IsN = false, IsD = false;
  in = getchar();
  if (in == EOF) return false;
  while (in != '-' && in != '.' && (in < '0' || in > '9')) in = getchar();
  if (in == '-') {
    IsN = true;
    num = 0;
  } else if (in == '.') {
    IsD = true;
    num = 0;
  } else
    num = in - '0';
  if (!IsD) {
    while (in = getchar(), in >= '0' && in <= '9') {
      num *= 10;
      num += in - '0';
    }
  }
  if (in != '.') {
    if (IsN) num = -num;
    return true;
  } else {
    while (in = getchar(), in >= '0' && in <= '9') {
      num += Dec * (in - '0');
      Dec *= 0.1;
    }
  }
  if (IsN) num = -num;
  return true;
}
int a[1010] = {0}, sum[1010] = {0};
int main() {
  int n, d;
  while (~scanf("%d%d", &n, &d)) {
    for (int i = 0; i < n; i++) {
      int x = read();
      a[x]++;
    }
    for (int i = 1; i <= 100; i++) sum[i] = sum[i - 1] + a[i];
    int ans = 10101111;
    for (int i = 1; i <= 100; i++) {
      int j = i + d;
      if (j > 100) j = 100;
      ans = min(ans, n - (sum[j] - sum[i - 1]));
    }
    printf("%d\n", ans);
  }
  return 0;
}
