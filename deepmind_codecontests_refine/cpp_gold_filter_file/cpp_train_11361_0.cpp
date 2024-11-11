#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      char c = 'a' + (i % k);
      cout << c;
    }
    cout << endl;
  }
  return 0;
}
