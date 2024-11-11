#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
int n;
long long m;
int a[N], b[N];
inline bool judge(int x) {
  int invalid = a[0] - x + b[0];
  for (int i = 1; i < 60; i++) {
    if (a[i] <= x) {
      invalid -= min(invalid, x - a[i]);
      x = a[i];
    } else
      invalid += a[i] - x;
    invalid += b[i];
  }
  return invalid <= x;
}
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%lld", &m);
    int bit = 0;
    bool flag = true;
    while (m > 1) {
      if (m & 1) flag = false;
      m >>= 1;
      ++bit;
    }
    if (!flag)
      ++b[bit];
    else
      ++a[bit];
  }
  int L = a[0] / 2, R = a[0];
  int ans = R;
  while (L <= R) {
    int M = L + R >> 1;
    if (judge(M)) {
      ans = M;
      R = M - 1;
    } else {
      L = M + 1;
    }
  }
  if (!judge(ans)) return puts("-1"), 0;
  for (int i = ans; i <= a[0]; i++) printf("%d%c", i, " \n"[i == a[0]]);
  return 0;
}
