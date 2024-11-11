#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool f = 0;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar()) f = c == '-' ? 1 : 0;
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return f ? -x : x;
}
const int M = 1000000000, N = 1000010;
map<int, int> g;
int a00, a01, a10, a11, n, m, num[N], tp = 0;
char str[N];
int main() {
  for (int i = 1, s = 0; s <= M; s += i, i++) g[s] = i;
  a00 = read();
  a01 = read();
  a10 = read();
  a11 = read();
  n = g[a00];
  m = g[a11];
  if (!n || !m) return puts("Impossible"), 0;
  if (!a01 && !a10) {
    if (n == 1) {
      for (int i = 1; i <= m; i++) printf("1");
      puts("");
      return 0;
    } else if (m == 1) {
      for (int i = 1; i <= n; i++) printf("0");
      puts("");
      return 0;
    } else
      return puts("Impossible"), 0;
  }
  if ((long long)n * m != a01 + a10) return puts("Impossible"), 0;
  for (int i = 1; i <= n; i++) {
    if (m >= a01) {
      num[i] = a01 + 1;
      for (int j = i + 1; j <= n; j++) num[j] = 1;
      break;
    }
    num[i] = m + 1;
    a01 -= m;
  }
  num[0] = m + 1;
  for (int i = 0; i <= n; i++) num[i] -= num[i + 1];
  for (int i = 0; i <= n; i++) {
    str[tp++] = '0';
    for (int j = 1; j <= num[i]; j++) str[tp++] = '1';
  }
  str[--tp] = 0;
  printf("%s\n", str + 1);
  return 0;
}
