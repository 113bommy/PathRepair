#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<pair<int, int>> c;
    for (int(j) = 0; (j) < (n); (j)++) {
      int k;
      cin >> k;
      vector<int> temp;
      for (int(j) = 0; (j) < (k); (j)++) {
        int a;
        cin >> a;
        temp.push_back(a);
      }
      int ma = 0;
      for (int(j) = 0; (j) < (k); (j)++) {
        ma = (ma < temp[j] - j + 1 ? temp[j] - j + 1 : ma);
      }
      int pos = 0;
      for (int(j) = 0; (j) < (k); (j)++) {
        if (ma == temp[j] - j + 1) {
          pos = j;
          break;
        }
      }
      c.push_back(make_pair(ma, ma + k));
    }
    sort(c.begin(), c.end());
    int ans = c[0].first;
    for (int(i) = 0; (i) < (n - 1); (i)++) {
      if (c[i].second > c[i + 1].first) {
        c[i + 1].second = c[i].second + c[i + 1].second - c[i + 1].first;
      } else {
        ans += c[i + 1].first - c[i].second;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
