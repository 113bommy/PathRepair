#include <bits/stdc++.h>
using namespace std;
void qmax(int &x, int y) {
  if (x < y) x = y;
}
void qmin(int &x, int y) {
  if (x > y) x = y;
}
inline int read() {
  char s;
  int k = 0, base = 1;
  while ((s = getchar()) != '-' && s != EOF && !(isdigit(s)))
    ;
  if (s == EOF) exit(0);
  if (s == '-') base = -1, s = getchar();
  while (isdigit(s)) k = k * 10 + (s ^ '0'), s = getchar();
  return k * base;
}
inline void write(long long x) {
  static char cnt, num[20];
  cnt = 0;
  if (!x) {
    putchar('0');
    return;
  }
  for (; x; x /= 10) num[++cnt] = x % 10;
  for (; cnt; putchar(num[cnt--] + 48))
    ;
}
const int maxn = 5e5 + 100;
char a[maxn], b[maxn];
int n, m, Next[maxn], cnt[2];
int main() {
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  for (int i = 1; i <= n; i++) {
    cnt[a[i] - '0']++;
  }
  int p = 0;
  for (int i = 2; i <= m; i++) {
    while (b[p + 1] != b[i] && p) p = Next[p];
    if (b[p + 1] == b[i]) {
      ++p;
      Next[i] = p;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (cnt[b[i] - '0']) {
      cnt[b[i] - '0']--;
      putchar(b[i]);
    } else
      break;
  }
  p = Next[m] + 1;
  while (true) {
    if (cnt[b[p] - '0'] > 0) {
      cnt[b[p] - '0']--;
      putchar(b[p]);
    } else
      break;
    p++;
    if (p > n) p = Next[m] + 1;
  }
  while (cnt[0]) {
    cnt[0]--;
    putchar('0');
  }
  while (cnt[1]) {
    cnt[1]--;
    putchar('1');
  }
  return 0;
}
