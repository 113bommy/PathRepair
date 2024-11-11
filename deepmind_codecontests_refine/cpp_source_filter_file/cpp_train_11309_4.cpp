#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  for (long long i = 0; i <= n; i++) {
    long long y = n - (i * a);
    if (((i * a) + y == n) && (y % b == 0) && y > 0) {
      cout << "YES" << endl;
      cout << i << ' ' << y / b << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
