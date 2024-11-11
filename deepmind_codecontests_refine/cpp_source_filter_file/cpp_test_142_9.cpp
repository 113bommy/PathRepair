#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    vector<int> v(n, 0);
    vector<int> b(n);
    int c = -1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> b[j];
        v[j] = max(v[j], b[j]);
      }
      sort(b.begin(), b.end());
      c = max(c, b[n - 2]);
    }
    cout << min(c, *min_element(v.begin(), v.end()));
  }
  return 0;
}
