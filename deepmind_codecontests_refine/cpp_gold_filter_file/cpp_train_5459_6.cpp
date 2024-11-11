#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 1; i < n; i++) {
    v.push_back(make_pair(i, i + 1));
    for (int j = i + 3; j <= n; j += 2) {
      v.push_back(make_pair(i, j));
    }
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }
  return 0;
}
