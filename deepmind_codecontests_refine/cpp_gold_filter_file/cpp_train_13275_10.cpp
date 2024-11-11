#include <bits/stdc++.h>
using namespace std;
const long long inf = 1LL << 60;
const long double eps = 1e-14;
long long choose(long long n, long long k) {
  long long res = 1;
  for (int i = (0); i < int(k); ++i) res = res * (n - i) / (i + 1);
  return res;
}
int main() {
  long long x;
  cin >> x;
  x %= 360;
  if (x < 0) x += 360;
  if (x == 315)
    puts("0");
  else
    cout << (x + 44) / 90 % 4 << endl;
}
