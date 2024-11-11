#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s = 0, c;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c, s += c;
    cout << (s / n) + 1 << '\n';
  }
}
