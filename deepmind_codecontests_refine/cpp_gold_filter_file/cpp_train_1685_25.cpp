#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, a[150001], max, count;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    max = 1e9;
    count = 0;
    for (int j = n - 1; j >= 0; j--) {
      if (a[j] <= max) {
        max = a[j];
      } else {
        count++;
      }
    }
    cout << count << "\n";
  }
}
