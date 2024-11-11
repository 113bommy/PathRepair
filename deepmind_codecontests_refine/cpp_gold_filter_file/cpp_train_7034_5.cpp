#include <bits/stdc++.h>
using namespace std;
template <typename T>
void get_int(T &x) {
  char t = getchar();
  bool neg = false;
  x = 0;
  for (; (t > '9' || t < '0') && t != '-'; t = getchar())
    ;
  if (t == '-') neg = true, t = getchar();
  for (; t <= '9' && t >= '0'; t = getchar()) x = x * 10 + t - '0';
  if (neg) x = -x;
}
template <typename T>
void print_int(T x) {
  if (x < 0) putchar('-'), x = -x;
  short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
const int inf = 0x3f3f3f3f;
const long long Linf = 1ll << 61;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
int n, a[300111], b[300111], m, mm;
long long d[10111];
char s[10111];
vector<int> dp[300111];
int getrem(int x) {
  int c = 0;
  for (int i = m - 1; i >= 0; i--) {
    d[i] += c * 10000ll;
    c = d[i] % x;
    d[i] /= x;
  }
  while (m != 0 && d[m - 1] == 0) m--;
  return c;
}
int main() {
  get_int(n);
  for (int i = 1; i < n; i++) get_int(a[i]);
  a[n] = 1000000000;
  for (int i = 1; i <= n; i++) get_int(b[i]);
  scanf("%s", s);
  m = strlen(s);
  for (int i = m - 1; i >= 0; i -= 4, mm++)
    for (int j = max(0, i - 3); j <= i; j++) d[mm] = d[mm] * 10 + s[j] - '0';
  m = mm;
  dp[1].push_back(1);
  for (int i = 1, rm; i <= n; i++) {
    if (a[i] != 1)
      rm = getrem(a[i]);
    else
      rm = 0;
    int sum = 0;
    for (int j = 0; j < (int)dp[i].size() + b[i]; j++) {
      if (j < (int)dp[i].size()) {
        sum += dp[i][j];
        if (sum >= mod) sum -= mod;
      }
      if (j > b[i]) {
        sum -= dp[i][j - b[i] - 1];
        if (sum < 0) sum += mod;
      }
      if (j % a[i] == rm) dp[i + 1].push_back(sum);
    }
  }
  if (m != 0)
    puts("0");
  else if (dp[n + 1].size() == 0)
    puts("0");
  else
    printf("%d\n", dp[n + 1][0]);
  return 0;
}
