#include <bits/stdc++.h>
using namespace std;
template <typename T>
T sqr(T x) {
  return x * x;
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
T chmin(T &x, const T &y) {
  if (y < x) return x = y;
  return x;
}
template <class T>
T chmax(T &x, const T &y) {
  if (x < y) return x = y;
  return x;
}
template <class P, class Q>
ostream &operator<<(ostream &os, const pair<P, Q> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  bool was = false;
  for (const T &x : v) {
    if (was) os << ", ";
    was = true;
    os << x;
  }
  os << '}';
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << '[';
  bool was = false;
  for (const T &x : v) {
    if (was) os << ", ";
    was = true;
    os << x;
  }
  os << ']';
  return os;
}
template <class P, class Q>
ostream &operator<<(ostream &os, const map<P, Q> &m) {
  os << '<';
  bool was = false;
  for (const auto &x : m) {
    if (was) os << ", ";
    was = true;
    os << x;
  }
  os << '>';
  return os;
}
const long long INF = (int)2e9;
const int MAXN = (int)2e5 + 10;
struct Dig {
  int pos;
  long long val;
  Dig() {}
  Dig(long long x, int pos) : pos(pos), val(x) {}
  inline bool operator<(const Dig &other) const {
    return abs(this->val) < abs(other.val);
  }
};
int n, k, x;
bool flag = false;
Dig a[MAXN];
long long ans[MAXN];
multiset<Dig> s;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].val, a[i].pos = i;
    if (a[i].val < 0) flag = true - flag;
    s.insert(a[i]);
  }
  if (!flag) {
    Dig cur = *s.begin();
    s.erase(s.begin());
    bool fl = (cur.val < 0);
    if (cur.val < 0) cur.val *= -1;
    while (k && cur.val > 0) k--, cur.val -= x;
    if (fl) cur.val *= -1;
    s.insert(cur);
  }
  while (k) {
    Dig cur = *s.begin();
    s.erase(s.begin());
    if (cur.val < 0)
      cur.val -= x;
    else
      cur.val += x;
    s.insert(cur);
    k--;
  }
  for (auto it : s) {
    ans[it.pos] = it.val;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
