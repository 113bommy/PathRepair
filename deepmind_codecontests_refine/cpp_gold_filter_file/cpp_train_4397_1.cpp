#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int MAXN = 3e5 + 10;
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto i = begin(v); i != end(v); i++) is >> *i;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (auto i = begin(v); i != end(v); i++)
    os << *i << (i == end(v) - 1 ? "\n" : " ");
  return os;
}
template <typename T>
inline void rd(T &s) {
  s = 0;
  T t = 1, k = getchar();
  for (; k < '0' || k > '9'; k = getchar())
    if (k == '-') t = -1;
  for (; k >= '0' && k <= '9'; k = getchar())
    s = (s << 1) + (s << 3) + (k ^ 48);
  s *= t;
}
void solve() {
  int n;
  cin >> n;
  vi a(n), b(n);
  cin >> a >> b;
  sort(begin(a), end(a)), sort(begin(b), end(b));
  for (register int i = 0, ilen = (int)(n); i < ilen; ++i) cout << a[i] << " ";
  cout << '\n';
  for (register int i = 0, ilen = (int)(n); i < ilen; ++i) cout << b[i] << " ";
  cout << '\n';
}
signed main() {
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
