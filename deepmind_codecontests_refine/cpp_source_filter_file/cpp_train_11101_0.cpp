#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int a[N], b[N], c[N];
int main() {
  int n;
  cin >> n;
  a[0] = 1, b[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) c[i] = a[i];
    a[0] = b[0] % 2;
    for (int j = 1; j <= i + 1; j++) {
      a[j] = (c[j - 1] + b[j]) % 2;
    }
    for (int j = 0; j <= i; j++) b[i] = c[i];
  }
  cout << n << endl;
  for (int i = 0; i <= n; i++) cout << a[i] << " ";
  cout << endl;
  cout << n - 1 << endl;
  for (int i = 0; i < n; i++) cout << b[i] << " ";
  cout << endl;
  return 0;
}
