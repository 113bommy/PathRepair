#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  int i;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> n;
    int ara[n], j, k, ara1[n], tmp;
    for (k = 0; k < n; k++) {
      cin >> ara[k];
      ara1[k] = k - ara[k];
    }
    for (j = 0; j < n - 1; j++) {
      for (k = j + 1; k < n; k++) {
        if (ara1[j] == ara1[k]) {
          tmp = ara[j];
          ara[j] = ara[k];
          ara[k] = tmp;
          ara1[k] = k - ara[k];
          ara1[j] = j - ara[j];
          j = -1;
          break;
        }
      }
    }
    for (k = 0; k < n; k++) {
      cout << ara[k] << " ";
    }
    cout << "\n";
  }
}
