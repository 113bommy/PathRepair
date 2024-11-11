#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x[n], y[n];
  int h[n], a[n];
  int home[100002];
  for (int i = 0; i < 100002; i++) {
    home[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    cin >> y[i];
    h[i] = 0;
    a[i] = 0;
    home[x[i]]++;
  }
  for (int i = 0; i < n; i++) {
    h[i] = n - 1;
    a[i] = n - 1;
  }
  for (int i = 0; i < n; i++) {
    h[i] += home[y[i]];
    a[i] -= home[y[i]];
  }
  for (int i = 0; i < n; i++) {
    cout << h[i] << " " << a[i] << endl;
  }
  return 0;
}
