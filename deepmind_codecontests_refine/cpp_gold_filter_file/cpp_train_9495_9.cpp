#include <bits/stdc++.h>
using namespace std;
long long n, a, b, x = 945049, m = 15e6;
int main() {
  cin >> n >> a >> b;
  cout << ((a * x) % m) * m + 1 << " " << ((b * x) % m) * m;
  return 0;
}
