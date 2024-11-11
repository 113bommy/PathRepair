#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647, maxL = 18 + 10;
long long N1, N2;
long long f[maxL];
void setIO(string name) {
  string in = name + ".in";
  string out = name + ".out";
  freopen(in.c_str(), "r", stdin);
  freopen(out.c_str(), "w", stdout);
}
long long solve(long long a) {
  if (a == 0) return 0;
  long long l = 0, k = 1, res = 0;
  while (a >= k) ++l, k *= 10;
  k /= 10;
  long long x = a / k, y = a % 10;
  a %= k;
  a /= 10;
  if (x <= y) ++a;
  res = a;
  k = 1;
  for (int i = 0; i < l - 2; ++i) k *= 10;
  res += k * (x - 1);
  res += f[l - 1];
  return res;
}
int main() {
  f[0] = 0, f[1] = 9;
  long long k = 1;
  for (int i = 2; i <= 18; ++i) f[i] = 9 * k + f[i - 1], k *= 10;
  scanf("%I64d %I64d", &N1, &N2);
  if (N2 % 10 == 0) --N2;
  long long a = solve(N2);
  long long b = solve(N1 - 1);
  printf("%I64d\n", a - b);
  return 0;
}
