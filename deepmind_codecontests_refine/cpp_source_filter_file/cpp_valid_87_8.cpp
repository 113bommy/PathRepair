#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int sol = 0;
    for (int i = 1; i < n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        sol += a[i] > a[j];
      }
    }
    cout << sol << "\n";
  }
}
