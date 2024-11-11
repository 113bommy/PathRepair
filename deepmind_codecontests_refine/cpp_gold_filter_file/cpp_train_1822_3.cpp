#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x = 0, y = 0, ans, i, j, k, v;
  cin >> n;
  int a[n + 1], b[100001] = {0}, c[n + 1];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] <= n) {
      b[a[i]]++;
    } else {
      b[a[i]]--;
    }
  }
  for (i = 1; i <= n; i++) {
    if (b[i] == 0) {
      c[x] = i;
      x++;
    }
  }
  if (x > 0) {
    for (i = 0; i < n; i++) {
      if (b[a[i]] > 1 || b[a[i]] < 0) {
        b[a[i]]--;
        a[i] = c[y];
        y++;
      }
    }
  }
  for (i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
