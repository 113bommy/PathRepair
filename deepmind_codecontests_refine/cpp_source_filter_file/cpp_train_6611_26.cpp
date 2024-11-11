#include <bits/stdc++.h>
using namespace std;
map<int, pair<int, int> > ar;
vector<int> ans;
int main() {
  int n, m;
  cin >> n >> m;
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    ar[t].first++;
    ar[t].second = i + 1;
  }
  bool fl = false;
  for (int i = 0; i < m; i++) {
    cin >> t;
    if (ar[t].first == 0) {
      cout << "Impossible";
      return 0;
    }
    if (ar[t].first == 1) {
      ans.push_back(ar[t].second);
    } else {
      fl = true;
    }
  }
  if (fl) {
    cout << "Ambiguity";
    return 0;
  }
  cout << "Possible" << endl;
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  return 0;
}
