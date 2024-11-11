#include <bits/stdc++.h>
using namespace std;
long long fpow(long long n, long long m) {
  if (m == 0) return 0;
  if (n == 0) return 1;
  long long k;
  if (n % 2) {
    return (3 * fpow(n - 1, m)) % m;
  } else {
    k = fpow(n / 2, m);
    return (k * k) % m;
  }
}
int main() {
  long long n, m;
  cin >> n >> m;
  if (fpow(n, m))
    cout << fpow(n, m) - 1 << endl;
  else
    cout << 0 << endl;
}
