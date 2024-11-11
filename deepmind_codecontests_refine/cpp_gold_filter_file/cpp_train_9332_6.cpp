#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, i, j, a[55], b[55];
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < m; i++) cin >> b[i];
  for (i = 0; i < n; i++) {
    long long pr = -2e18;
    for (j = 0; j < m; j++) pr = max(pr, (long long)a[i] * (long long)b[j]);
    v.push_back(pr);
  }
  sort(v.rbegin(), v.rend());
  cout << v[1] << endl;
  return 0;
}
