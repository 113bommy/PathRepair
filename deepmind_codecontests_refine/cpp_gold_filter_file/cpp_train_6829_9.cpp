#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long aplusb, a, b, c;
long long max(long long a, long long b) { return (a > b) ? a : b; }
int main() {
  cin >> n >> k;
  aplusb = max(n / (k + 1), (n / 2) - (n / 2) % (k + 1));
  a = aplusb / (k + 1);
  b = a * k;
  c = n - a - b;
  cout << a << " " << b << " " << c << " " << endl;
  return 0;
}
