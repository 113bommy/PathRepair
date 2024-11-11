#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  k = n - 2 * min(k, n / 2);
  cout << (n - 1) * n / 2 - (k - 1) * k / 2;
  return 0;
}
