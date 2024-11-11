#include <bits/stdc++.h>
using namespace std;
int n = 8, m = 8, ans1 = 1e9, ans2 = 1e9;
string c;
vector<pair<int, int> > d;
vector<pair<int, int> > a;
int main() {
  for (int i = 0; i < n; i++) {
    cin >> c;
    for (int q = 0; q < m; q++)
      if (c[q] == 'B')
        d.push_back(make_pair(i, q));
      else if (c[q] == 'W')
        a.push_back(make_pair(i, q));
  }
  for (int i = d.size() - 1; i >= 0; i--) {
    int k = 0;
    for (int q = 0; q < a.size(); q++)
      if (a[q].second == d[i].second && a[q].first > d[i].first) {
        k = 1;
        break;
      }
    if (k == 0) {
      ans1 = d[i].first;
      break;
    }
  }
  for (int i = 0; i < a.size(); i++) {
    int k = 0;
    for (int q = 0; q < d.size(); q++)
      if (a[i].second == d[q].second && a[q].first > d[i].first) {
        k = 1;
        break;
      }
    if (k == 0) {
      ans2 = a[i].first;
      break;
    }
  }
  if (ans1 == 1e9) {
    cout << "A";
    return 0;
  }
  if (ans2 == 1e9) {
    cout << "B";
    return 0;
  }
  if (n - ans1 <= ans2) {
    cout << "B";
    return 0;
  }
  cout << "A";
  return 0;
}
