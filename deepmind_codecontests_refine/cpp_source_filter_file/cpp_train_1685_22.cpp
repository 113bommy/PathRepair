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
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long min = a[n - 1];
    long long c = 0;
    for (long long i = n - 1 - 1; i >= 0; i--) {
      if (a[i] < min)
        min = a[i];
      else
        c++;
    }
    cout << c << "\n";
  }
  return 0;
}
