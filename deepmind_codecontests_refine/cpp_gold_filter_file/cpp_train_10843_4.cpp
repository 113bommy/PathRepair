#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxheap = priority_queue<T>;
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
  os << "[ ";
  for (auto e : v) os << e << " ";
  return os << "]";
}
template <typename T, typename V>
ostream& operator<<(ostream& os, set<T, V> v) {
  os << "{ ";
  for (auto e : v) os << e << " ";
  return os << "}";
}
template <typename T, typename V, typename S>
ostream& operator<<(ostream& os, map<T, V, S> v) {
  os << "{ ";
  for (auto e : v) os << e << " ";
  return os << "}";
}
template <typename T, typename V>
ostream& operator<<(ostream& os, pair<T, V> x) {
  return os << "( " << x.first << ", " << x.second << " )";
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& e : v) is >> e;
  return is;
}
template <typename T, typename V>
istream& operator>>(istream& is, pair<T, V>& x) {
  return is >> x.first >> x.second;
}
void solve();
int main() { solve(); }
const ll inf = 1e18;
ll safemult(ll a, ll b) {
  if (a == 0 || b == 0) return 0;
  if (a < inf / b) return a * b;
  return inf;
}
void solve() {
  int q;
  cin >> q;
  while (q--) {
    ll a, b, m;
    cin >> a >> b >> m;
    if (0)
      cout << "a"
              " = "
           << (a)
           << " "
              "b"
              " = "
           << (b)
           << " "
              "m"
              " = "
           << (m) << "\n";
    ;
    bool found = false;
    for (int n = 1; n <= 50 && !found; ++n) {
      if (n == 1) {
        if (a == b) {
          cout << 1 << " " << a << "\n";
          found = true;
        }
      } else if (n == 2) {
        if (a + 1 <= b && b <= a + m) {
          cout << 2 << " " << a << " " << b << "\n";
          found = true;
        }
      } else {
        ll A = (1LL << (n - 2)) * a;
        if (A > b) break;
        ll delt = b - A;
        ll lo = (1LL << (n - 2));
        ll hi = safemult(lo, m);
        if (lo <= delt && delt <= hi) {
          found = true;
          ll pw = 1LL << (n - 3);
          cout << n << " ";
          cout << a << " ";
          ll second = a;
          delt -= lo;
          for (int i = 0; i < n - 1; ++i) {
            ll take = delt / pw;
            take = min(take, m - 1);
            cout << second + take + 1LL << " ";
            second += second + take + 1LL;
            delt -= pw * take;
            pw /= 2;
            if (pw == 0) pw = 1;
          }
          cout << "\n";
        }
      }
    }
    if (!found) {
      cout << "-1\n";
    }
  }
}
