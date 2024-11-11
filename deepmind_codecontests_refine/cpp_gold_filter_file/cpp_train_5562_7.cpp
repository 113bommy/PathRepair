#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
inline void writes(string s) { puts(s.c_str()); }
inline void writeln() { writes(""); }
inline void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
long long n, m, i, j, dp[35][35][2], lys = 1e9 + 7, ans;
vector<long long> dig;
int main() {
  cin >> n;
  long long t = n;
  dig.push_back(0);
  while (t) {
    dig.push_back(t & 1);
    t >>= 1;
  }
  n = dig.size() - 1;
  dp[n][0][1] = 1;
  for (i = n; i; i--) {
    for (j = n - i; j >= 0; j--) {
      int x = (j ? (1 << (j - 1)) : 1), y = (1 << j) - x;
      (dp[i - 1][j][0] += dp[i][j][0] * (x + y)) %= lys;
      (dp[i - 1][j + 1][0] += dp[i][j][0]) %= lys;
      if (dig[i]) {
        (dp[i - 1][j][0] += dp[i][j][1] * x) %= lys;
        (dp[i - 1][j][1] += dp[i][j][1] * y) %= lys;
        (dp[i - 1][j + 1][1] += dp[i][j][1]) %= lys;
      } else
        (dp[i - 1][j][1] += dp[i][j][1] * x) %= lys;
    }
  }
  for ((i) = (0); (i) <= (n); (i)++) (ans += dp[0][i][0] + dp[0][i][1]) %= lys;
  cout << ans << endl;
  return 0;
}
