#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100000], b[100000], x[100000] = {};
  cin >> n;
  cout << n - 1 << endl;
  for (int i = 1; i < n; ++i) {
    cin >> a[i] >> b[i];
    cout << 2 << ' ' << a[i] << ' ' << b[i] << endl;
  }
  for (int i = 1; i < n; ++i) {
    if (x[a[i]]) cout << x[a[i]] << ' ' << i << endl;
    if (x[b[i]]) cout << x[b[i]] << ' ' << i << endl;
    x[b[i]] = x[a[i]] = i;
  }
  return 0;
}
