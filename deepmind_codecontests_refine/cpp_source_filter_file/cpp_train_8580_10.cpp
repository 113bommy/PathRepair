#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int x[N];
int main() {
  int n, k;
  while (cin >> n >> k) {
    vector<pair<int, int> > ans, res;
    int max_x = 0;
    for (int i = 0; i < n; i++) {
      cin >> x[i];
      max_x = max(x[i], max_x);
    }
    int sum = 99999;
    for (int i = 0; i <= max_x; i++) {
      res.clear();
      int cont = 0;
      for (int j = 0; j < n; j++) {
        int temp = i + j * k - x[j];
        if (temp != 0) {
          res.push_back(make_pair(j + 1, temp));
          cont++;
        }
      }
      if (cont < sum) {
        sum = cont;
        ans.clear();
        ans.assign(res.begin(), res.end());
      }
    }
    cout << sum << endl;
    for (int i = 0; i < sum; i++) {
      if (ans[i].second > 0) {
        cout << "+ " << ans[i].first << " " << ans[i].second << endl;
      } else {
        int temp = abs(ans[i].second);
        cout << "- " << ans[i].first << ' ' << temp << endl;
      }
    }
  }
  return 0;
}
