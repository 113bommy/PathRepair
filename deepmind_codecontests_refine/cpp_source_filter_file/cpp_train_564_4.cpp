#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  ;
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  ;
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
bool check(string& s, string& t, long long i, long long j) {
  if (j == t.size()) return true;
  if (i == s.size()) return false;
  if (s[i] == t[j]) {
    return check(s, t, i + 1, j + 1);
  }
  return check(s, t, i + 1, j);
}
void solve() {
  string s, t;
  cin >> s >> t;
  map<char, long long> m1, m2;
  for (auto a : s) m1[a]++;
  for (auto a : t) m2[a]++;
  if (s.size() == t.size()) {
    long long flag = 0;
    for (auto a : m1) {
      if (a.second != m2[a.first]) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      cout << "need tree";
      return;
    } else {
      cout << "array";
      return;
    }
  } else if (s.size() > t.size()) {
    long long flag = 0;
    for (auto a : m1) {
      if (a.second < m2[a.first]) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      cout << "need tree";
      return;
    } else {
      if (check(s, t, 0, 0)) {
        cout << "automaton";
        return;
      } else {
        cout << "both";
        return;
      }
    }
  } else {
    cout << "need tree";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
}
