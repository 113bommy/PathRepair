#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
template <class T, class U>
void chmax(T& x, U y) {
  if (x < y) x = y;
}
template <class T, class U>
void chmin(T& x, U y) {
  if (y < x) x = y;
}
template <class T>
void mkuni(V<T>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
template <class S, class T>
ostream& operator<<(ostream& o, const pair<S, T>& p) {
  return o << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& vc) {
  o << "{";
  for (const T& v : vc) o << v << ",";
  o << "}";
  return o;
}
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
int query(int x, int y) {
  cout << "? " << x << " " << y << endl;
  int v;
  cin >> v;
  return v;
}
int main() {
  int N;
  cin >> N;
  V<int> a(N), b(N);
  for (int i = 0; i < int(N); i++) a[i] = query(0, i);
  for (int i = 0; i < int(N); i++) b[i] = query(i, 0);
  V<int> p(N), q(N);
  V<int> ans(N);
  int num = 0;
  V<bool> is(N);
  for (int p0 = 0; p0 < int(N); p0++) {
    p[0] = p0;
    for (int i = 0; i < int(N); i++) q[i] = p[0] ^ a[i];
    for (int i = 0; i < int(N); i++) p[i] = q[0] ^ a[i];
    for (int i = 0; i < int(N); i++) is[i] = false;
    bool ok = true;
    for (int i = 0; i < int(N); i++) {
      if (!(0 <= p[i] && p[i] < N)) ok = false;
      if (!(0 <= q[i] && q[i] < N)) ok = false;
    }
    if (ok) {
      for (int i = 0; i < int(N); i++) is[p[i]] = true;
      for (int i = 0; i < int(N); i++)
        if (!is[i]) ok = false;
    }
    if (ok) {
      for (int i = 0; i < int(N); i++)
        if (p[q[i]] != i) ok = false;
    }
    if (ok) {
      ans = p;
      num++;
    }
  }
  cout << "!" << endl;
  cout << num << endl;
  for (int v : ans) cout << v << " ";
  cout << endl;
}
