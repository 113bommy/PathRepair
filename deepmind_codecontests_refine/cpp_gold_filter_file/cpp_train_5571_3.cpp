#include <bits/stdc++.h>
using namespace std;
int a[100069], i, n, l, r;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> l;
    a[l] = i;
    r = max(r, i - min(max(a[l - 2], a[l + 1]), max(a[l - 1], a[l + 2])));
  }
  cout << r;
}
