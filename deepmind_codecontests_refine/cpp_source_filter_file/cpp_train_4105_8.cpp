#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main() {
  int n, maxp, mx2p;
  scanf("%d", &n);
  for (register int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  if (a[1] > a[2]) {
    maxp = 1;
    mx2p = 2;
  } else {
    maxp = 2;
    mx2p = 1;
  }
  for (register int i = 3; i <= n; ++i) {
    if (a[i] > a[maxp]) {
      mx2p = maxp;
      maxp = i;
    } else if (a[i] > mx2p) {
      mx2p = i;
    }
  }
  printf("%d %d", maxp, a[mx2p]);
  return 0;
}
