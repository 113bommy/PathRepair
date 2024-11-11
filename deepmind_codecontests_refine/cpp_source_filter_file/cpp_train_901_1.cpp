#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const long long INF_LL = 9223372036854775807LL;
const double E = exp(1.0);
const double PI = acos(-1.0);
long long gcd(long long a, long long b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
long long lcd(long long a, long long b) { return a * b / gcd(a, b); }
inline long long read() {
  char ch = getchar();
  long long x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
using namespace std;
struct mp {
  int num;
  int dex;
  bool friend operator<(mp a, mp b) { return a.num > b.num; }
} a[1100];
int main() {
  int n;
  int sum = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].num);
    a[i].dex = i;
    sum += a[i].num;
  }
  if (sum % n == 0) {
    sort(a + 1, a + n + 1);
    int ave = sum / n;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      if (a[i].num == ave) cnt++;
    if (cnt == n) {
      printf("Exemplary pages.\n");
    } else {
      cnt = 0;
      int ml = -1, from = -1, to = -1;
      for (int i = 1; i <= n / 2; i++) {
        if ((a[i].num + a[n - i + 1].num) / 2 == ave && a[i].num != ave &&
            a[n - i + 1].num != ave) {
          cnt++;
          to = a[n - i + 1].dex;
          from = a[i].dex;
          ml = abs(a[i].num - a[n - i + 1].num) / 2;
        }
      }
      if (cnt != 1) {
        printf("Unrecoverable configuration\n");
      } else {
        printf("%d ml. from cup #%d to cup #%d.\n", ml, to, from);
      }
    }
  } else {
    printf("Unrecoverable configuration.\n");
  }
}
