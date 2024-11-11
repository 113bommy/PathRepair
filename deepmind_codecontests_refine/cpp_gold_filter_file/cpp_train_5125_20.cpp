#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int u = 0; u < t; u++) {
    int n, day;
    cin >> n >> day;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
      while ((day >= i) && (a[i] != 0)) {
        a[i]--;
        a[0]++;
        day -= i;
      }
    }
    cout << a[0] << endl;
  }
  return 0;
}
