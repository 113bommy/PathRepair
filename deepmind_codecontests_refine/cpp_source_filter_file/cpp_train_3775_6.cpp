#include <bits/stdc++.h>
using namespace std;
inline int rd(int f = 1, int x = 0, char ch = ' ') {
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = -1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
const int N = 3e5 + 5, P = 998244353;
int n, a[N];
void fix(int &x) { x < P ? 0 : x -= P; }
long long inv(int i) { return i == 1 ? 1 : P - (P / i) * inv(P % i) % P; }
int main() {
  n = rd();
  for (int i = 1; i <= n; ++i) a[i] = rd();
  sort(a + 1, a + n + 1, [&](int a, int b) { return a > b; });
  for (int i = 2; i <= n; ++i) fix(a[i] += a[i - 1]);
  for (int k = 1, w = inv(n); k <= n; ++k) {
    int s = 0;
    for (int i = k, j = 1; i < n; i += k, ++j)
      fix(s += (long long)(a[min(n, i + k)] - a[i]) * j % P);
    printf("%lld ", (long long)s * w % P);
  }
  puts("");
  return 0;
}
