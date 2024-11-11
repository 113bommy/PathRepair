#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
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
void read(long long &x) {
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
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
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
void writell(long long x) {
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
inline long long inc(int &x) { return ++x; }
inline long long inc(long long &x) { return ++x; }
inline long long inc(int &x, long long y) { return x += y; }
inline long long inc(long long &x, long long y) { return x += y; }
inline double inc(double &x, double y) { return x += y; }
inline long long dec(int &x) { return --x; }
inline long long dec(long long &x) { return --x; }
inline long long dec(int &x, long long y) { return x -= y; }
inline long long dec(long long &x, long long y) { return x -= y; }
inline double dec(double &x, double y) { return x -= y; }
inline long long mul(int &x) { return x = ((long long)x) * x; }
inline long long mul(long long &x) { return x = x * x; }
inline long long mul(int &x, long long y) { return x *= y; }
inline long long mul(long long &x, long long y) { return x *= y; }
inline double mul(double &x, double y) { return x *= y; }
inline long long divi(const int &x) {
  long long ans, l, r, mid;
  ans = 0;
  l = 0;
  r = 0x3fffffff;
  while (l < r) {
    mid = (l + r) / 2;
    if (mid * mid <= x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid;
  }
  return ans;
}
inline long long divi(const long long &x) {
  long long ans, l, r, mid;
  ans = 0;
  l = 0;
  r = 0x3fffffff;
  while (l < r) {
    mid = (l + r) / 2;
    if (mid * mid <= x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid;
  }
  return ans;
}
inline long long divi(int &x, long long y) { return x /= y; }
inline long long divi(long long &x, long long y) { return x /= y; }
inline double divi(double &x, double y) { return x /= y; }
inline long long mod(int &x, long long y) { return x %= y; }
inline long long mod(long long &x, long long y) { return x %= y; }
int n, m, i, j, a[55], b[55];
double p[55], dp[55][5205], l, r, mid;
bool check(double x) {
  int i, j;
  if ((0) <= (n))
    for ((i) = (0); (i) <= (n); (i)++) {
      if ((0) <= (5200))
        for ((j) = (0); (j) <= (5200); (j)++) dp[i][j] = x;
    }
  if ((0) <= (m))
    for ((i) = (0); (i) <= (m); (i)++) dp[n][i] = 0;
  for (i = n - 1; i >= 0; i--) {
    for (j = m; j >= 0; j--) {
      {
        dp[i][j] =
            min(dp[i][j],
                (a[i + 1] + dp[i + 1][j + a[i + 1]]) * p[i + 1] +
                    (b[i + 1] + dp[i + 1][j + b[i + 1]]) * (1 - p[i + 1]));
      }
    }
    for (j = 1; j <= m; j++) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
  }
  return dp[0][0] < mid;
}
int main() {
  double st = clock();
  cin >> n >> m;
  if ((1) <= ((n)))
    for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
      cin >> a[i] >> b[i] >> p[i];
      p[i] /= 100.0;
    }
  l = 0;
  r = 1e15;
  while ((clock() - st) < 1900) {
    mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else
      l = mid;
  }
  printf("%.20f\n", mid);
  return 0;
}
