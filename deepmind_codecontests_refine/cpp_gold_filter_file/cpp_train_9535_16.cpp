#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int maxn = 1e6 + 1e2;
int n;
int a[maxn];
int ji, ou;
int ans[maxn];
int mx;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), mx = max(mx, a[i]);
  if (n & 1) {
    int mid = n >> 1;
    mid++;
    for (int k = 0; k <= n - 2; k++) {
      if (k >= 2) ans[k] = max(ans[k], ans[k - 2]);
      if (k % 2 == 0) {
        int kk = k / 2;
        if (mid - kk - 1 >= 1)
          ans[k] = max(ans[k],
                       min(a[max(mid - kk, 0)], max(a[max(mid - kk - 1, 0)],
                                                    a[max(mid - kk + 1, 0)])));
        if (mid + kk + 1 <= n)
          ans[k] = max(ans[k], min(a[min(mid + kk, n + 1)],
                                   max(a[min(mid + kk + 1, n + 1)],
                                       a[min(mid + kk - 1, n + 1)])));
      } else {
        int kk = (k + 1) / 2;
        if (mid - kk >= 1)
          ans[k] =
              max(ans[k], max(a[max(mid - kk, 0)], a[max(0, mid - kk + 1)]));
        kk--;
        if (mid + kk + 1 <= n)
          ans[k] = max(ans[k], max(a[min(mid + kk, n + 1)],
                                   a[min(n + 1, mid + kk + 1)]));
      }
    }
  } else {
    int mid = n >> 1;
    for (int k = 0; k <= n - 2; k++) {
      if (k >= 2) ans[k] = max(ans[k], ans[k - 2]);
      if (k % 2 == 0) {
        int kk = k / 2;
        if (mid - kk >= 1)
          ans[k] =
              max(ans[k], max(a[max(mid - kk, 0)], a[max(0, mid - kk + 1)]));
        if (mid + kk + 1 <= n)
          ans[k] = max(ans[k], max(a[min(mid + kk, n + 1)],
                                   a[min(n + 1, mid + kk + 1)]));
      } else {
        int kk = k / 2;
        if (mid - kk - 1 >= 1)
          ans[k] = max(ans[k],
                       min(a[max(mid - kk, 0)], max(a[max(mid - kk - 1, 0)],
                                                    a[max(mid - kk + 1, 0)])));
        kk++;
        if (mid + kk + 1 <= n)
          ans[k] = max(ans[k], min(a[min(mid + kk, n + 1)],
                                   max(a[min(mid + kk + 1, n + 1)],
                                       a[min(mid + kk - 1, n + 1)])));
      }
    }
  }
  for (int i = 0; i <= n - 2; i++) cout << ans[i] << " ";
  cout << mx;
  cout << endl;
  return 0;
}
