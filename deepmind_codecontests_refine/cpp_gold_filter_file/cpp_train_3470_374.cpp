#include <bits/stdc++.h>
using namespace std;
double const eps = 1e-9;
int const INF = 100000;
int const MOD = 1000000007;
int const MAX = 1000 * 100 + 5;
int main() {
  int a, b;
  cin >> a;
  if (a == 5)
    cout << 1;
  else
    cout << a % 3 + 1;
  return 0;
}
