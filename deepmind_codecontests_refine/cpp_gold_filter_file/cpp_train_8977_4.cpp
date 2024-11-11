#include <bits/stdc++.h>
using namespace std;
int64_t t, n;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    cout << 2 * n - __builtin_popcountll(n) << "\n";
  }
}
