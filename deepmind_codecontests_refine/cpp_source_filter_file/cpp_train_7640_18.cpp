#include <bits/stdc++.h>
using namespace std;
long long fact[200005];
long long binfact[100005];
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    n >>= 1;
  }
  return res;
}
long long solve(int n, int m, int g) {
  if (n == 1 && m == 0 && g == 0) return 1;
  if (n == 0 && m == 1 && g == 0) return 0;
  if (n == 1 && m == 0 && g == 1) return 0;
  if (n == 0 && m == 1 && g == 1) return 1;
  if (n == 0 && g == 0) return 1;
  if (n == 0 && g == 1) return 0;
  if (m == 0 && g == 0) {
    if (n % 2 == 0)
      return 1;
    else
      return 0;
  }
  if (m == 0 && g == 1) {
    if (n % 2 != 0)
      return 1;
    else
      return 0;
  }
  if (g == 1)
    return solve(n - 1, m, 0);
  else
    return (solve(n - 1, m, 1) +
            ((((fact[n + m - 1] * binfact[n]) % 1000000007) * binfact[m - 1]) %
             1000000007)) %
           1000000007;
}
int main() {
  int n, m, g;
  cin >> n >> m >> g;
  fact[0] = 1;
  for (int i = 1; i < 200005; i++) fact[i] = (fact[i - 1] * i) % 1000000007;
  for (int i = 0; i < 100005; i++) binfact[i] = binpow(fact[i], 1000000007 - 2);
  cout << solve(n, m, g) << endl;
}
