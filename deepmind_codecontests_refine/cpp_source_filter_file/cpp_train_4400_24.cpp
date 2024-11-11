#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, i;
  cin >> n;
  int a[n];
  for (i = 1; i <= n; i++) {
    cin >> t;
    a[t] = i;
  }
  for (i = 1; i <= n; i++) {
    cout << a[i];
  }
  return 0;
}
