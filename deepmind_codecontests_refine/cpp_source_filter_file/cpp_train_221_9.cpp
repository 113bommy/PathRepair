#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 1e5 + 10, M = 300;
int n, q;
char s[N], a[4][M];
int dp[M][M][M], nxt[N][27], len[4];
void upd(int first) {
  for (int i = first == 3 ? len[1] : 0; i <= len[1]; ++i) {
    for (int j = first == 2 ? len[2] : 0; j <= len[2]; ++j) {
      for (int k = first == 1 ? len[3] : 0; k <= len[3]; ++k) {
        int &r = dp[i][j][k] = n + 2;
        if (i && dp[i - 1][j][k] + 1 <= n)
          r = min(r, nxt[dp[i - 1][j][k] + 1][a[1][i] - 'a']);
        if (j && dp[i][j - 1][k] + 1 <= n)
          r = min(r, nxt[dp[i][j - 1][k] + 1][a[2][j] - 'a']);
        if (k && dp[i][j][k - 1] + 1 <= n)
          r = min(r, nxt[dp[i][j][k - 1] + 1][a[3][k] - 'a']);
      }
    }
  }
}
int main() {
  scanf("%d%d%s", &n, &q, s + 1);
  for (int i = 'a'; i <= 'z'; ++i) {
    nxt[n + 1][i - 'a'] = n + 2;
    for (int j = n; j >= 1; --j) {
      if (s[j] == i)
        nxt[j][i - 'a'] = j;
      else
        nxt[j][i - 'a'] = nxt[j + 1][i - 'a'];
    }
  }
  for (int i = 1; i <= q; ++i) {
    char op, c;
    int first;
    scanf(" %c%d", &op, &first);
    if (op == '+') {
      scanf(" %c", &c);
      a[first][++len[first]] = c;
      upd(first);
    } else
      --len[first];
    puts(dp[len[1]][len[2]][len[3]] <= n ? "YES" : "NO");
  }
}
