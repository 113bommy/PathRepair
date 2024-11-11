#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int b[n];
  cin >> a[1];
  for (int i = 2; i <= n; i++) {
    cin >> a[i];
    b[i - 1] = a[i - 1] + a[i];
  }
  b[n] = a[n];
  for (int i = 1; i <= n; i++) {
    if (i != n)
      cout << b[i] << " ";
    else
      cout << b[i];
  }
  return 0;
}
