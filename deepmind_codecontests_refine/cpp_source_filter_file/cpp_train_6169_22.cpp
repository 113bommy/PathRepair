#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline void prn(vector<T>& v) {
  int n = (int)v.size();
  for (int i = (0); i < ((n)); i++) cout << v[i] << ' ';
}
template <class T>
inline void printv(vector<T>& v) {
  int n = (int)v.size();
  for (int i = (0); i < ((n)); i++) cout << v[i] << (i == n - 1 ? '\n' : ' ');
}
template <class T>
inline void printvv(vector<vector<T>>& v) {
  for (auto u : v) printv(u);
}
template <class T>
inline void printlnv(vector<T>& v) {
  int n = (int)v.size();
  for (int i = (0); i < ((n)); i++) cout << v[i] << '\n';
}
const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000001000000001LL;
void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(numeric_limits<double>::max_digits10);
  solve();
  return 0;
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (n % 2 == 0 ? "YES" : "NO") << '\n';
  }
}
