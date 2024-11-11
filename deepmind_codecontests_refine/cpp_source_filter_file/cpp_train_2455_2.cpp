#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[10], i, j;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
      if (a[i] > a[j]) {
        a[i] = a[i] + a[j];
        a[j] = a[i] - a[j];
        a[i] = a[i] + a[j];
      }
  cout << a[n / 2];
  return 0;
}
