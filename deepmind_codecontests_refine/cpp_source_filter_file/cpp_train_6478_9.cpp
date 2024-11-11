#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, m = 0, o = 0, c = 0;
  cin >> n;
  int a[n], b[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (i = 0; i < n; i++) {
    if (a[i] == b[i]) c++;
    if (a[i] < b[i]) {
      m++;
    } else if (a[i] > b[i]) {
      o++;
    }
  }
  if (c == n) {
    cout << "-1";
    exit(0);
  }
  if (o > m) {
    cout << "1";
  } else if (o < m) {
    if (o == 0)
      cout << "-1";
    else {
      o = m / o + 1;
      cout << o;
    }
  } else if (m == n)
    cout << "2";
  return 0;
}
