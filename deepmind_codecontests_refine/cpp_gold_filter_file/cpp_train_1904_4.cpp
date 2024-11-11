#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      int s;
      cin >> s;
      sum += s;
    }
    if (sum == m) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
