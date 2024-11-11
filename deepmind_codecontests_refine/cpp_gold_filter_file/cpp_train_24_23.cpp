#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i, j;
  cin >> t;
  for (i = 1; i <= t; i++) {
    long long int n;
    cin >> n;
    long long int a[n + 1];
    for (j = 1; j <= n; j++) {
      cin >> a[j];
    }
    if ((a[1] + a[2]) <= a[n]) {
      cout << 1 << " " << 2 << " " << n << endl;
    } else {
      cout << "-1" << endl;
    }
  }
}
