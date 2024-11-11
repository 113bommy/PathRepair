#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m = INT_MAX;
    int n;
    cin >> n;
    int a[n];
    set<long long int> s;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    m = a[n - 1];
    long long int k = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (m >= a[i]) {
        m = a[i];
        continue;
      } else
        k++;
    }
    cout << k << "\n";
  }
}
