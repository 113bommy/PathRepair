#include <bits/stdc++.h>
using namespace std;
template <class T>
void Min(T &x, T y) {
  if (y < x) x = y;
}
template <class T>
void Max(T &x, T y) {
  if (y > x) x = y;
}
const int maxn = 100010;
const int mod = 1000000007;
int c[1010][1010];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i <= 1000; i++) {
    c[i][0] = 1;
    c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
  }
  printf("%I64d\n", (long long)c[n - 1][2 * k] * c[m - 1][2 * k] % mod);
  return 0;
}
