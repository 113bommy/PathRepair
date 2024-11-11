#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  int t = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  bool ok;
  for (int i = 0; i < n; i++) {
    ok = false;
    for (int j = 0; j < m; j++)
      if (a[i] <= b[j]) {
        b[j] = -2;
        ok = true;
        break;
      }
    if (ok == false) t++;
  }
  cout << t << endl;
}
