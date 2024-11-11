#include <bits/stdc++.h>
using namespace std;
inline int Readint() {
  int ret = 0;
  int f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f *= -1;
  } while (ch >= 0 && (ch < '0' || ch > '9'));
  while ('0' <= ch && ch <= '9') {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * f;
}
void open() {
  freopen("soccer.in", "r", stdin);
  freopen("soccer.out", "w", stdout);
}
void close() {
  fclose(stdin);
  fclose(stdout);
}
int n, m;
long long ans = -1e9;
void init() { n = Readint(), m = Readint(); }
long long calc(int k) {
  int a = n, b = m;
  long long lena = a - k + 1;
  long long lenb = b / (k + 1) + 1;
  long long modb = b % (k + 1);
  long long reta = 0;
  long long retb = 0;
  reta = lena * lena + k - 1;
  retb = lenb * lenb * modb + (lenb - 1) * (lenb - 1) * (k + 1 - modb);
  return reta - retb;
}
void work() {
  long long tmp;
  int place = 0;
  for (int i = 1, _END_ = min(n, m - 1); i <= _END_; i++) {
    tmp = calc(i);
    if (ans < tmp) {
      ans = tmp;
      place = i;
    }
  }
  int cnt = m % (place + 1);
  cnt = place + 1 - cnt;
  printf("%I64d\n", ans);
  for (int i = 1, _END_ = place << 1 | 1; i <= _END_; i++)
    if (i & 1) {
      if (cnt > 0) {
        for (int j = 1, _END_ = m / (place + 1); j <= _END_; j++) printf("x");
        cnt--;
      } else
        for (int j = 1, _END_ = m / (place + 1) + 1; j <= _END_; j++)
          printf("x");
    } else {
      if (i == 2)
        for (int j = 1, _END_ = n - place + 1; j <= _END_; j++) printf("o");
      else
        printf("o");
    }
}
int main() {
  int _ = 0;
  init();
  if (!n) {
    printf("%I64d\n", -1ll * m * m);
    for (int i = 1, _END_ = m; i <= _END_; i++) printf("x");
    printf("\n");
  } else if (!m) {
    printf("%I64d\n", 1ll * n * n);
    for (int i = 1, _END_ = n; i <= _END_; i++) printf("o");
    printf("\n");
  } else if (m == 1) {
    printf("%I64d\n", 1ll * n * n - 1);
    for (int i = 1, _END_ = n; i <= _END_; i++) printf("o");
    printf("y\n");
  } else {
    work();
  }
  close();
  return 0;
}
