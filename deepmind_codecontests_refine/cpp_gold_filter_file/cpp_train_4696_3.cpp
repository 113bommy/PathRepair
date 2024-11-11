#include <bits/stdc++.h>
using namespace std;
long long hcf(long long a, long long b) { return b == 0 ? a : hcf(b, a % b); }
int main() {
  long long a, b, x, y;
  cin >> a >> b >> x >> y;
  long long k = hcf(x, y);
  x = x / k;
  y = y / k;
  cout << min(a / x, b / y);
}
