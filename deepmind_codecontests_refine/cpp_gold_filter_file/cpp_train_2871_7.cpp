#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp;
  cin >> n;
  int a[n];
  for (int i = 0; i <= n - 1; ++i) cin >> a[i];
  for (int i = 0; i <= n / 2 - 1; ++i) {
    if (i % 2 == 0) {
      temp = a[i];
      a[i] = a[n - 1 - i];
      a[n - 1 - i] = temp;
    }
  }
  for (int i = 0; i <= n - 1; ++i) cout << a[i] << " ";
  return 0;
}
