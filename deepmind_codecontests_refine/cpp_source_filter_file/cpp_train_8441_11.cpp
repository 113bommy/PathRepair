#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char zf = 1;
  char ch = getchar();
  while (ch != '-' && !isdigit(ch)) ch = getchar();
  if (ch == '-') zf = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * zf;
}
void write(long long y) {
  if (y < 0) putchar('-'), y = -y;
  if (y > 9) write(y / 10);
  putchar(y % 10 + 48);
}
void writeln(const long long y) {
  write(y);
  putchar('\n');
}
int i, j, k, m, n, cnt;
const double PI = acos(-1.0);
struct node {
  int x, y;
} a[3030];
double b[3030];
int main() {
  n = read();
  for (register int i = 1; i <= n; i++) a[i].x = read(), a[i].y = read();
  unsigned long long ans = 0;
  for (register int i = 1; i <= n; i++) {
    cnt = 0;
    for (register int j = 1; j <= n; j++)
      if (i != j) b[++cnt] = atan2(a[j].x - a[i].x, a[j].y - a[i].y);
    sort(b + 1, b + cnt + 1);
    for (register int i = cnt + 1; i <= 2 * cnt; i++)
      b[i] = b[i - cnt] + PI * 2;
    for (register int j = k = 1; j <= cnt; j++) {
      if (k < j) k = j;
      while (k < cnt * 2 && b[k + 1] - b[j] < PI) k++;
      int sum = k - j, sum2 = cnt - sum - 1;
      ans += (unsigned long long)sum * (sum - 1) * sum2 * (sum2 - 1) / 4;
    }
  }
  cout << ans / 2;
  return 0;
}
