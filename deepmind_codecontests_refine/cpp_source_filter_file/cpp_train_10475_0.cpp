#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, ans[205];
string s[205];
int work(int x) {
  for (int i = 1; i <= 10; ++i)
    for (int j = 0; j <= (1 << i) - 1; ++j) {
      string t;
      for (int k = 0; k <= i - 1; ++k) {
        if (j & (1 << k))
          t += '1';
        else
          t += '0';
      }
      if (s[x].find(t) == -1) return i - 1;
    }
  return 10;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) cin >> s[i];
  m = read();
  for (int i = 1; i <= n; ++i) ans[i] = work(i);
  for (int i = 1; i <= m; ++i) {
    int l = read(), r = read();
    s[n + i] = s[l] + s[r];
    ans[n + i] = max(work(n + i), max(ans[l], ans[r]));
    if (s[n + i].length() > 500)
      s[n + i] = s[n + i].substr(0, 250) +
                 s[n + i].substr(s[n + i].length() - 250, 250);
    printf("%d\n", ans[i + n]);
  }
}
