#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n = 250;
    int a[250];
    int maxval = 0;
    double mean = 0;
    double var = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      maxval = max(maxval, a[i]);
      mean += a[i];
    }
    mean /= n;
    for (int i = 0; i < n; i++) var += (a[i] - mean) * (a[i] - mean);
    var /= n;
    int pvar = mean;
    int uvar = (maxval) * (maxval) / 12;
    if (abs(var - pvar) < abs(var - uvar))
      cout << mean << endl;
    else
      cout << maxval / 2 << endl;
  }
}
