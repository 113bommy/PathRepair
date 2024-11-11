#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int cn = 1, mc = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1])
      cn++;
    else
      cn = 1;
    if (cn > mc) mc = cn;
  }
  if (mc <= (n + 1) / 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
