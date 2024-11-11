#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, r;
  cin >> n >> k;
  r = n * (n - 1) / 2;
  if (k >= n / 2)
    r = n * (n - 1) / 2;
  else
    r -= (n - 2 * k) * (n - 2 * k - 1) / 2;
  cout << r;
  return 0;
}
