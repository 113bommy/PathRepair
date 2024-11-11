#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, n, i, j, c = 0;
  cin >> s >> n;
  int a[n], b[n];
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        swap(a[i], a[j]);
        swap(b[i], b[j]);
      }
    }
  for (i = 0; i < n && c == 0; i++) {
    if (s >= a[i])
      s = s + b[i];
    else {
      c = 1;
    }
  }
  if (c == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
