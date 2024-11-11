#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
const long long mod = 1e6 + 3;
const int maxn = 5e5 + 100;
char s[maxn];
int a[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int p = 1;
  for (int i = 1; i < n + 1; i++) {
    scanf("%s", s + p);
    p += m;
  }
  long long ans = 1;
  p = 1;
  for (int i = 1; i < n + 1; i++) {
    bool f = true;
    int pos = -1;
    for (int j = p; j < p + m; j++) {
      if (s[j] != '.') {
        f = false;
        break;
      }
    }
    if (f)
      ans = (ans * 2) % mod;
    else {
      for (int j = p; j < p + m; j++) {
        if (s[j] != '.') {
          pos = j - p + 1;
          int t = s[j] - '0';
          if (t == 1 || t == 2)
            a[j - p + 1] = 1;
          else
            a[j - p + 1] = -1;
        }
        a[j - p + 1] = 0;
      }
      for (int k = pos + 1; k < m; k++) {
        if (a[k]) {
          if (a[k] != -a[k - 1]) return 0 * puts("0");
        }
        a[k] = -a[k - 1];
      }
      for (int k = pos - 1; k >= 1; k--) {
        if (a[k]) {
          if (a[k] != -a[k + 1]) return 0 * puts("0");
        }
        a[k] = -a[k + 1];
      }
    }
    p = p + m;
  }
  for (int j = 1; j < m + 1; j++) {
    bool f = true;
    for (int i = j; i <= n * m; i += m) {
      if (s[i] != '.') {
        f = false;
        break;
      }
    }
    if (f)
      ans = (ans * 2) % mod;
    else {
      int pos = -1;
      int cnt = 0;
      for (int i = j; i <= n * m; i += m) {
        if (s[i] != '.') {
          ++cnt;
          pos = cnt;
          int t = s[i] - '0';
          if (t == 1 || t == 4)
            a[cnt] = 1;
          else
            a[cnt] = -1;
        } else
          a[++cnt] = 0;
      }
      for (int k = pos + 1; k < n; k++) {
        if (a[k]) {
          if (a[k] != -a[k - 1]) return 0 * puts("0");
        }
        a[k] = -a[k - 1];
      }
      for (int k = pos - 1; k >= 1; k--) {
        if (a[k]) {
          if (a[k] != -a[k + 1]) return 0 * puts("0");
        }
        a[k] = -a[k + 1];
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
