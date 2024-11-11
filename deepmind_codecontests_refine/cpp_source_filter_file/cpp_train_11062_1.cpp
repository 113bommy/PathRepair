#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, l, m;
  cin >> m;
  while (m--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int p = n - 1;
    while (p > 1 && a[p] <= a[p - 1]) {
      p--;
    }
    while (p > 1 && a[p] >= a[p - 1]) {
      p--;
    }
    cout << p - 1 << "\n";
  }
}
