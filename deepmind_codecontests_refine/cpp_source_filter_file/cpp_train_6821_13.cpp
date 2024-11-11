#include <bits/stdc++.h>
using namespace std;
bool func(vector<pair<int, int> > vd, vector<pair<int, int> > vu) {
  for (int i = 0; i < vd.size(); i++) {
    if ((vd[i].first < vu[i].first && vd[i].second < vu[i].second) ||
        (vd[i].first > vu[i].first && vd[i].second > vu[i].second)) {
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, i, j, k, n, m,
      a = 1, b = 1, c, p, prev, q, r, width, o, rc, height, mx = -999999999,
      mn = 99999999, ct = 0, ans = 0, flag = 1, sum = 0, pos1, pos2;
  cin >> n >> m >> k;
  std::vector<pair<long long int, long long int> > row(n), col(m);
  for (i = 0; i < k; i++) {
    cin >> o >> rc >> a;
    if (o == 1) {
      row[rc - 1] = {a, i};
    } else {
      col[rc - 1] = {a, i};
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (col[j].second > row[i].second)
        cout << col[j].first << " ";
      else
        cout << row[i].first << " ";
    }
    cout << "\n";
  }
  return 0;
}
