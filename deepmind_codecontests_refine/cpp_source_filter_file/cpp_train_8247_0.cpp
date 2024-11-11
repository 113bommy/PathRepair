#include <bits/stdc++.h>
using namespace std;
const int N = 2010, M = 1000010, P = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int INF = 0xcfcfcfcf;
const double eps = 1e-9, pi = asin(1) * 2;
inline long long read();
inline int ADD(int a, int b) { return a + b >= P ? a + b - P : a + b; }
inline int MINUS(int a, int b) { return a - b < 0 ? a - b + P : a - b; }
int n, k;
char s[N];
int a[N];
int dp[N][N];
int b[N][N];
int bit[N];
int num[10], mi[10];
inline void init() {
  for (int i = 1; i < (1 << 7); i++) bit[i] = bit[i >> 1] + (i & 1);
  for (int i = 1; i <= 7; i++) mi[i] = 1 << i - 1;
  num[0] = mi[1] + mi[2] + mi[3] + mi[5] + mi[6] + mi[7];
  num[1] = mi[3] + mi[6];
  num[2] = mi[1] + mi[3] + mi[4] + mi[5] + mi[7];
  num[3] = mi[1] + mi[3] + mi[4] + mi[6] + mi[7];
  num[4] = mi[2] + mi[3] + mi[4] + mi[6];
  num[5] = mi[1] + mi[2] + mi[4] + mi[6] + mi[7];
  num[6] = mi[1] + mi[2] + mi[4] + mi[5] + mi[6] + mi[7];
  num[7] = mi[1] + mi[3] + mi[6];
  num[8] = mi[1] + mi[2] + mi[3] + mi[4] + mi[5] + mi[6] + mi[7];
  num[9] = mi[1] + mi[2] + mi[3] + mi[4] + mi[6] + mi[7];
}
inline long long read() {
  long long s = 0;
  bool flag = false;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') flag = true;
  for (; '0' <= ch && ch <= '9'; ch = getchar())
    s = (s << 3) + (s << 1) + (ch ^ '0');
  if (flag) return -s;
  return s;
}
int main() {
  init();
  n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= 7; j++) a[i] += (s[j] - '0') * mi[j];
  }
  dp[n + 1][0] = 1;
  for (int i = n; i; i--) {
    for (int j = 0; j <= k; j++) {
      for (int l = 9; l >= 0; l--) {
        if (j - bit[num[l]] + bit[a[i]] < 0 || ((a[i] & num[l]) != a[i]))
          continue;
        if (dp[i + 1][j - bit[num[l]] + bit[a[i]]]) {
          dp[i][j] = 1, b[i][j] = l;
          break;
        }
      }
    }
  }
  if (!dp[n][k])
    printf("-1\n");
  else {
    for (int i = 1; i <= n; i++) {
      putchar(b[i][k] + '0');
      k -= bit[num[b[i][k]]] - bit[a[i]];
    }
    putchar('\n');
  }
  return 0;
}
