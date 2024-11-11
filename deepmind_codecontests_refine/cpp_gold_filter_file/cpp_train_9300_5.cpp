#include <bits/stdc++.h>
using namespace std;
long long p(int x, long long y) {
  if (!y) return 1;
  long long res = p(x, y / 2);
  res = res * res % 1000000007;
  if (y & 1) res = res * x % 1000000007;
  return res;
}
int main() {
  long long n;
  cin >> n;
  long long x = p(2, n);
  cout << x * (x + 1) / 2 % 1000000007 << endl;
}
