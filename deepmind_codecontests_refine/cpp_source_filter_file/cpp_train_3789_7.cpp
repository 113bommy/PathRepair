#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, temp = 0, v, x, y, q, a[100010] = {0}, n, m;
  cin >> n >> m;
  for (long long int i = 1; i <= n; i++) cin >> a[i];
  while (m--) {
    cin >> t;
    if (t == 1) {
      cin >> v >> x;
      a[v] = x;
    } else if (t == 2) {
      cin >> y;
      temp += y;
    } else if (t == 3) {
      cin >> q;
      cout << a[q] + temp << endl;
    }
  }
  return 0;
}
