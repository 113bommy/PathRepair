#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int ans = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = (ans << 1) + (ans << 3) + c - '0';
    c = getchar();
  }
  return ans * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x / 10) write(x / 10);
  putchar((char)(x % 10) + '0');
}
template <typename T>
inline T Abs(T a) {
  return a > 0 ? a : -a;
};
template <typename T, typename TT>
inline T Min(T a, TT b) {
  return a < b ? a : b;
}
template <typename T, typename TT>
inline T Max(T a, TT b) {
  return a < b ? b : a;
}
const int N = 1e4 + 5;
int t, n, m, a[N], c[N], ans;
char s[15][N];
pair<int, int> b[N];
signed main() {
  t = read();
  while (t--) {
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    ans = -1e9;
    for (int i = 0; i < (1 << n); ++i) {
      for (int j = 1; j <= m; ++j) {
        b[j] = make_pair(0, j);
        for (int k = 1; k <= n; ++k)
          if (s[k][j] == '1') {
            if ((i >> (k - 1)) & 1)
              b[j].first++;
            else
              b[j].first--;
          }
      }
      sort(b + 1, b + 1 + m);
      int tmp = 0;
      for (int j = 1; j <= n; ++j)
        if ((i >> (j - 1)) & 1)
          tmp -= a[j];
        else
          tmp += a[j];
      for (int j = 1; j <= m; ++j) tmp += j * b[j].first;
      if (tmp > ans) {
        ans = tmp;
        for (int j = 1; j <= m; ++j) c[b[j].second] = j;
      }
    }
    for (int i = 1; i <= m; ++i) write(c[i]), putchar(' ');
    puts("");
  }
  return 0;
}
