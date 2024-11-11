#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int openedl, openedr;
  openedl = 0;
  openedr = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    if (l == 1) openedl++;
    if (r == 1) openedr++;
  }
  if (openedl > (n / 2)) {
    if (openedr > (n / 2))
      cout << (n - openedl) + (n - openedr);
    else
      cout << (n - openedl) + openedr;
  } else {
    if (openedr > (n / 2))
      cout << openedl + (n - openedr);
    else
      cout << openedl + openedr;
  }
  return 0;
}
