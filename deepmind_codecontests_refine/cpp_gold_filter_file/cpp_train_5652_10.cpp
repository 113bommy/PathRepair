#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n], x_or;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    x_or = (i > 0 ? x_or ^ a[i] : a[i]);
  }
  if (n & 1) {
    cout << "YES\n" << n - 2 << '\n';
    for (int i = 2; i < n; i += 2)
      cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
    for (int i = 2; i < n - 2; i += 2)
      cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
  } else {
    if (x_or)
      cout << "NO\n";
    else {
      cout << "YES\n" << n - 2 << '\n';
      for (int i = 2; i < n; i += 2) {
        cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
        cout << i << ' ' << i + 1 << ' ' << n << '\n';
      }
    }
  }
}
