#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, c = 0;
  cin >> n;
  int a[n], b[n], s1 = 0, s2 = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    s1 += a[i];
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
    s2 += b[i];
  }
  if ((s1 - s2) < n)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
