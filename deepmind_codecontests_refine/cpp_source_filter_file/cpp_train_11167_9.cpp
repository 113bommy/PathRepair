#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int T, n, k, a[maxn];
inline int read() {
  int res = 0, f_f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f_f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    res = (res << 3) + (res << 1) + (ch - '0'), ch = getchar();
  return res * f_f;
}
int main() {
  T = read();
  while (T--) {
    n = read(), k = read();
    bool flag = true;
    if (k & 1) flag = false;
    for (int i = 1; i <= n; i++) {
      char ch = getchar();
      while (ch != '0' && ch != '1' & ch != '?') ch = getchar();
      if (ch == '0') a[i] = 0;
      if (ch == '1') a[i] = 1;
      if (ch == '?') a[i] = -1;
      if (a[i] > k) {
        if (a[i] == -1)
          a[i] = a[i - 1];
        else if (a[i - k] != -1 && a[i - k] != a[i])
          flag = false;
      }
    }
    for (int i = n; i; i--) {
      if (a[i + k] <= n && a[i] == -1) a[i] = a[i + k];
    }
    if (flag) {
      int aa = 0, bb = 0, cc = 0;
      for (int i = 1; i <= k; i++) {
        if (a[i] == 0) aa++;
        if (a[i] == 1) bb++;
        if (a[i] == -1) cc++;
      }
      if (min(aa, bb) + cc < max(aa, bb)) flag = false;
    }
    if (!flag)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
