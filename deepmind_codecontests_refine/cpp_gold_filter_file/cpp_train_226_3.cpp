#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[2005], b[2005], c[2005];
bool ok() {
  for (int i = 0; i < n; i++) {
    if (c[i] != b[i]) return 0;
  }
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + n);
  int mn = 1e9 + 100;
  for (int i = 0; i < n; i++) {
    int add = (b[i] - a[0] + m) % m;
    for (int i = 0; i < n; i++) {
      c[i] = (a[i] + add) % m;
    }
    sort(c, c + n);
    if (ok()) {
      mn = min(mn, add);
    }
  }
  cout << mn << endl;
}
