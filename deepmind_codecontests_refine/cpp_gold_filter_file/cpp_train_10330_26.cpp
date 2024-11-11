#include <bits/stdc++.h>
using namespace std;
const int N = 410;
int q, f[2][N][N];
char s[N], t[N];
template <class T>
inline void read(T &x) {
  x = 0;
  char ch = getchar(), w = 0;
  while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = w ? -x : x;
  return;
}
int main() {
  read(q);
  while (q--) {
    scanf("%s%s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    memset(f, 0xc0, sizeof(f));
    for (register int i = 1; i <= m; ++i) f[0][0][i] = 0;
    for (register int i = 1; i <= n; ++i) {
      for (register int j = 0, w = i & 1; j <= min(i, m); ++j)
        for (register int k = j; k <= m; ++k) {
          f[w][j][k] = f[w ^ 1][j][k];
          if (f[w][j][k] >= 0 && s[i] == t[k + f[w][j][k]]) ++f[w][j][k];
          if (s[i] == t[j]) f[w][j][k] = max(f[w][j][k], f[w ^ 1][j - 1][k]);
        }
    }
    int flag = 0;
    for (register int i = 0; i <= m; ++i)
      if (f[n & 1][i][i + 1] >= m - i) flag = 1;
    printf("%s\n", flag ? "YES" : "NO");
  }
  return 0;
}
