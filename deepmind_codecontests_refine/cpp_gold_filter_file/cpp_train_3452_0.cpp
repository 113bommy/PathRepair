#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  vector<int> r(n + 1);
  for (i = 1; i <= n; i++) cin >> r[i];
  vector<int> c(n + 1);
  for (i = 1; i <= n; i++) cin >> c[i];
  vector<tuple<int, int, int, int>> ans;
  for (i = 1; i <= n; i++) {
    if (r[i] == i && c[i] == i) continue;
    int gr, gc;
    for (j = i; j <= n; j++)
      if (r[j] == i) {
        swap(r[i], r[j]);
        gr = j;
        break;
      }
    for (j = i; j <= n; j++)
      if (c[j] == i) {
        swap(c[i], c[j]);
        gc = j;
        break;
      }
    ans.push_back(make_tuple(gr, i, i, gc));
  }
  cout << ans.size() << endl;
  for (auto it : ans) {
    int q, w, e, r;
    tie(q, w, e, r) = it;
    cout << q << " " << w << " " << e << " " << r << endl;
  }
}
