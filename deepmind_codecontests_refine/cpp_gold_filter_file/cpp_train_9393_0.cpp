#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 100;
const int mod = 10903;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << -1 << '\n';
      continue;
    }
    cout << 2;
    for (int i = 0; i < n - 1; i++) {
      cout << 3;
    }
    cout << '\n';
  }
}
