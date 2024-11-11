#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, k, x;
  cin >> n >> k;
  x = n / (2 * (k + 1));
  cout << x << " " << k * x << " " << n - (k + 1) * x;
  return 0;
}
