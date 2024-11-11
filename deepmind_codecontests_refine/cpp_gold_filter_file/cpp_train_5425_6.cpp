#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
const char nl = '\n';
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using str = string;
str to_string(char c) { return str(1, c); }
str to_string(bool b) { return b ? "true" : "false"; }
str to_string(const char* second) { return (str)second; }
str to_string(str second) { return second; }
template <class A>
str to_string(complex<A> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}
str to_string(vector<bool> v) {
  str res = "{";
  for (int i = 0; i < (int)v.size(); i++) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t SZ>
str to_string(bitset<SZ> b) {
  str res = "";
  for (int i = 0; i < b.size(); i++) res += char('0' + b[i]);
  return res;
}
template <class A, class B>
str to_string(pair<A, B> p);
template <class T>
str to_string(T v) {
  bool fst = 1;
  str res = "{";
  for (const auto& x : v) {
    if (!fst) res += ", ";
    fst = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <class A, class B>
str to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
const int mxN = 2069;
int n, m;
int p[mxN], done[mxN];
pii x[mxN];
signed main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < 2 * n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (p[a] > p[b]) swap(a, b);
    x[i].first = a, x[i].second = b;
  }
  int t;
  cin >> t;
  t--;
  int force = -1;
  for (int j = 0; j < 2 * n; j++) {
    0;
    if (!t) {
      if (force != -1) {
        cout << force + 1 << endl;
        done[force] = 1;
        t ^= 1;
        continue;
      }
      bool flag = 0;
      for (int i = 0; i < m; i++) {
        if (!done[x[i].first] && !done[x[i].second]) {
          cout << x[i].second + 1 << endl;
          done[x[i].second] = 1;
          flag = 1;
          break;
        }
      }
      if (flag) {
        t ^= 1;
        continue;
      }
      int ma = 0;
      int pos = 0;
      for (int i = 0; i < 2 * n; i++) {
        if (!done[i] && p[i] > ma) {
          pos = i;
          ma = p[i];
        }
      }
      done[pos] = 1;
      cout << pos + 1 << endl;
    } else {
      force = -1;
      int ne;
      cin >> ne;
      ne--;
      done[ne] = 1;
      for (int i = 0; i < m; i++) {
        if (x[i].first == ne && !done[x[i].second]) {
          force = x[i].second;
        }
        if (x[i].second == ne && !done[x[i].first]) {
          force = x[i].first;
        }
      }
    }
    t ^= 1;
  }
}
