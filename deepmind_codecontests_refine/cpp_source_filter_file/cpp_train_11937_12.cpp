#include <bits/stdc++.h>
using namespace std;
void qmax(int &x, int y) {
  if (x < y) x = y;
}
void qmin(long long &x, long long y) {
  if (x > y) x = y;
}
inline long long read() {
  char s;
  long long k = 0, base = 1;
  while ((s = getchar()) != '-' && s != EOF && !(isdigit(s)))
    ;
  if (s == EOF) exit(0);
  if (s == '-') base = -1, s = getchar();
  while (isdigit(s)) {
    k = k * 10 + (s ^ '0');
    s = getchar();
  }
  return k * base;
}
inline void write(int x) {
  static char cnt, num[15];
  cnt = 0;
  if (!x) {
    putchar('0');
    return;
  }
  for (; x; x /= 10) num[++cnt] = x % 10;
  for (; cnt; putchar(num[cnt--] + 48))
    ;
}
const int maxn = 1e3 + 20;
int n;
char ch[maxn][maxn], s1, s2;
void work() {
  s1 = 0;
  s2 = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (ch[i][j] == '0' && (i + j) % 2 == 0)
        s1++;
      else if (ch[i][j] == '1' && (i + j) % 2 == 1)
        s1++;
      else
        s2++;
    }
}
int x[5], y[5];
long long ans;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) scanf("%s", ch[i] + 1);
  work();
  x[1] = s1;
  y[1] = s2;
  for (int i = 1; i <= n; i++) scanf("%s", ch[i] + 1);
  work();
  x[2] = s1;
  y[2] = s2;
  for (int i = 1; i <= n; i++) scanf("%s", ch[i] + 1);
  work();
  x[3] = s1;
  y[3] = s2;
  for (int i = 1; i <= n; i++) scanf("%s", ch[i] + 1);
  work();
  x[4] = s1;
  y[4] = s2;
  if (n % 2 == 1) {
    for (int i = 1; i <= 4; i++) y[i] -= x[i];
    ans = x[1] + x[2] + x[3] + x[4];
    sort(y + 1, y + 5);
    ans = ans + y[1] + y[2];
  } else {
    ans = min(x[1] + x[2] + x[3] + x[4], y[1] + y[2] + y[3] + y[4]);
  }
  cout << ans;
  return 0;
}
