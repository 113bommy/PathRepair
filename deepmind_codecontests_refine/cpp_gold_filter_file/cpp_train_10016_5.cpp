#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, j, l;
  cin >> t;
  while (t--) {
    int n, m, x;
    cin >> n >> m;
    vector<int> a(n), A(500000), b(m), B(500000);
    for (i = 0; i < n; i++) {
      cin >> x;
      a[i] = x;
      A[x] = i;
    }
    for (i = 0; i < m; i++) {
      cin >> x;
      b[i] = x;
      B[x] = i;
    }
    long long int max = 0, ans = 0;
    for (i = 0; i < m; i++) {
      if (A[b[i]] > max) {
        ans += 2 * (A[b[i]] - i) + 1;
        max = A[b[i]];
      } else
        ans++;
    }
    cout << ans << endl;
  }
}
