#include <bits/stdc++.h>
using namespace std;
vector<int> b, c;
int a[1001], n, mx = 0;
int main() {
  cin >> n;
  b.resize(1000005);
  c.resize(1000005);
  for (int k = 1; k <= n; k++) {
    cin >> a[k];
    b[a[k]]++;
    mx = max(mx, b[a[k]]);
  }
  for (int k = 1; k <= n; k++) {
    c[a[k]]++;
    if (c[a[k]] == mx) {
      cout << a[k];
      return 0;
    }
  }
}
