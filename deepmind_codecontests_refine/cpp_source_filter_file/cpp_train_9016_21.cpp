#include <bits/stdc++.h>
using namespace std;
int v[110000] = {0};
int main() {
  int n, k, m, a[100010], t = 0, p, g = 0;
  cin >> n >> k >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v[a[i] % m]++;
    if (v[a[i] % m] == k) {
      t = 1;
      p = a[i] % m;
    }
  }
  if (!t)
    cout << "NO";
  else {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
      if (a[i] % m == p) {
        cout << a[i] << " ";
        g++;
        if (g == k) break;
      }
  }
}
