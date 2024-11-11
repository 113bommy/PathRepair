#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  bool flag = false;
  if (n == 2) {
    cout << a[1] + a[1] - a[0];
    return 0;
  }
  for (int i = 1; i < n - 1; i++) {
    if (a[i] * 2 != a[i - 1] + a[i + 1]) {
      cout << a[n - 1];
      return 0;
    }
  }
  cout << a[n - 1] + a[n - 1] - a[n - 2];
}
