#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000007;
inline int IN() {
  char ch;
  (ch = getchar());
  int f = 0, x = 0;
  for (; ((ch) == '\n' || (ch) == '\r' || (ch) == '\t' || (ch) == ' ');
       (ch = getchar()))
    ;
  if (ch == '-') f = 1, (ch = getchar());
  for (; !((ch) == '\n' || (ch) == '\r' || (ch) == '\t' || (ch) == ' ');
       (ch = getchar()))
    x = x * 10 + ch - '0';
  return (f) ? (-x) : (x);
}
int sm = 'a', bg = 'z', n, f[2005][2005], K;
char st[2005];
int large(char x) { return bg - x; }
int small(char x) { return x - sm; }
int main() {
  scanf("%d%d", &n, &K);
  scanf("%s", st + 1);
  f[0][0] = 1;
  int ans = 0;
  for (int j = (int)0; j <= (int)K; j++) {
    int sum = f[0][j];
    for (int i = (int)1; i <= (int)n; i++) {
      f[i][j] = (f[i][j] + 1ll * sum * small(st[i])) % mo;
      sum = (sum + f[i][j]) % mo;
    }
    for (int i = (int)1; i <= (int)n; i++) {
      for (int k = (int)1; k <= (int)i; k++) {
        int cost = (n - i + 1) * k;
        if (cost + j > K) break;
        f[i][cost + j] =
            (f[i][cost + j] + 1ll * f[i - k][j] * large(st[i])) % mo;
      }
    }
  }
  for (int i = (int)1; i <= (int)n; i++) ans = (ans + f[i][K]) % mo;
  printf("%d\n", ans);
  return 0;
}
