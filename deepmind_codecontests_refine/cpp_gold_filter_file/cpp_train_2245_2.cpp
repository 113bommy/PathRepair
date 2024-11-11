#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, j, g, t;
  cin >> n >> j;
  char a[n];
  cin >> a;
  for (i = 0; i < n; i++) {
    if (a[i] == 'G') {
      g = i;
    } else if (a[i] == 'T') {
      t = i;
    }
  }
  if ((g - t) % j != 0) {
    cout << "NO";
    return 0;
  }
  if (g < t) {
    for (i = g; i < t; i += j) {
      if (a[i] == '#') {
        cout << "NO";
        return 0;
      }
    }
  } else {
    for (i = g; i > t; i -= j) {
      if (a[i] == '#') {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
}
