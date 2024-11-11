#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int d[m];
  for (int _n(m), i(0); i < _n; i++) cin >> d[i];
  int p[k];
  for (int _n(k), i(0); i < _n; i++) cin >> p[k];
  vector<int> ans;
  int best = k + 1;
  for (int _n(m), i(0); i < _n; i++) {
    int cnt = 0;
    for (int _n(k), j(0); j < _n; j++)
      if (p[j] % d[i] == 0) cnt++;
    if (cnt < best) {
      best = cnt;
      ans.clear();
    }
    if (cnt == best) ans.push_back(i + 1);
  }
  cout << ans.size() << endl;
  for (int _n(ans.size()), i(0); i < _n; i++) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  return 0;
}
