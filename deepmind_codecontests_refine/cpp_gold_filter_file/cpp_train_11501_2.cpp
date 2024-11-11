#include <bits/stdc++.h>
using namespace std;
long long a[1000] = {1};
long long b[1000];
int main() {
  int m, s1, s2;
  scanf("%d%d", &m, &s1);
  s2 = s1;
  if ((s1 == 0 && m > 1) || (s1 > 9 * m)) {
    cout << "-1 -1";
    return 0;
  }
  for (int i = m - 1; i > 0; i--) {
    if (s1 < 9) {
      a[i] = s1 - 1;
      s1 = 1;
    } else if (s1 == 9 && i != 0) {
      a[i] = 8;
      s1 -= 8;
    } else {
      a[i] = 9;
      s1 -= 9;
    }
  }
  a[0] = s1;
  for (int i = 0; i < m; i++) {
    if (s2 < 9) {
      b[i] = s2;
      s2 = 0;
    } else {
      b[i] = 9;
      s2 -= 9;
    }
  }
  for (int i = 0; i < m; i++) printf("%d", a[i]);
  cout << " ";
  for (int i = 0; i < m; i++) printf("%d", b[i]);
  return 0;
}
