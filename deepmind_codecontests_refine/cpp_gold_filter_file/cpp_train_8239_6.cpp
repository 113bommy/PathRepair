#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x, ts = 0, als, alst = 0;
  cin >> n;
  vector<pair<int, int> > vec;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    cin >> x;
    ts += x;
    vec.push_back(make_pair(x, i + 1));
  }
  als = vec[0].first;
  alst = als;
  sort(vec.begin(), vec.end());
  for (int j = 0; j < n; j++) {
    if ((2 * alst) > ts) break;
    if ((2 * vec[j].first) <= als) {
      alst += vec[j].first;
      ans.push_back(vec[j].second);
    } else
      break;
  }
  ans.push_back(1);
  if ((2 * alst) <= ts)
    cout << 0 << endl;
  else {
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
  }
  return 0;
}
