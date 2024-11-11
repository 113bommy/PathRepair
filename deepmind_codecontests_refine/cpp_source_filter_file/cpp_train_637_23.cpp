#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int a, b, c, d;
  a = b = c = d = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (x & 1)
      a++;
    else
      b++;
  }
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    if (x & 1)
      c++;
    else
      d++;
  }
  int res = min(a, d) + min(d, c);
  cout << res << endl;
}
