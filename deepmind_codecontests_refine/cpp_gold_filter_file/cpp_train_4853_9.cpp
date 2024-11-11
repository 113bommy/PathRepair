#include <bits/stdc++.h>
using namespace std;
const int N = 5009;
int a[N];
long long s[N];
struct Sol {
  int d0, d1, d2;
  long long res;
};
inline int read() {
  int s = 1, a = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') s = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    a = a * 10 + ch - '0';
    ch = getchar();
  }
  return s * a;
}
inline long long sum(int l, int r) {
  if (l < 0) return s[r - 1];
  return l <= r ? s[r - 1] - s[l - 1] : 0;
}
int main() {
  int n = read();
  for (int i = 0; i < n; i++) a[i] = read();
  s[0] = a[0];
  for (int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];
  Sol ans;
  ans.res = 0;
  for (int d1 = 0; d1 <= n; d1++) {
    int d0 = d1, d2 = d1;
    for (int j = 0; j <= d1; j++)
      if (sum(0, j) > sum(0, d0)) d0 = j;
    for (int j = d1; j <= n; j++)
      if (sum(d1, j) > sum(d1, d2)) d2 = j;
    long long res = sum(0, d0) - sum(d0, d1) + sum(d1, d2) - sum(d2, n);
    if (res >= ans.res) ans.res = res, ans.d0 = d0, ans.d1 = d1, ans.d2 = d2;
  }
  return 0 * printf("%d %d %d\n", ans.d0, ans.d1, ans.d2);
}
