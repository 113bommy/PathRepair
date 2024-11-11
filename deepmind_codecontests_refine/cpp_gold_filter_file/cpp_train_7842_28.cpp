#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, b, n, t;
  cin >> k >> b >> n >> t;
  long long bacterias = 1;
  while (bacterias <= t) {
    bacterias = 1LL * k * bacterias + b;
    n--;
  }
  cout << max(n + 1, 0) << endl;
  return 0;
}
