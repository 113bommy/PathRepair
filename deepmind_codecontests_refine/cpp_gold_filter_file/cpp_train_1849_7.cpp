#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 9;
int main() {
  int k;
  cin >> k;
  vector<pair<int, pair<int, int> > > ans;
  for (int e = 0; e < int(k); e++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < int(n); i++) cin >> a[i];
    int s = accumulate(a.begin(), a.end(), 0);
    for (int i = 0; i < int(n); i++) {
      ans.push_back(make_pair(s - a[i], make_pair(e, i)));
    }
  }
  sort(ans.begin(), ans.end());
  for (unsigned int i = 1; i < ans.size(); i++) {
    if (ans[i].first == ans[i - 1].first &&
        ans[i].second.first != ans[i - 1].second.first) {
      cout << "YES" << endl;
      cout << ans[i].second.first + 1 << " " << ans[i].second.second + 1
           << endl;
      cout << ans[i - 1].second.first + 1 << " "
           << ans[i - 1].second.second + 1;
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
