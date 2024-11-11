#include <bits/stdc++.h>
using namespace std;
long long xorn(long long n) {
  long long r = n % 4;
  if (r == 0) return n;
  if (r == 1) return 1;
  if (r == 2) return n + 1;
  if (r == 3) return 0;
}
int main() {
  long long n;
  cin >> n;
  long long val = 0;
  for (long long i = 1; i <= n; i++) {
    long long x, m;
    cin >> x >> m;
    val ^= xorn(x - 1) ^ xorn(x + m - 1);
  }
  if (val == 0)
    cout << "bolick";
  else
    cout << "tolik";
}
