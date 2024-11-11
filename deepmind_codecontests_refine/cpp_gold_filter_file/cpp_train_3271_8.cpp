#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<pair<int, int> > res;
int main() {
  cin >> n >> m >> k;
  if (k == 0) {
    for (int i = m - 1; i >= 0; i--) {
      for (int j = 0; j < i; j++) {
        res.push_back(make_pair(j, j + 1));
      }
    }
  } else {
    for (int i = 0; i < m; i++) {
      for (int j = m - 2; j >= i; j--) {
        res.push_back(make_pair(j + 1, j));
      }
    }
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
  }
  return 0;
}
