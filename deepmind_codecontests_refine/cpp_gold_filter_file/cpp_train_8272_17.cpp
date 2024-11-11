#include <bits/stdc++.h>
using namespace std;
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return (string)s; }
string to_string(string s) { return s; }
template <class A>
string to_string(complex<A> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}
string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < (int)v.size(); i++) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t SZ>
string to_string(bitset<SZ> b) {
  string res = "";
  for (size_t i = 0; i < SZ; i++) res += char('0' + b[i]);
  return res;
}
template <class A, class B>
string to_string(pair<A, B> p);
template <class T>
string to_string(T v) {
  bool fst = 1;
  string res = "{";
  for (const auto& x : v) {
    if (!fst) res += ", ";
    fst = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <class A, class B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
const int MAXN = 1e6 + 10;
int p[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  if (k == 1) {
    cout << string(n, '1') << '\n';
    return 0;
  }
  vector<int> z(n + 1);
  int l = 0, r = 0;
  z[0] = n;
  for (int i = 1; i < n; i++) {
    if (r < i) {
      l = i, r = i - 1;
      while (r < n - 1 && s[r + 1] == s[r - l + 1]) {
        r++;
      }
      z[i] = r - l + 1;
    } else {
      int kk = i - l;
      if (z[kk] >= r - i + 1) {
        l = i;
        while (r < n - 1 && s[r + 1] == s[r - l + 1]) {
          r++;
        }
        z[i] = r - l + 1;
      } else {
        z[i] = z[kk];
      }
    }
  }
  for (int i = 1; i * k <= n; i++) {
    if (z[i] >= (k - 1) * i) {
      l = i * k, r = i * k + min(i, z[i * k]);
      p[l]++, p[r + 1]--;
    }
  }
  for (int i = 1; i <= n; i++) {
    p[i] += p[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    cout << (p[i] > 0);
  }
  cout << '\n';
}
