#include <bits/stdc++.h>
using namespace std;
using namespace std;
using namespace std;
long long int fact(long long int n) {
  if (n <= 1) return 1;
  return (n * fact(n - 1));
}
long long int nPr(long long int n, long long int r) {
  return (fact(n)) / fact(n - r);
}
long long int binpow(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long int res = binpow(a, b / 2) % int(1e9 + 7);
  res = (res * res) % int(1e9 + 7);
  if (b & 1) res = (res * a) % int(1e9 + 7);
  return res;
}
int main() {
  long long int t, l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    long long int s = r + 1;
    if (l >= (s / (float)2))
      cout << "yes"
           << "\n";
    else
      cout << "no"
           << "\n";
  }
  return 0;
}
