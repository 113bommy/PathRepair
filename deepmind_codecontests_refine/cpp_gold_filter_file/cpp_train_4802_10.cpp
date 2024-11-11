#include <bits/stdc++.h>
using namespace std;
int F() {
  char ch;
  int x, a;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  if (ch == '-')
    ch = getchar(), a = -1;
  else
    a = 1;
  x = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - '0';
  return a * x;
}
const int N = 2e5 + 10;
int n, m, a[N], b[N], c[N];
vector<int> d[N];
long long t[N];
int main() {
  ((n) = F());
  m = n >> 1;
  for (int i = 1; i <= m; ++i) ((a[i]) = F());
  for (int i = 1; i <= 200000; ++i)
    for (int j = i; j <= 200000; j += i) d[j].push_back(i);
  for (int i = 1; i <= m; ++i) {
    if (a[i] % 4 == 2) {
      puts("No");
      return 0;
    }
    bool ok = 0;
    for (auto g : d[a[i]]) {
      int h = a[i] / g;
      if ((g + h) & 1) continue;
      int A = (g + h) >> 1, B = (g - h) >> 1;
      if (B <= c[i - 1]) continue;
      if (!ok) {
        ok = 1;
        b[i] = B, c[i] = A;
      } else {
        if (c[i] > A) {
          b[i] = B, c[i] = A;
        }
      }
    }
    if (!ok) {
      puts("No");
      return 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    t[(i << 1) - 1] = 1LL * b[i] * b[i];
    t[i << 1] = 1LL * c[i] * c[i];
  }
  for (int i = n; i; --i) t[i] -= t[i - 1];
  for (int i = 1; i <= n; ++i) {
    if (t[i] <= 0) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  for (int i = 1; i <= n; ++i) printf("%I64d ", t[i]);
  return 0;
}
