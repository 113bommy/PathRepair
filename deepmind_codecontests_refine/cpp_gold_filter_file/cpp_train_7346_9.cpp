#include <bits/stdc++.h>
using namespace std;
long long ncrp(long long n, long long r, long long p) {
  long long C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (long long i = 1; i <= n; i++)
    for (long long j = min(i, r); j >= 1; j--) C[j] = (C[j] + C[j - 1]) % p;
  return C[r];
}
long long mod_exp(long long x, long long y, long long mm) {
  x %= mm;
  if (y == 0)
    return (1);
  else if (y % 2 == 0)
    return (mod_exp((x * x) % mm, y / 2, mm));
  else
    return ((x * mod_exp((x * x) % mm, (y - 1) / 2, mm)) % mm);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, r, s;
  cin >> n;
  r = (sqrt(1 + 8 * n) - 1) / 2;
  s = n - (r * (r + 1) / 2);
  cout << r << endl;
  for (long long i = r; i >= 1; i--) {
    if (s != 0) {
      cout << i + 1 << " ";
      s--;
    } else
      cout << i << " ";
  }
  return 0;
}
