#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
template <typename T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    write(x / 10);
  }
  putchar(x % 10 + '0');
}
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; };
long long ksm(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ((ans % mod) * (a % mod)) % mod;
    a = ((a % mod) * (a % mod)) % mod;
    n >>= 1;
  }
  return ans % mod;
}
const int maxn = 120;
char s1[maxn], s2[maxn], v[maxn];
int len1, len2, lenv;
int dp[maxn][maxn][maxn];
int NEXT[maxn];
struct Path {
  int a, b, c;
  Path(int aa = 0, int bb = 0, int cc = 0) { a = aa, b = bb, c = cc; }
} path[maxn][maxn][maxn];
inline void get_next() {
  int j = 0;
  for (register int i = 1; i <= lenv - 1; ++i) {
    while (j && v[i] != v[j]) j = NEXT[j - 1];
    if (v[j] == v[i]) j++;
    NEXT[i] = j;
  }
}
Path st;
inline bool solve1() {
  for (register int i = 1; i <= len1; ++i) {
    for (register int j = 1; j <= len2; ++j) {
      for (register int k = 0; k <= lenv - 1; ++k) {
        if (dp[i][j][k] < dp[i - 1][j][k]) {
          dp[i][j][k] = dp[i - 1][j][k];
          path[i][j][k] = Path(i - 1, j, k);
        }
        if (dp[i][j][k] < dp[i][j - 1][k]) {
          dp[i][j][k] = dp[i][j - 1][k];
          path[i][j][k] = Path(i, j - 1, k);
        }
        if (s1[i] == s2[j]) {
          int w = k;
          while (w && s1[i] != v[w]) w = NEXT[w - 1];
          if (s1[i] == v[w])
            w++;
          else
            w = 0;
          if (dp[i][j][w] < dp[i - 1][j - 1][k] + 1) {
            dp[i][j][w] = dp[i - 1][j - 1][k] + 1;
            path[i][j][w] = Path(i - 1, j - 1, k);
          }
        }
      }
    }
  }
  int ma = 0;
  for (register int i = 0; i <= lenv - 2; ++i) {
    if (ma < dp[len1][len2][i]) {
      ma = dp[len1][len2][i];
      st = Path(len1, len2, i);
    }
  }
  return ma != 0;
}
void print_path(int a, int b, int c) {
  if (a == 0 && b == 0 && c == 0) return;
  Path nxt = path[a][b][c];
  print_path(nxt.a, nxt.b, nxt.c);
  if (dp[a][b][c] == dp[nxt.a][nxt.b][nxt.c] + 1) {
    putchar(s1[a]);
  }
}
int main() {
  scanf("%s", s1 + 1);
  len1 = strlen(s1 + 1);
  scanf("%s", s2 + 1);
  len2 = strlen(s2 + 1);
  scanf("%s", v);
  lenv = strlen(v);
  get_next();
  if (!solve1()) {
    puts("0");
  } else {
    print_path(st.a, st.b, st.c);
  }
  return 0;
}
