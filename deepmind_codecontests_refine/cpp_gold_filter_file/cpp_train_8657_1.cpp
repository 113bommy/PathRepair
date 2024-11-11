#include <bits/stdc++.h>
using namespace std;
bool check_it(vector<pair<int, int> > &v, int l) {
  vector<int> temp;
  for (int i = 0; i < v.size(); i++) {
    if (i == l) continue;
    temp.push_back(v[i].first);
  }
  int d = temp[1] - temp[0];
  for (int i = 0; i < temp.size() - 1; i++) {
    if (temp[i] + d != temp[i + 1]) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back({x, i});
  }
  sort(v.begin(), v.end());
  if (n == 2) {
    cout << v[0].second + 1 << endl;
    return 0;
  }
  vector<pair<int, int> > tt;
  for (int i = 0; i < 3; i++) {
    tt.push_back(v[i]);
  }
  for (int l = 0; l < 3; l++) {
    if (check_it(v, l)) {
      cout << v[l].second + 1 << endl;
      return 0;
    }
  }
  int d = v[1].first - v[0].first;
  int id = -1;
  for (int i = 0; i < n - 1; i++) {
    if (v[i].first + d != v[i + 1].first) {
      id = i + 1;
      break;
    }
  }
  if (id == -1) {
    cout << v[0].second + 1 << endl;
    return 0;
  } else {
    if (check_it(v, id)) {
      cout << v[id].second + 1 << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
