#include <bits/stdc++.h>
using namespace std;
template <typename T, typename V>
ostream &operator<<(ostream &os, const pair<T, V> pai) {
  return os << '(' << pai.first << ' ' << pai.second << ')';
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> v) {
  cout << '[';
  for (auto p : v) cout << p << ",";
  cout << "]";
  return os;
}
template <typename T, typename V>
ostream &operator<<(ostream &os, const set<T, V> v) {
  cout << "{";
  for (auto p : v) cout << p << ",";
  cout << "}";
  return os;
}
template <typename T, typename V>
ostream &operator<<(ostream &os, const map<T, V> v) {
  cout << "{";
  for (auto p : v) cout << p << ",";
  cout << "}";
  return os;
}
template <typename T>
void get_max(T &a, T b) {
  a = max(a, b);
}
template <typename T>
void get_min(T &a, T b) {
  a = min(a, b);
}
const int MAXN = 2e5 + 10;
const long long MOD = 998244353;
int n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long ans1 = 0;
  long long ans2 = 1;
  cin >> n >> m;
  ans1 = m * (2 * n - m + 1) / 2;
  int ck = 0;
  int cnt = 1;
  for (int i = 0, _i = (n); i < _i; i++) {
    int x;
    cin >> x;
    if (x < n - m + 1)
      cnt++;
    else {
      if (ck == 0)
        ck = 1;
      else
        ans2 = ans2 * cnt % MOD;
      cnt = 1;
    }
  }
  cout << ans1 << ' ' << ans2;
  return 0;
}
