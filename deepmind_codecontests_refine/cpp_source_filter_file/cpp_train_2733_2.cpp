#include <bits/stdc++.h>
using namespace std;
bool comp(pair<pair<int, int>, pair<int, int> > &p1,
          pair<pair<int, int>, pair<int, int> > &p2) {
  if (p1.first.first == p2.first.first) {
    if (p1.second.first == p2.second.first)
      return p1.second.second < p2.second.second;
    return p1.second.first > p2.second.first;
  }
  return p1.first.first < p2.first.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<pair<int, int>, pair<int, int> > > vt;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[i]) {
        vt.push_back({{i, a[i]}, {a[j], j}});
      }
    }
  }
  sort(vt.begin(), vt.end(), comp);
  cout << vt.size() << "\n";
  for (int i = 0; i < vt.size(); i++) {
    cout << vt[i].first.first + 1 << " " << vt[i].second.second + 1 << "\n";
  }
  return 0;
}
