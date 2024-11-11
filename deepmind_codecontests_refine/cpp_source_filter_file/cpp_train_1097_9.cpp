#include <bits/stdc++.h>
using namespace std;
int a[111], b[111];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (register int i = (0); i < (int)n; ++i) {
    for (register int j = (0); j < (int)n; ++j) cin >> b[j];
    for (register int j = (0); j < (int)n; ++j) a[j] += b[j];
  }
  bool ok = true;
  for (register int i = (0); i < (int)n; ++i)
    if (a[i]) {
      ok = false;
      break;
    }
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
