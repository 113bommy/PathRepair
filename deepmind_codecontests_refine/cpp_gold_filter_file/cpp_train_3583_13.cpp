#include <bits/stdc++.h>
using namespace std;
void open() {
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
}
void close() {
  fclose(stdin);
  fclose(stdout);
}
inline int Readint() {
  int ret = 0;
  int f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f *= -1;
  } while (ch >= 0 && (ch < '0' || ch > '9'));
  while ('0' <= ch && ch <= '9') {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * f;
}
const int MAXN = 120;
const int STA = 1 << 21;
int n, m;
int s[MAXN];
int dp[STA];
int p[MAXN];
int t[MAXN] = {0};
void init() {
  n = Readint();
  for (int i = 0, _END_ = n - 1; i <= _END_; i++) s[i] = Readint();
  sort(s, s + n, greater<int>());
  char op[MAXN];
  m = Readint();
  for (int i = 0, _END_ = m - 1; i <= _END_; i++) {
    scanf("%s", op);
    t[i] = Readint();
    p[i] = op[0] == 'p';
  }
}
int hamming_weight(int x) {
  int cnt = 0;
  while (x) {
    cnt++;
    x -= ((x) & (-(x)));
  }
  return cnt;
}
void work() {
  int d;
  int x;
  for (int i = 1, _END_ = (1 << m) - 1; i <= _END_; i++) {
    dp[i] = -1e9;
    x = m - hamming_weight(i);
    for (int j = 0, _END_ = m - 1; j <= _END_; j++)
      if (i & 1 << j) {
        if (t[x] != t[x + 1])
          dp[i] = max(dp[i], -dp[i ^ 1 << j] + p[x] * s[j]);
        else
          dp[i] = max(dp[i], dp[i ^ 1 << j] + p[x] * s[j]);
      }
  }
  if (t[0] == 1)
    printf("%d\n", dp[(1 << m) - 1]);
  else
    printf("%d\n", -dp[(1 << m) - 1]);
}
int main() {
  int _ = 0;
  init();
  work();
  close();
  return 0;
}
