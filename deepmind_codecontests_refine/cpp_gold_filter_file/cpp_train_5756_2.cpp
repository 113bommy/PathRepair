#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << 2 << endl;
    for (int i = n; i >= 3; i--) {
      cout << i << " " << i - 2 << endl;
      if (i == n) cout << i - 1 << " " << i - 1 << endl;
    }
    if (n == 2) {
      cout << 1 << " " << 2 << endl;
    }
  }
  return 0;
}
