#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 23;
long long n, m, T;
int f[2][403][403];
char s[maxn], t[maxn];
int main() {
  cin >> T;
  while (T--) {
    scanf("%s%s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    memset(f, 0x80, sizeof(f));
    for (int i = 0; i <= m; i++) f[1][0][i] = 0;
    int now = 0, pre = 1;
    for (int i = 1; i <= n; i++, now ^= 1, pre ^= 1) {
      for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) f[now][i][j] = f[pre][i][j];
      }
      for (int j = 1; j <= m; j++) {
        if (s[i] == t[j]) {
          for (int k = m; k >= 1; k--) {
            f[now][k][j] = max(f[now][k][j], f[pre][k][j - 1] + 1);
            f[now][j][k] = max(f[now][j][k], f[pre][j - 1][k] + 1);
          }
        }
      }
    }
    bool flag = false;
    for (int i = 0; i <= m; i++) flag |= f[pre][i][m] == m;
    printf("%s\n", flag ? "YES" : "NO");
  }
}
