#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  cin >> q;
  vector<int> m(q);
  for (int i = 0; i < q; i++) {
    cin >> m[i];
    int ans = lower_bound(x.begin(), x.end(), m[i]) + 1 - x.begin();
    cout << ans << endl;
  }
}
