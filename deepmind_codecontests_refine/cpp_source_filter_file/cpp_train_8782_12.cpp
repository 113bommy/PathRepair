#include <bits/stdc++.h>
using namespace std;
const int N = 100007;
int n, m, q[N], a[N], mn = 1007, k, l;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> q[i];
    mn = min(mn, q[i]);
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = n - 1; i >= 0; i--) {
    k += a[i];
    l++;
    if (l == mn) {
      l = 0;
      if (i == 1)
        i--;
      else if (i >= 2)
        i -= 2;
    }
  }
  cout << k;
  return 0;
}
