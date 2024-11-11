#include <bits/stdc++.h>
using namespace std;
pair<int, int> ust[5005], st[5005];
int n, m, k, t, r, c;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> t >> r >> c;
    r--;
    if (t == 1) {
      ust[r] = make_pair(c, i);
    } else {
      st[r] = make_pair(c, i);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (st[j].second > ust[i].second)
        cout << st[j].first << ' ';
      else
        cout << ust[i].first << ' ';
    }
    cout << endl;
  }
  return 0;
}
