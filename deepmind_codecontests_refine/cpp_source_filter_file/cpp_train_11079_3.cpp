#include <bits/stdc++.h>
using namespace ::std;
int cols[200], a[200], sizes[200];
int main() {
  int n, active = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    int l = 0;
    while (l < active) {
      if (cols[l] <= a[i] && sizes[l] < a[i]) {
        cols[l] = a[i];
        sizes[l]++;
        break;
      }
      l++;
    }
    if (l == active) {
      cols[l] = a[i];
      sizes[l] = 1;
      active++;
    }
  }
  cout << active << endl;
}
