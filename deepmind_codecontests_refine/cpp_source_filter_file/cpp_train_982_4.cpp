#include <bits/stdc++.h>
using namespace std;
template <typename T, size_t size>
ostream &operator<<(ostream &os, const array<T, size> &arr) {
  os << '{';
  string sep;
  for (const auto &x : arr) os << sep << x, sep = ", ";
  return os << '}';
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
const int MAX = 1000010;
const int MOD2 = 998244353;
const int MOD1 = 1000000007;
const int INF = 0x3f;
const long long int LLINF = 0x3f3f3f3f3f3f3f3fll;
const long double EPS = 1e-7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(25);
  cerr << fixed << setprecision(10);
  long long int n, k, d;
  cin >> n >> k >> d;
  long long int a = 1;
  for (int i = 1; i <= d; i++) {
    a *= k;
    if (a <= n) continue;
    break;
  }
  if (a <= n) {
    cout << -1 << "\n";
    return 0;
  }
  vector<vector<int>> ans(d, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    int x = i;
    for (int j = 0; j < d; j++) {
      ans[j][i] = x % k + 1;
      x /= k;
    }
  }
  42;
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < n; j++) cout << ans[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
