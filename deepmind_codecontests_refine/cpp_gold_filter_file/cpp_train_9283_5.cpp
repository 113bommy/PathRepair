#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < n; ++i)
    if (i % 2) {
      a[i] = 2 * n - i + 1;
      a[i + n] = a[i] - 1;
    } else {
      a[i] = 1 + i;
      a[i + n] = a[i] + 1;
    }
  if (n % 2) {
    cout << "YES\n";
    for (int i = 0; i < 2 * n; ++i) cout << a[i] << " ";
    cout << "\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
