#include <bits/stdc++.h>
using namespace std;
int a[111];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    a[i] = 1e9;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      scanf("%d", &x);
      a[i] = min(a[i], x);
    }
  }
  cout << (*max_element(a, a + n));
  return 0;
}
