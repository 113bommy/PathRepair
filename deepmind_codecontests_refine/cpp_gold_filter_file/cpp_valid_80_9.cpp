#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const int mod = 1000000007;
const int N = 3e5, M = N;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "{";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "{";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T, typename second>
ostream& operator<<(ostream& os, const map<T, second>& v) {
  os << "{";
  for (auto it : v) {
    os << "(" << it.first << " : " << it.second << ")";
    if (it != *v.rbegin()) os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T, typename second>
ostream& operator<<(ostream& os, const unordered_map<T, second>& v) {
  os << "{";
  for (auto it : v) {
    os << "(" << it.first << " : " << it.second << ")";
    os << ", ";
  }
  os << "}\n";
  return os;
}
template <typename T, typename second>
ostream& operator<<(ostream& os, const pair<T, second>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  return os;
}
template <typename T>
inline istream& operator>>(istream& in, vector<T>& a) {
  for (auto& x : a) in >> x;
  return in;
}
void run_case() {
  long long int t, i, j, k, p, x, y, u, n, m, w;
  cin >> n;
  string s;
  cin >> s;
  int ok = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') ok = 1;
  }
  u = (n) / 2;
  if (!ok) {
    cout << 1 << " " << u * 2 << " " << 1 << " " << u << endl;
    return;
  }
  for (int i = 0; i < (n + 1) / 2; i++) {
    if (s[i] == '0') {
      cout << i + 1 << " " << n << " " << i + 2 << " " << n << endl;
      return;
    }
  }
  for (int i = (n + 1) / 2; i < n; i++) {
    if (s[i] == '0') {
      cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
      return;
    }
  }
  assert(false);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t;
  for (int T = 1; 1 < t + 1 ? T < t + 1 : T > t + 1;
       1 < t + 1 ? T += 1 : T -= 1) {
    run_case();
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
