#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, t, s = 1;
  cin >> n;
  t = n - 1;
  int p[n];
  for (i = 0; i < n; i++) {
    if (i == 0) {
      p[i] = 1;
    } else {
      cin >> p[i];
    }
  }
  for (i = t; i >= 1; i = p[i] - 1) {
    s = s + 1;
  }
  int k = s;
  int a[k];
  a[0] = 1;
  int z = s - 1;
  for (i = t; i >= 1; i = p[i] - 1) {
    a[z] = i + 1;
    z = z - 1;
  }
  for (i = 0; i < s; i++) {
    cout << a[i];
  }
  return 0;
}
