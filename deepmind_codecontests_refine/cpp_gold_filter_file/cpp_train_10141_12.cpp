#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar(), w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * w;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
const int N = 2000000;
int n;
char s[N];
int b[N], tot;
int main() {
  cin >> (s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i)
    if (s[i] != s[i - 1])
      b[++tot] = 1;
    else
      b[tot] = 0;
  if (s[1] == s[n]) b[1] = 0, --tot;
  int sum = 0, ans = 0;
  for (int i = 1; i <= tot; ++i)
    if (b[i])
      ++sum;
    else
      ans += sum / 2 + 1, sum = 0;
  ans += sum / 2;
  writeln(ans);
  return 0;
}
