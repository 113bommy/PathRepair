#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
const long long INFll = 1ll * INF * INF;
const long double ldINF = 1e+018;
const long double EPS = 0.000000001;
template <typename T>
ostream& operator<<(ostream& out, pair<T, T>& a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T>
istream& operator>>(istream& in, pair<T, T>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> a) {
  for (int i = 0; i < a.size(); ++i)
    if (i == a.size() - 1)
      out << a[i];
    else
      out << a[i] << " ";
}
int v[4][4];
int n, a, b, c, d;
bool check(int cur) {
  v[0][0] = cur;
  v[0][2] = cur + b - c;
  if (v[0][2] <= 0 || v[0][2] > n) return false;
  v[2][0] = v[0][0] + a - d;
  if (v[2][0] <= 0 || v[2][0] > n) return false;
  v[2][2] = v[0][2] + a - d;
  if (v[2][2] <= 0 || v[2][2] > n) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  set<int> s;
  map<int, int> l, r;
  s.insert(a[0]);
  vector<int> ans(n);
  for (int i = 1; i < n; i++) {
    auto d = s.upper_bound(a[i]);
    auto pr = d;
    pr--;
    bool left = false, right = false;
    int anc;
    if (d == s.begin()) anc = *d, left = true;
    if (d == s.end()) anc = *pr, right = true;
    if (!left && !right) {
      if (r[*pr] == 1)
        anc = *d, left = true;
      else
        anc = *pr, right = true;
    }
    s.insert(a[i]);
    ans[i] = anc;
    if (left)
      l[anc] = 1;
    else
      r[anc] = 1;
  }
  for (int i = 1; i < n; i++) cout << ans[i] << ' ';
  return 0;
}
