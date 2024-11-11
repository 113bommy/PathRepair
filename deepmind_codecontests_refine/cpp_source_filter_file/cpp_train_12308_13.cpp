#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(const vector<T>& s) {
  for (auto x : s) cout << x << " ";
  cout << endl;
}
template <class T>
void print(const T* s, int n) {
  for (int i = 0; i < n; i++) cout << s[i] << ' ';
  cout << endl;
}
template <class T>
void print(vector<vector<T>> s) {
  for (int i = 0; i < s.size(); i++) print(s[i]);
}
int solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> s(n);
  for (int i = 0; i < n; i++) cin >> s[i].first;
  for (int i = 0; i < n; i++) cin >> s[i].second;
  sort(s.begin(), s.end());
  set<pair<int, int>> lst;
  int cur = 0, asasddlsa = 0;
  long long res = 0;
  while (cur < n) {
    while (lst.size() && asasddlsa < s[cur].first) {
      auto [val, x] = *lst.rbegin();
      lst.erase(--lst.end());
      res += (long long)(asasddlsa - x) * val;
      asasddlsa++;
    }
    asasddlsa = s[cur].first;
    int t = 0;
    while (t + cur < n && s[cur].first == s[cur + t].first) t++;
    for (int i = 0; i < t; i++)
      lst.insert({s[cur + i].second, s[cur + i].first});
    cur += t;
  }
  while (lst.size()) {
    auto [val, x] = *lst.rbegin();
    lst.erase(--lst.end());
    res += (long long)(asasddlsa - x) * val;
    asasddlsa++;
  }
  cout << res << endl;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int t = 1;
  while (t--) solve();
  return 0;
}
