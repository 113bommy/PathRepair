#include <bits/stdc++.h>
using namespace std;
int dem, n;
int main() {
  cin >> n;
  dem = 576 * (n / 2520);
  n = n % 2520;
  for (int i = 1; i <= n; ++i) {
    if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0) ++dem;
  }
  cout << dem;
  return 0;
}
