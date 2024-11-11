#include <bits/stdc++.h>
using namespace std;
int n, m, k, ind;
int main() {
  while (cin >> n >> m >> k) {
    vector<int> a(n), b(m), M(n + 1);
    for (int i = 0; i < (int)n; ++i) {
      scanf("%d", &a[i]);
      M[a[i]] = i;
    }
    long long ans = 0;
    for (int i = 0; i < (int)m; ++i) {
      scanf("%d", &b[i]);
      ind = M[b[i]];
      ans += ind / k + 1;
      if (ind) {
        swap(a[ind - 1], a[ind]);
        M[a[ind - 1]] = ind - 1;
        M[a[ind]] = ind;
      }
    }
    cout << ans << endl;
  }
}
