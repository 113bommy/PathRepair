#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100];
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i < n - 1; ++i) {
    if (2 * a[i] != a[i - 1] + a[i + 1]) {
      cout << a[n];
      return 0;
    }
  }
  cout << a[n] + a[1] - a[0];
  return 0;
}
