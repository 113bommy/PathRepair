#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << 2 * n - __builtin_popcountll(n);
  }
}
