#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  cin >> n >> k;
  k = min(n >> 1, k);
  cout << k * (n - 2 * k) + k * (k - 1) / 2 + k * (2 * n - k - 1) / 2;
  return 0;
}
