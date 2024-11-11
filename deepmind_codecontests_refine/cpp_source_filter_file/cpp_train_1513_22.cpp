#include <bits/stdc++.h>
using namespace std;
long double x = 1.000000011;
int main() {
  long double n;
  int t;
  cin >> n >> t;
  n += pow(x, t);
  cout.precision(10);
  cout << n;
  return 0;
}
