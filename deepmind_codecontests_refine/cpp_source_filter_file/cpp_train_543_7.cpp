#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int moves = 0;
    long long int m = (n + 1) / 2;
    moves = 8 * (m * (m + 1) * ((2 * m) + 1)) / 6;
    cout << moves << "\n";
  }
  return 0;
}
