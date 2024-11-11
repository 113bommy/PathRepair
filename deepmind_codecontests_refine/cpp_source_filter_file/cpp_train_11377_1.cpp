#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, ff = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - 48, ch = getchar();
  return sum * ff;
}
void write(long long x) {
  if (x < 0) x = ~(x - 1), putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
void writesp(long long x) { write(x), putchar(' '); }
void writeln(long long x) { write(x), puts(""); }
const int N = 5e5 + 7;
int n, ans, siz, sum, f[N];
char s[N];
int main() {
  n = read();
  cin >> s + 1;
  for (register int i = 1; i <= n; ++i) f[i] = n + 1;
  for (register int i = n; i >= 1; --i) {
    if (s[i] - '0')
      ++siz, sum += f[siz] - i;
    else
      while (siz) f[siz] = i + siz, --siz;
    ans += sum;
  }
  write(ans);
  return 0;
}
