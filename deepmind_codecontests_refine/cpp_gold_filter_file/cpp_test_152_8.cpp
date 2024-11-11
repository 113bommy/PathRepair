#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v) in >> x;
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &v) {
  for (auto &x : v) out << x << " ";
  return out;
}
template <typename Iterable>
void prnv(const Iterable &iterable, ostream &out = cout) {
  if (iterable.begin() == iterable.end()) {
    out << '\n';
    return;
  }
  auto x = iterable.begin();
  out << *x;
  for (++x; x != iterable.end(); ++x) out << ' ' << *x;
  out << '\n';
}
void prn(char en = '\n') { cout << en; }
template <typename T, typename... Args>
void prn(T x, Args... args) {
  cout << x << " ";
  prn(args...);
}
void dbg() { cerr << '\n'; }
template <typename T, typename... Args>
void dbg(T x, Args... args) {}
const int N = (int)1e6 + 5;
int dp[2][N], v[2][N];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> v[0][i];
    v[1][i] = -v[0][i];
  }
  dp[0][0] = dp[1][0] = -N;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      dp[j][i] = N;
      for (int k = 0; k < 2; ++k) {
        if (v[j][i] >= v[k][i - 1]) {
          dp[j][i] = min(dp[j][i], dp[k][i - 1]);
        }
        if (v[j][i] >= dp[k][i - 1]) {
          dp[j][i] = min(dp[j][i], v[k][i - 1]);
        }
      }
    }
  }
  if (dp[0][n - 1] >= N && dp[1][n - 1] >= N) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector<int> ret;
  int j = 0;
  if (dp[j][n - 1] >= N) j = 1;
  ret.push_back(v[j][n - 1]);
  for (int i = n - 1; i > 0; --i) {
    if (v[j][i] >= v[j ^ 1][i - 1] && dp[j][i] == dp[j ^ 1][i - 1]) {
      j ^= 1;
    }
    if (v[j][i] >= dp[j ^ 1][i - 1] && dp[j][i] == v[j ^ 1][i - 1]) {
      j ^= 1;
    }
    ret.push_back(v[j][i - 1]);
  }
  reverse(ret.begin(), ret.end());
  cout << ret << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
