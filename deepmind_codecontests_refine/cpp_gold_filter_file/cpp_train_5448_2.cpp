#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int a[maxn << 1], b[maxn];
int num[maxn << 1], p[maxn];
int n, m;
int bin(int l, int r, int pos) {
  int ret = l - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (p[a[mid]] < pos) {
      ret = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ret;
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      a[n + i] = a[i];
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
      p[b[i]] = i;
    }
    num[n << 1 + 1] = 0;
    for (int i = n << 1; i >= 1; --i) {
      if (p[a[i]] == 0)
        num[i] = 0;
      else if (num[i + 1] == 0 || p[a[i]] >= p[a[i + 1]])
        num[i] = 1;
      else
        num[i] = num[i + 1] + 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
      if (num[i]) {
        int j = i + num[i];
        int t = num[i] + bin(j, j + num[j] - 1, p[a[i]]) - j + 1;
        if (t > ans) ans = t;
      }
    printf("%d\n", ans);
  }
  return 0;
}
