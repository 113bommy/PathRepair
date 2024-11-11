#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
const int infi = 1e9 + 7;
const long long infl = 1e18;
const double eps = 1e-7;
inline int readChar();
inline void writeChar(int x);
inline void writeWord(const char *s);
inline void flush();
static const int buf_size = 4096;
inline int getChar() {
  static char buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len) pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len) return -1;
  return buf[pos++];
}
inline int readChar() {
  int c = getChar();
  while (c >= 0 && c <= 32) c = getChar();
  return c;
}
inline int readWord(char *bf) {
  char *cur = bf;
  *cur = getChar();
  while (*cur <= 32) *cur = getChar();
  while (*cur > 32) {
    ++cur;
    *cur = getChar();
  }
  return cur - bf;
}
inline int readInt() {
  int s = 1, c = readChar();
  int x = 0;
  if (c == '-') s = -1, c = getChar();
  while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}
static int write_pos = 0;
static char write_buf[buf_size];
inline void writeChar(int x) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
}
inline void flush() {
  if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
}
inline void writeInt(long long x) {
  if (x < 0) writeChar('-'), x = -x;
  char s[24];
  int n = 0;
  while (x || !n) s[n++] = '0' + x % 10, x /= 10;
  while (n--) writeChar(s[n]);
}
inline void writeWord(const char *s) {
  while (*s) writeChar(*s++);
}
double dp[50][200500];
double opt[50][200500];
long long sum_s[200500];
double sum_add[200500];
double sum_dr[200500];
int ar[200500];
inline double get_add(int l, int r) {
  double ans = sum_add[r];
  if (l) {
    ans -= sum_add[l - 1];
    ans -= (sum_dr[r] - sum_dr[l - 1]) * (double)sum_s[l - 1];
  }
  return ans;
}
inline void calc_dp(int k, int pos, int l_ans, int r_ans) {
  r_ans = min(r_ans, pos);
  double d;
  int op;
  d = dp[k - 1][pos];
  op = opt[k - 1][pos];
  for (int i = l_ans; i < r_ans; ++i) {
    double q = dp[k - 1][i] + get_add(i + 1, pos);
    if (q < d) {
      d = q;
      op = i;
    }
  }
  dp[k][pos] = d;
  opt[k][pos] = op;
  return;
}
inline void din(int k, int l, int r, int l_ans, int r_ans) {
  if (r < 0 || l > r) return;
  int m = (l + r) >> 1;
  calc_dp(k, m, l_ans, r_ans);
  din(k, l, m - 1, l_ans, opt[k][m]);
  din(k, m + 1, r, opt[k][m], r_ans);
  return;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &ar[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (i)
      sum_s[i] = sum_s[i - 1], sum_dr[i] = sum_dr[i - 1],
      sum_add[i] = sum_add[i - 1];
    sum_s[i] += (long long)ar[i];
    sum_dr[i] += (double)1.0 / (double)ar[i];
    sum_add[i] += (double)sum_s[i] / (double)ar[i];
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      opt[i][j] = -1;
      dp[i][j] = -1;
    }
  }
  for (int i = 0; i < n; ++i) {
    dp[0][i] = sum_add[i];
  }
  for (int i = 1; i < k; ++i) {
    din(i, 0, n - 1, 0, n - 1);
  }
  printf("%.20lf", dp[k - 1][n - 1]);
  return 0;
}
