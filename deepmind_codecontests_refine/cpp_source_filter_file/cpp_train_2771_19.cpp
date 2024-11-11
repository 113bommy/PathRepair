#include <bits/stdc++.h>
using namespace std;
int n, x[2010], y[2010], a[2000010], ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    a[x[i]] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> y[i];
    a[y[i]] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ans += a[x[i] ^ y[j]];
    }
  }
  if (ans % 2) {
    cout << "Koyomi";
  } else {
    cout << "Karen";
  }
}
