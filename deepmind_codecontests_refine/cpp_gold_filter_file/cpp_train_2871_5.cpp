#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int temp, n, m, i, j;
  long long int a[200001];
  cin >> n;
  a[0] = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  j = n / 2;
  m = n;
  for (i = 1; i <= j; i++) {
    temp = a[i];
    a[i] = a[m];
    a[m] = temp;
    m = m - 2;
    i = i + 1;
  }
  for (i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
