#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
char nextchar() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return (p1 == p2) &&
                 (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <typename T>
void input(T& num) {
  static double f, x;
  static char ch;
  static bool sign;
  static long long z;
  f = 1.0 / 10;
  z = x = ch = num = sign = 0;
  while ((ch < '0') || (ch > '9')) {
    sign |= (ch == '-');
    ch = nextchar();
  }
  while ((ch >= '0') && (ch <= '9')) {
    z = z * 10 + (ch - '0');
    ch = nextchar();
  }
  if (ch == '.') {
    ch = nextchar();
    while ((ch >= '0') && (ch <= '9')) {
      x += (ch ^ 48) * f;
      f /= 10;
      ch = nextchar();
    }
  }
  num = sign ? -z - x : z + x;
}
long long N, ans;
pair<long long, long long> a[MAXN];
int main() {
  scanf("%I64d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%I64d", &a[i].first);
    a[i].first = -a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + N + 1);
  ans = 1;
  for (int i = 2; i <= N; i++) {
    ans += -a[i].first * (i - 1) + 1;
  }
  printf("%I64d\n", ans);
  printf("%I64d ", a[1].second);
  for (int i = 2; i <= N; i++) printf("%I64d ", a[i].second);
  return 0;
}
