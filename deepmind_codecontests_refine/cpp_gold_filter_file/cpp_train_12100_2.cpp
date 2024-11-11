#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int m, n, a, b;
  cin >> t;
  while (t--) {
    cin >> m >> n >> a >> b;
    cout << ((n - m) % (a + b) == 0 ? (n - m) / (a + b) : -1) << endl;
  }
  return 0;
}
