#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, i;
  cin >> q;
  char a[q];
  int b[q], c[200005];
  int l = 300000, r = 300001;
  for (i = 0; i < q; i++) {
    cin >> a[q] >> b[q];
    if (a[q] == 'L') {
      c[b[q]] = l;
      l--;
    }
    if (a[q] == 'R') {
      c[b[q]] = r;
      r++;
    }
    if (a[q] == '?') cout << min(c[b[q]] - l - 1, r - c[b[q]] - 1) << endl;
  }
  return 0;
}
