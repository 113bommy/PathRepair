#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int a[n], b[n], j = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    b[j] = a[i] + a[i + 1];
    j++;
  }
  b[j] = a[i];
  for (i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  return 0;
}
