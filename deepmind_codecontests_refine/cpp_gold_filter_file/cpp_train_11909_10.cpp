#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const double pi = (3.141592653589);
const int N = 2e5 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(10);
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    a[i] = i;
    b[i] = i + 1;
  }
  b[n - 1] = 0;
  if (n % 2 == 0) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    cout << (a[i] + b[i]) % n << " ";
  }
  return 0;
}
