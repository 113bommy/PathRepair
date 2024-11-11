#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  int ch = getchar(), f = 1;
  long long x = 0;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return f * x;
}
int solve();
int main() {
  for (int t = read(); t--; solve())
    ;
  return 0;
}
char ans[105][105];
int solve() {
  int n = read(), m = read(), k = read();
  int flag = 0;
  if (m % 2) swap(n, m), k = n * m / 2 - k, flag = 1;
  if (n % 2 == 0)
    if (k % 2)
      return puts("no") & 0;
    else
      ;
  else if (k * 2 < m)
    return puts("no") & 0;
  else if (((k - m / 2) % 2) == 1)
    return puts("no") & 0;
  puts("yes");
  if (n % 2 == 0) {
    for (int i = 1; i <= n; i += 2) {
      for (int j = 1; j <= m; j += 2) {
        if (k)
          ans[i][j] = ans[i][j + 1] = (i + j) % 26 + 'a',
          ans[i + 1][j] = ans[i + 1][j + 1] = (i + j + 10) % 26 + 'a', k -= 2;
        else
          ans[i][j] = ans[i + 1][j] = (i + j) % 26 + 'a',
          ans[i][j + 1] = ans[i + 1][j + 1] = (i + j + 10) % 26 + 'a';
      }
    }
  } else {
    for (int j = 1; j <= m; j += 2)
      ans[1][j] = ans[1][j + 1] = (j + 20) % 26 + 'a';
    k -= m / 2;
    for (int i = 2; i <= n; i += 2) {
      for (int j = 1; j <= m; j += 2) {
        if (k)
          ans[i][j] = ans[i][j + 1] = (i + j) % 26 + 'a',
          ans[i + 1][j] = ans[i + 1][j + 1] = (i + j + 13) % 26 + 'a', k -= 2;
        else
          ans[i][j] = ans[i + 1][j] = (i + j) % 26 + 'a',
          ans[i][j + 1] = ans[i + 1][j + 1] = (i + j + 10) % 26 + 'a';
      }
    }
  }
  if (!flag)
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cout << ans[i][j];
      }
      cout << endl;
    }
  else {
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        cout << ans[j][i];
      }
      cout << endl;
    }
  }
}
