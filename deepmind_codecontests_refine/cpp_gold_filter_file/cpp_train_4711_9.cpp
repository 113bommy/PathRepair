#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int min = 1000;
    int diff[n - 1];
    for (int i = 0; i < n - 1; i++) diff[i] = a[i + 1] - a[i];
    for (int i = 0; i < n - 1; i++) {
      if (min > diff[i]) min = diff[i];
    }
    cout << min << "\n";
  }
}
