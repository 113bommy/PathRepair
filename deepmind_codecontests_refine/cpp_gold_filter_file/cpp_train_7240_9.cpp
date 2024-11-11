#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  b[n - 1] = a[n - 1];
  for (int j = 0; j < n - 1; j++) b[j] = a[j] + a[j + 1];
  for (int k = 0; k < n; k++) cout << b[k] << " ";
  return 0;
}
