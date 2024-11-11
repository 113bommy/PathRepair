#include <bits/stdc++.h>
using namespace std;
int get() {
  char c;
  while (c = getchar(), (c < '0' || c > '9') && (c != '-'))
    ;
  bool flag = (c == '-');
  if (flag) c = getchar();
  int x = 0;
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - 48;
    c = getchar();
  }
  return flag ? -x : x;
}
void output(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  int len = 0, data[10];
  while (x) {
    data[len++] = x % 10;
    x /= 10;
  }
  if (!len) data[len++] = 0;
  while (len--) putchar(data[len] + 48);
  putchar('\n');
}
const int maxn = 100000;
const int mod = 1000000007;
const int base = 19961021;
long long h[maxn + 1];
bool flag[maxn];
int pos[maxn + 1], dp[maxn + 1], sum[maxn + 1];
int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  for (int i = h[0] = 0; i < n; i++) h[i + 1] = (h[i] * base + s[i]) % mod;
  long long tmp = 0, Pow = 1;
  for (int i = 0; i < m; i++) {
    tmp = (tmp * base + t[i]) % mod;
    Pow = Pow * base % mod;
  }
  for (int i = 0; i + m <= n; i++)
    flag[i] = (((h[i + m] - h[i] * Pow) % mod + mod) % mod == tmp);
  pos[n] = n;
  for (int i = n - 1; i >= 0; i--)
    if (flag[i])
      pos[i] = i;
    else
      pos[i] = pos[i + 1];
  dp[n] = sum[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (pos[i] == n)
      dp[i] = 1;
    else
      dp[i] = dp[i + 1] + sum[pos[i] + m];
    sum[i] = (dp[i] + sum[i + 1]) % mod;
  }
  dp[0] = (dp[0] + mod - 1) % mod;
  output(dp[0]);
  return 0;
}
