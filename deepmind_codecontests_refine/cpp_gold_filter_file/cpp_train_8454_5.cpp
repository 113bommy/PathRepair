#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int a[n];
    for (int j = 0; j < n; j++) {
      int ai;
      cin >> ai;
      a[j] = ai;
    }
    int n_z = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        n_z++;
        a[i] = 1;
      }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
    }
    if (sum != 0) {
      cout << n_z << "\n";
    } else {
      cout << 1 - sum + n_z << "\n";
    }
  }
  return 0;
}
