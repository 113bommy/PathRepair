#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100001], b[100001], x[100001] = {};
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
