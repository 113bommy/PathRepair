#include <bits/stdc++.h>
using namespace std;
void result(int n) {
  long long int a[n], sum_even = 0, sum_odd = 0;
  for (int i = 0; i < n / 2; ++i) {
    a[i] = 2 + i * 2;
    sum_even += a[i];
  }
  for (int i = n / 2, j = 0; i < n - 1; ++i, ++j) {
    a[i] = 2 + j * 2 - 1;
    sum_odd += a[i];
  }
  a[n - 1] = sum_even - sum_odd;
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
}
int main() {
  long long int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n / 2 % 2 != 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      result(n);
      cout << endl;
    }
  }
}
