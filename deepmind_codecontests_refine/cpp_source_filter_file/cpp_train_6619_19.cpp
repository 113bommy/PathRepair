#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  int a[100010], aa[100010], c = 0, x = 0;
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
