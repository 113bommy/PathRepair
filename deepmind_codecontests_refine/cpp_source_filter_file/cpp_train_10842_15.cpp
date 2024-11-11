#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
template <class T>
using V = vector<T>;
template <class T1, class T2>
istream& operator>>(istream&, pair<T1, T2>&);
template <class T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& it : v) {
    in >> it;
  }
  return in;
}
template <class T1, class T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  return in >> p.first >> p.second;
}
template <class T1, class T2>
ostream& operator<<(ostream&, const pair<T1, T2>&);
template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  for (int i = 0; i < v.size(); ++i) {
    out << v[i];
    if (i + 1 != v.size()) {
      out << ", ";
    }
  }
  out << "]";
  return out;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& p) {
  return out << "{" << p.first << ", " << p.second << "}";
}
struct _ {
  _() {
    ios_base::Init();
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(11);
    if (false) cerr << fixed << setprecision(11);
  }
  ~_() {}
} _;
const int kInf = 1e9 + 1e3;
const long long kLInf = 4e18;
const int kMod = 1e9 + 7;
void solve() {
  for (int i = 20; i < 51; ++i) {
    cout << int(!!(((min(i, 25) + i) % (2 + i % 3)))) << endl;
  }
}
int main() {
  solve();
  return 0;
}
