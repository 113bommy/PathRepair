#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  pair<int, int> p(-1, -1);
  vector<int> res(n, -1);
  for (int i = 0; i < n; ++i) {
    if (a[i].first != p.first) {
      if (a[i].second < p.second)
        res[a[i].second] = p.second - a[i].second - 1;
      else {
        p = a[i];
      }
    } else {
      if (a[i].second < p.second) {
        res[a[i].second] = p.second - a[i].second - 1;
      }
      if (a[i].second > p.second) p.second = a[i].second;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << res[i] << ' ';
  }
}
