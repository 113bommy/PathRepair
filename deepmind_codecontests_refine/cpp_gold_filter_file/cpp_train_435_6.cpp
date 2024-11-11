#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
template <class T>
inline T biton(T n, T pos) {
  return n | ((T)1 << pos);
}
template <class T>
inline T bitoff(T n, T pos) {
  return n & ~((T)1 << pos);
}
template <class T>
inline T ison(T n, T pos) {
  return (bool)(n & ((T)1 << pos));
}
template <class T>
inline T gcd(T a, T b) {
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <class T>
inline T bigmod(T p, T e, T m) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % m;
    p = (p * p) % m;
  }
  return (T)ret;
};
void solve() {
  string s, c;
  cin >> s >> c;
  if (s < c) {
    cout << s << endl;
    return;
  }
  int n = (int)s.size();
  map<char, vector<int>> mn;
  map<char, set<char>> st;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i] >= s[j]) {
        if (st[s[i]].count(s[j]) == 0) {
          mn[s[i]].push_back({j});
          st[s[i]].insert(s[j]);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (auto m : mn) {
      for (auto j : m.second) {
        swap(s[i], s[j]);
        if (s < c) {
          cout << s << endl;
          return;
        }
        swap(s[i], s[j]);
      }
    }
  }
  cout << "---" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(10);
  cout.tie(nullptr);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
