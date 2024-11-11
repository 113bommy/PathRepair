#include <bits/stdc++.h>
using namespace std;
bool sr(pair<double, int> x, pair<double, int> y) {
  if (x.first > y.first) return true;
  if ((x.first == y.first) && (x.second < y.second)) return true;
  return false;
}
int main() {
  int n, k, t1, t2;
  cin >> n >> t1 >> t2 >> k;
  pair<double, int> tmp;
  vector<pair<double, int> > tab;
  for (int i = 0; i < n; i++) {
    int v1, v2;
    double t, tt;
    cin >> v1 >> v2;
    t = ((double)v1 * t1 * (100 - k)) / 100 + v2 * t2;
    tt = ((double)v2 * t2 * (100 - k)) / 100 + v1 * t1;
    tmp.second = i + 1;
    tmp.first = max(t, tt);
    tab.push_back(tmp);
  }
  sort(tab.begin(), tab.end(), sr);
  for (int i = 0; i < n; i++) {
    cout << tab[i].second << " ";
    cout.precision(2);
    cout << fixed << tab[i].first << '\n';
  }
  return 0;
}
