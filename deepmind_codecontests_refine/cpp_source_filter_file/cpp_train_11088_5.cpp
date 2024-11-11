#include <bits/stdc++.h>
using namespace std;
long a[100010];
int main() {
  long i, j, k, l, m, n, p;
  char c, c2;
  ios::sync_with_stdio(false);
  cin >> n;
  cin >> c;
  p = 1;
  memset(a, 0, sizeof(a));
  a[1] = 1;
  for (i = 2; i <= n; i++) {
    cin >> c2;
    if (c2 == c)
      a[p]++;
    else {
      p++;
      c = c2;
      a[p] = 1;
    }
  }
  m = p;
  long px = 0;
  for (i = 1; i <= p; i++)
    if (a[i] >= 2) px = 1;
  for (i = 1; i <= p; i++) {
    if ((a[i] >= 3) || (px == 1)) {
      if ((p + 2) > m) m = p + 2;
    } else if (a[i] == 2) {
      if ((p + 1) > m) m = p + 1;
    };
  }
  cout << m;
}
