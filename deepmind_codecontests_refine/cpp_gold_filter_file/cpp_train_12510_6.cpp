#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, r;
  cin >> n;
  cin >> k;
  r = sqrt(9 + 8 * (k + n));
  r = (r - 3) / 2;
  cout << n - r;
}
