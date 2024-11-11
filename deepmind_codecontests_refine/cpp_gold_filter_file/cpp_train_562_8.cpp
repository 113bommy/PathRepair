#include <bits/stdc++.h>
using namespace std;
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int i = 0; i < t.size(); i++) s << t[i] << " ";
  return s;
}
long long sqr(long long n) { return n * n; }
void solve(char a, char b, long long n, long long m) {
  long long first = (long long)sqrt(m * 1.), second;
  first += 100;
  long long ans = n * n - m * m, cur = 1;
  for (long long i = min(n + 1, m); i > 1; i--) {
    long long d = m / i, res = 0, y1 = m - d * i;
    long long z = sqr(d) * (i - y1) + sqr(d + 1) * y1;
    res = sqr(n - i + 2) + i - 2 - z;
    if (res >= ans) ans = res, cur = i;
  }
  printf("%I64d\n", ans);
  long long d = m / cur, y1 = m - d * cur;
  if (y1)
    for (long long j = 0; j < y1; j++) {
      for (long long k = 0; k < d + 1; k++) putchar(b);
      putchar(a);
    }
  for (long long j = 0; j < cur - y1 - 1; j++) {
    for (long long k = 0; k < d; k++) putchar(b);
    putchar(a);
  }
  for (long long j = 0; j < n - cur + 1; j++) putchar(a);
  for (long long k = 0; k < d; k++) putchar(b);
}
int main() {
  long long n, m;
  while (~scanf("%I64d%I64d", &n, &m)) {
    if (m == 0) {
      printf("%I64d\n", n * n);
      for (long long i = 0; i < n; i++) printf("o");
    } else if (n == 0) {
      printf("%I64d\n", -m * m);
      for (long long i = 0; i < m; i++) printf("x");
    } else
      solve('o', 'x', n, m);
    puts("");
  }
}
