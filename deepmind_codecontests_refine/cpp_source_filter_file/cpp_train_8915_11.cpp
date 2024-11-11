#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long LLinf = 0x3f3f3f3f3f3f3f3f;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10ll + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int maxn = 200000 + 10;
int n;
int a[maxn], b;
int f[maxn][2];
int l, r, mid, pre;
int res;
void build() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  memset(f, 0x3f, sizeof(f));
  f[1][0] = -inf;
  for (int i = 1; i <= n; i++) {
    b = a[i] - i + 1;
    l = 1;
    r = n;
    while (l < r) {
      mid = (l + r) / 2;
      if (b < f[mid][1])
        r = mid;
      else
        l = mid + 1;
    }
    f[l][1] = b;
    res = max(res, l);
    f[pre][1] = min(f[pre][1], f[pre][0]);
    res = max(res, pre);
    b = a[i] - i;
    l = 1;
    r = n;
    while (l < r) {
      mid = (l + r) / 2;
      if (b < f[mid][0])
        r = mid;
      else
        l = mid + 1;
    }
    pre = l;
    f[l][0] = b;
  }
  printf("%d\n", max(0, n - res - 1));
}
void solve() {}
int main() {
  build();
  solve();
  return 0;
}
