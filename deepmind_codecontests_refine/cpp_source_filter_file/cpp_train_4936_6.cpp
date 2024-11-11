#include <bits/stdc++.h>
using namespace std;
const int maxn = 300050;
const int maxv = 1000050 * 2;
int n, k, a[maxn], mp[maxv], p[maxv];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  n = read();
  k = read();
  int a, t = 10000000;
  for (int i = 1; i <= n; ++i) mp[a = read()]++, t = min(t, a);
  for (int i = 1; i <= maxv; ++i) mp[i] += mp[i - 1];
  for (int i = 1; i <= maxv; ++i) p[i] = mp[min(maxv, i + k)] - mp[i - 1];
  int ans = k;
  for (int i = k + 1; i <= t; ++i) {
    int j = i;
    int tmp = 0;
    while (j <= maxv) {
      tmp += p[j];
      j = j + i;
    }
    if (tmp == n) ans = i;
  }
  printf("%d\n", ans);
  return 0;
}
