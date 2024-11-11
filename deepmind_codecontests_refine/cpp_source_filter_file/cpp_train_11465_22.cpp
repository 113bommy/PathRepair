#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> t;
  cout.precision(9);
  for (int i = 0; i < t; i++) {
    cin >> n;
    if (n > 0 && n < 4)
      cout << "N\n";
    else
      cout << "Y " << (n + sqrt(n * n - 4 * n)) / 2. << " "
           << (n - sqrt(n * n - 4 * n)) / 2. << "\n";
  }
  return 0;
}
