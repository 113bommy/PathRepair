#include <bits/stdc++.h>
using namespace std;
pair<int, int> ust[5005], st[5005];
int n, m, k, t, r, c;
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    cin >> t >> r >> c;
    r--;
    if (t == 2) {
      ust[r] = make_pair(c, i);
    } else {
      st[r] = make_pair(c, i);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (st[i].second > ust[j].second)
        cout << st[i].first << ' ';
      else
        cout << ust[j].first << ' ';
    }
    cout << endl;
  }
  return 0;
}
