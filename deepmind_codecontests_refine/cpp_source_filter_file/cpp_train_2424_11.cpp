#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (size_t i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (size_t i = 1; i < n; i += 2) {
      cout << -a[i] << " " << -a[i - 1] << " ";
    }
    cout << endl;
  }
  return 0;
}
