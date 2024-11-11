#include <bits/stdc++.h>
using namespace std;
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(";
  os << v.first << "," << v.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  long long sz = v.size();
  for (long long i = 0; i < sz; ++i) {
    os << v[i];
    if (i != sz - 1) os << ",";
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const list<T>& v) {
  os << "[";
  long long sz = v.size();
  long long i = 0;
  for (auto x : v) {
    os << x;
    if (i != sz - 1) os << ",";
    ++i;
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  T last = *v.rbegin();
  os << "[";
  for (auto it : v) {
    os << it;
    if (it != last) os << ",";
  }
  os << "]\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  for (auto it : v) {
    os << it.first << " : " << it.second << "\n";
  }
  return os;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) {
      res = (res * a) % 1000000007;
    }
    b /= 2;
    a = (a * a) % 1000000007;
  }
  return res;
}
uint64_t toint(const string& s) {
  istringstream src(s);
  uint64_t v;
  src >> v;
  return v;
}
string tostring(uint64_t v) {
  ostringstream src;
  src << v;
  return src.str();
}
vector<long long> g[100005];
vector<long long> par(100005, 0), sz(100005, 0);
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, res = 0;
    cin >> n;
    vector<long long> a(n), push_front(n);
    for (decltype(0) i = 0; i <= n - 1; i++) {
      cin >> a[i];
      push_front[i] = a[i];
    }
    for (decltype(n - 2) i = n - 2; i >= 0; i--) {
      push_front[i] += push_front[i + 1];
      res = max({push_front[i], res, push_front[n - 1]});
    }
    cout << res << "\n";
  }
  return 0;
}
