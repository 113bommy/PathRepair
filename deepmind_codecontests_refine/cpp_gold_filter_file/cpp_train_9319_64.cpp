#include <bits/stdc++.h>
using namespace std;
int a[1005];
int b[1005];
int main() {
  int n;
  scanf("%d", &n);
  int mx = 0;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", b + i);
  for (int i = 0; i < n; i++) {
    int x1, x2;
    x1 = x2 = 0;
    for (int j = i; j < n; j++) {
      x1 |= a[j];
      x2 |= b[j];
      mx = max(mx, x1 + x2);
    }
  }
  cout << mx << endl;
}
