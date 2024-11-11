#include <bits/stdc++.h>
using namespace std;
char buf[25];
const int maxn = 100010;
int b[maxn];
int a[1 << 6], cnt[6], c[1 << 6];
int n, m;
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return f ? -x : x;
}
void write(int x) {
  if (!x) {
    putchar('0');
    return;
  }
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  int cnt = 0;
  while (x) {
    buf[++cnt] = '0' + x % 10;
    x /= 10;
  }
  for (int i = cnt; i >= 1; --i) putchar(buf[i]);
}
void init() {
  char ch = getchar();
  while (ch >= 'a' && ch <= 'f') {
    ++n;
    ++cnt[ch - 'a'];
    ch = getchar();
  }
  for (int i = 0; i <= 5; ++i)
    for (int j = 1; j <= (1 << 6) - 1; ++j)
      if ((1 << i) & j) a[j] += cnt[i];
}
bool pd() {
  for (int j = 1; j <= (1 << 6) - 1; ++j)
    if (a[j] > c[j]) return false;
  return true;
}
int main() {
  init();
  m = read();
  for (int i = 1; i <= n; ++i) b[i] = (1 << 6) - 1;
  for (int i = 1; i <= m; ++i) {
    int x = read();
    char ch = getchar();
    b[x] = 0;
    while (ch < 'a' || ch > 'f') ch = getchar();
    while (ch >= 'a' && ch <= 'f') {
      b[x] |= 1 << (ch - 'a');
      ch = getchar();
    }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= (1 << 6) - 1; ++j)
      if (b[i] & j) ++c[j];
  if (!pd()) {
    puts("Impossible");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= (1 << 6) - 1; ++j)
      if (b[i] & j) --c[j];
    for (int j = 0; j <= 5; ++j)
      if (cnt[j] && (b[i] & (1 << j))) {
        --cnt[j];
        for (int k = 1; k <= (1 << 6) - 1; ++k)
          if ((1 << j) & k) --a[k];
        if (pd()) {
          putchar('a' + j);
          break;
        }
        for (int k = 1; k <= (1 << 6) - 1; ++k)
          if ((1 << j) & k) ++a[k];
        ++cnt[j];
      }
  }
  return 0;
}
