#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[100];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int p;
  cin >> p;
  for (int j = 0; j < p; j++) {
    int x, y;
    cin >> x >> y;
    if (x >= 2) {
      a[x - 2] += y - 1;
    }
    if (x <= n - 1) {
      a[x] += a[x - 1] - y;
    }
    a[x - 1] = 0;
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}
