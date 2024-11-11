#include <bits/stdc++.h>
using namespace std;
long long bigmod(long long a, long long b, long long m) {
  if (b == 0) return 1 % m;
  long long x = bigmod(a, b / 2, m);
  x = (x * x) % m;
  if (b % 2) x = (x * a) % m;
  return x;
}
int main() {
  int p, an = 0, t, x[100000 + 5], y[100000 + 5], n, k, i, j;
  cin >> p;
  for (i = 1, j = n; i < j; i++, j--) cout << i << " " << j << " ";
  if (n % 2) cout << n / 2 + 1 << endl;
}
