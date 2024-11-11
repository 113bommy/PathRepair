#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t, n, d;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    long long md = -1e12;
    md = max(md, 1LL * v[0] * v[1] * v[2] * v[3] * v[4]);
    md = max(md, 1LL * v[0] * v[1] * v[2] * v[3] * v[n - 1]);
    md = max(md, 1LL * v[0] * v[1] * v[n - 1] * v[n - 2] * v[n - 3]);
    md = max(md, 1LL * v[0] * v[n - 1] * v[n - 2] * v[n - 3] * v[n - 4]);
    md = max(md, 1LL * v[n - 1] * v[n - 2] * v[n - 3] * v[n - 4] * v[n - 5]);
    cout << md << endl;
  }
}
