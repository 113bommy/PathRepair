#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a = n;
    int b = n;
    while (a > 0) {
      for (int j = 1; j <= i && a > 0; j++) {
        cout << "(";
        a--;
      }
      cout << ")";
      b--;
    }
    for (int k = 1; k <= b; k++) {
      cout << ")";
    }
    cout << endl;
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
