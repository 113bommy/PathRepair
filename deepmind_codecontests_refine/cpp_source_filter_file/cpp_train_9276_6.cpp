#include <bits/stdc++.h>
using namespace std;
int n, i, m, x, a[109]{0};
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> m;
    while (m--) {
      cin >> x;
      ++a[x];
    }
  }
  for (i = 1; i <= 100; i++)
    if (a[i] == n) cout << a[i] << " ";
  return 0;
}
