#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[100005], b[100005] = {0}, i, count = 0, n, m, k, h, t, flag = 1;
  cin >> n;
  cin >> m;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= m; i++) {
    cin >> t;
    if (t == 1) {
      cin >> k;
      cin >> h;
      a[k] = h;
      flag = 0;
      b[k] = (b[k] + count - b[k]);
    }
    if (t == 2) {
      cin >> k;
      count += k;
    }
    if (t == 3) {
      cin >> k;
      cout << a[k] + count - b[k] << endl;
    }
  }
  return 0;
}
