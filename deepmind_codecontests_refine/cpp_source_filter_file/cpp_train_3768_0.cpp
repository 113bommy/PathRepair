#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      sum += val;
    }
    int res = round((float)sum / n);
    cout << res << '\n';
  }
  return 0;
}
