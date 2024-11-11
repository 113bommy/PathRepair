#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long linf = 1LL << 62;
const int MAX = 510000;
long long dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
long long dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const double pi = acos(-1);
const double eps = 1e-7;
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  } else
    return false;
}
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  } else
    return false;
}
template <typename T>
inline void print(T &a) {
  for (int i = 0; i < (a.size()); i++) cout << a[i] << " ";
  cout << "\n";
}
template <typename T1, typename T2>
inline void print2(T1 a, T2 b) {
  cout << a << " " << b << "\n";
}
template <typename T1, typename T2, typename T3>
inline void print3(T1 a, T2 b, T3 c) {
  cout << a << " " << b << " " << c << "\n";
}
long long pcount(long long x) { return __builtin_popcountll(x); }
const int mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < (n); i++) cin >> a[i];
  sort((a).begin(), (a).end());
  long long s = 0;
  for (int i = 0; i < (n - 1); i++) s += a[i];
  if (s <= a.back())
    cout << "T"
         << "\n";
  else {
    s += a.back();
    if (s & 1)
      cout << "T"
           << "\n";
    else
      cout << "HL"
           << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
