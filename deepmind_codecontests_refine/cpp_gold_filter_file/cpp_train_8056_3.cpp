#include <bits/stdc++.h>
template <class T>
inline bool rd(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
template <class T>
inline void pt(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) pt(x / 10);
  putchar(x % 10 + '0');
}
using namespace std;
const int N = 18;
string s;
int n;
int a[N << 1], siz[1 << N];
long long ten[N + 10];
long long dp[2][1 << N], d[2][1 << N], sum[2][N + 10], status[2][N + 10];
void go(int cur, int off) {
  dp[cur][0] = 0;
  for (int i = 1; i < (1 << n); i++)
    for (int j = 0; j < n; j++)
      if ((i & (1 << j)) > 0) {
        dp[cur][i] = dp[cur][i ^ (1 << j)] * 10 + a[n - 1 - j + off];
        break;
      }
  d[cur][(1 << n) - 1] = 0;
  for (int i = (1 << n) - 2; i >= 0; i--)
    for (int j = 0; j < n; j++)
      if ((i & (1 << j)) == 0) {
        d[cur][i] = d[cur][i ^ (1 << j)] * 10 + a[n - 1 - j + off];
        break;
      }
  if (cur == 0) {
    for (int i = 0; i < (1 << n); i++) {
      dp[cur][i] *= ten[n - siz[i]];
      d[cur][i] *= ten[siz[i]];
    }
  }
  for (int i = 0; i <= n; i++) sum[cur][i] = -1;
  for (int i = 0; i < (1 << n); i++)
    if (dp[cur][i] + d[cur][i] > sum[cur][siz[i]]) {
      sum[cur][siz[i]] = dp[cur][i] + d[cur][i];
      status[cur][siz[i]] = i;
    }
}
int main() {
  rd(n);
  cin >> s;
  for (int i = 0; i < (1 << n); i++) {
    int j = i;
    siz[i] = 0;
    while (j > 0) {
      siz[i]++;
      j &= j - 1;
    }
  }
  ten[0] = 1;
  for (int i = 1; i < N; i++) ten[i] = ten[i - 1] * 10;
  for (int i = 0; i < s.length(); i++) a[i] = s[i] - '0';
  go(0, 0);
  go(1, n);
  long long ans = -1;
  pair<long long, long long> p;
  for (int i = 0; i <= n; i++) {
    if (ans < sum[0][i] + sum[1][n - i]) {
      ans = sum[0][i] + sum[1][n - i];
      p = pair<long long, long long>(status[0][i], status[1][n - i]);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (p.first & (1LL << i))
      putchar('M');
    else
      putchar('H');
  }
  for (int i = n - 1; i >= 0; i--) {
    if (p.second & (1LL << i))
      putchar('M');
    else
      putchar('H');
  }
  puts("");
  return 0;
}
