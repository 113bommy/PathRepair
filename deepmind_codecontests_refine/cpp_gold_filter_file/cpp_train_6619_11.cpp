#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  int a[200010], aa[200010] = {0}, c = 0, x = 0;
  for (i = 0; i < 2 * n; i++) {
    cin >> a[i];
    if (aa[a[i]] != 0)
      c--;
    else {
      c++;
      aa[a[i]] = 1;
    }
    x = max(c, x);
  }
  cout << x;
}
