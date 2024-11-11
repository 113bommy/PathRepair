#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vl = vector<long long>;
using pii = pair<int, int>;
char el = '\n';
char esp = ' ';
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
ostream& operator<<(ostream& os, const vector<int>& v) {
  for (auto const& i : v) {
    os << i << " ";
  }
  os << '\n';
  return os;
}
string yes = "YES";
string no = "NO";
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  cin >> s;
  int n = s.size();
  vector<pair<char, int>> v;
  string cur = "";
  for (int i = 0; i < n; i++) {
    if (cur.size()) {
      if (cur.back() != s[i]) {
        v.push_back({cur[0], cur.size()});
        cur = "";
      }
    }
    cur += s[i];
  }
  int ans = 0;
  v.push_back({cur[0], cur.size()});
  vector<pair<char, int>> v1;
  while (v.size() > 1) {
    v1.clear();
    for (int i = 0; i < v.size(); i++) {
      if (i == 0 || i == v.size() - 1) {
        v[i].second -= 1;
      } else {
        v[i].second = -2;
      }
    }
    for (int i = 0; i < v.size(); i++) {
      if (v1.size() && v[i].second > 0) {
        if (v1.back().first == v[i].first) {
          v1.back().second += v[i].second;
        } else {
          v1.push_back(v[i]);
        }
      } else if (v[i].second > 0) {
        v1.push_back(v[i]);
      }
    }
    v1.swap(v);
    ans++;
  }
  cout << ans << el;
}
