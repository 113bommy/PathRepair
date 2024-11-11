#include <bits/stdc++.h>
using namespace std;
long long n, a, d, x = 945049, m = 15e6;
int main() {
  cin >> n >> a >> d;
  cout << ((a * x) % m) * m + 1 << " " << ((d * x) % m) * m;
  return 0;
}
