#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "sz:" << v.size() << "\n[";
  for (const auto& p : v) {
    os << p << ",";
  }
  os << "]\n";
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& e : v) {
    is >> e;
  }
  return is;
}
template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
constexpr ll MOD = (ll)1e9 + 7LL;
template <typename T>
constexpr T INF = numeric_limits<T>::max() / 10;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  vector<bool> qq(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    a[i]--;
    qq[a[i]] = 1;
  }
  int x = v[a[0]].size();
  bool flag = 0;
  for (int i = 1; i < m; i++) {
    if (x != v[a[i]].size()) {
      flag = 1;
    }
  }
  if (flag) {
    cout << "No" << endl;
    return 0;
  }
  string ans;
  for (int i = 0; i < x; i++) {
    bool bbflag = 1;
    char p = v[a[0]][i];
    for (int j = 1; j < m; j++) {
      if (p != v[a[j]][i]) {
        bbflag = 0;
      }
    }
    if (bbflag) {
      ans.push_back(p);
    } else {
      ans.push_back('?');
    }
  }
  bool fflag = 0;
  for (int i = 0; i < n; i++) {
    if (qq[i] == 1) continue;
    if (v[i].size() != x) continue;
    bool breakflag = 0;
    for (int j = 0; j < x; j++) {
      if (ans[j] != '?') {
        if (ans[j] != v[i][j]) breakflag = 1;
      }
      if (breakflag) break;
    }
    if (!breakflag) fflag = 1;
  }
  if (fflag) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    cout << ans << endl;
  }
  return 0;
}
