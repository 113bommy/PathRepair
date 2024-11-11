#include <bits/stdc++.h>
using namespace std;
const int k = 60;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int n;
  cin >> n;
  vector<pair<int, int>> b;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    b.push_back({val, i});
  }
  sort(b.begin(), b.end());
  set<int> s;
  for (int i = 0; i < n; i++) s.insert(i);
  s.insert(-1);
  s.insert(n);
  vector<long double> zlomok(k + 1, 1);
  for (int i = 1; i <= k; i++) {
    zlomok[i] = zlomok[i - 1] / 2.0;
  }
  long double vys = 0;
  for (int it = 0; it < n; it++) {
    vector<int> l, r;
    int i = b[it].second;
    for (auto p = s.find(i);; p--) {
      l.push_back(*p);
      if (l.size() > k || p == s.begin()) {
        break;
      }
    }
    for (auto p = s.find(i);; p++) {
      r.push_back(*p);
      if (r.size() > k || next(p) == s.end()) {
        break;
      }
    }
    double sucl = 0;
    double sucr = 0;
    for (int li = 0; li < l.size() - 1; li++) {
      sucl += (l[li] - l[li + 1]) * zlomok[li];
    }
    for (int ri = 0; ri < r.size() - 1; ri++) {
      sucr += (r[ri + 1] - r[ri]) * zlomok[ri];
    }
    vys += sucl * sucr * 0.5 * b[it].first;
    s.erase(i);
  }
  vys /= n * 1.0 * n;
  cout << vys << endl;
  return 0;
}
