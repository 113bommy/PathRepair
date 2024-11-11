#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  vector<long long> a(n);
  a[0] = y - n + 1;
  for (int i = 1; i < n; ++i) a[i] = 1;
  long long s = 0;
  for (int i = 0; i < n; ++i) s += a[i] * a[i];
  if (a[0] <= 0 || s < x)
    cout << -1 << endl;
  else {
    for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
  }
  return 0;
}
