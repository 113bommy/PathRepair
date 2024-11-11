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
unsigned long long e = 1e6 + 3, pw[500005], calc[500005];
string st;
int n, m, i, j, dp[500005], ans;
char ss[500005];
set<unsigned long long> s[500005];
unsigned long long itcalc(int x, int y) {
  return calc[y] - calc[x - 1] * pw[y - x + 1];
}
bool check(int x) {
  return s[dp[x] - 1].count(itcalc(x, x + dp[x] - 2)) ||
         s[dp[x] - 1].count(itcalc(x + 1, x + dp[x] - 1));
}
int main() {
  scanf("%d %s", &n, ss);
  st = ss;
  st = " " + st;
  pw[0] = 1;
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    pw[i] = pw[i - 1] * e;
    calc[i] = calc[i - 1] * e + st[i];
  }
  for (((i)) = ((n)); ((i)) >= (1); ((i))--) {
    dp[i] = dp[i + 1] + 1;
    while (dp[i] > 1 && !check(i)) {
      dp[i]--;
      for (((j)) = ((dp[i + dp[i]])); ((j)) >= (1); ((j))--) {
        if (s[j].count(itcalc(i + dp[i], i + dp[i] + j - 1))) break;
        s[j].insert(itcalc(i + dp[i], i + dp[i] + j - 1));
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
