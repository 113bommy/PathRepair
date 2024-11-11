#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456")
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& t) {
  return in >> t.first >> t.second;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& t) {
  return out << t.first << " " << t.second << endl;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& t) {
  for (long long i = 0; i < t.size(); i++) in >> t[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& t) {
  for (long long i = 0; i < t.size(); i++) out << t[i] << " ";
  return out;
}
signed main() {
  long long rrrr = 1e5;
  long long n, m;
  cin >> n >> m;
  vector<vector<long long> > ve1(n, vector<long long>(2)),
      ve2(m, vector<long long>(2));
  cin >> ve1 >> ve2;
  vector<pair<long long, long long> > eq1(n), eq2(m);
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      vector<long long>&a = ve1[i], b = ve2[j];
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      if (a == b) continue;
      if (a[0] == b[0]) {
        eq1[i].first++;
        eq2[j].first++;
      }
      if (a[0] == b[1]) {
        eq1[i].first++;
        eq2[j].second++;
      }
      if (a[1] == b[0]) {
        eq1[i].second++;
        eq2[j].first++;
      }
      if (a[1] == b[1]) {
        eq1[i].second++;
        eq2[j].second++;
      }
    }
  }
  set<long long> v;
  for (long long i = 0; i < n; ++i) {
    if (eq1[i].first > 0 && eq1[i].second > 0) return cout << -1, 0;
    if (eq1[i].first > 0) v.insert(ve1[i][0]);
    if (eq1[i].second > 0) v.insert(ve1[i][1]);
  }
  for (long long i = 0; i < m; ++i) {
    if (eq2[i].first > 0 && eq2[i].second > 0) return cout << -1, 0;
    if (eq2[i].first > 0) v.insert(ve2[i][0]);
    if (eq2[i].second > 0) v.insert(ve2[i][1]);
  }
  if (v.size() == 1)
    return cout << *v.begin(), 0;
  else
    return cout << 0, 0;
  return 0;
}
