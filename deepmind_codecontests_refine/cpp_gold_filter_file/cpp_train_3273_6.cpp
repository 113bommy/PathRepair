#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, i;
  cin >> n;
  long int x[n], y[n], a[100001] = {0}, x1[n], y1[n];
  for (i = 0; i < n; i++) {
    x1[i] = n - 1;
    y1[i] = n - 1;
  }
  for (i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    a[x[i]]++;
  }
  for (i = 0; i < n; i++) {
    x1[i] += a[y[i]];
    y1[i] = 2 * n - 2 - x1[i];
    cout << x1[i] << " " << y1[i] << "\n";
  }
}
