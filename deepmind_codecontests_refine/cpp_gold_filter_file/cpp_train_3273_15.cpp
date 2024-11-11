#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x[n], y[n], h[n], a[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++) {
    h[i] = n - 1;
    a[i] = 0;
  }
  int home[1000000] = {0}, away[1000000] = {0};
  for (int i = 0; i < n; i++) {
    home[x[i]]++;
    away[y[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (home[y[i]] > 0) h[i] += home[y[i]];
  }
  for (int i = 0; i < n; i++) {
    a[i] = 2 * (n - 1) - h[i];
  }
  for (int i = 0; i < n; i++) cout << h[i] << " " << a[i] << endl;
  return 0;
}
