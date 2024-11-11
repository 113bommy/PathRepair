#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long int n;
  cin >> t;
  while (t--) {
    cin >> n;
    n = (n + 1) / 2;
    if (n < 3) n = 3;
    cout << (5 * n) << "\n";
  }
}
