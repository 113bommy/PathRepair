#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r = 0, i, j, p = 0;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    if (a[1] == a[i] || a[n - 1] == a[i]) p++;
  }
  cout << n - p;
}
