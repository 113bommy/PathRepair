#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long int k2, k3, k4, k5, k6;
  cin >> k2 >> k3 >> k4 >> k5 >> k6;
  long long int a = min({k2, k5, k6});
  k2 = k2 - a;
  long long int b = min(k2, k3);
  cout << a * 256 + b * 32;
  return 0;
}
