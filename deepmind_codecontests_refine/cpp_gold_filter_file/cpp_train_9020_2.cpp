#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long SIZE = 100000;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const long double PI = acos(-1);
const long long MAXN = numeric_limits<long long>::max();
template <class T>
T maxT(T a, T b) {
  return (a > b ? a : b);
}
template <class T>
T minT(T a, T b) {
  return (a < b ? a : b);
}
template <class T>
void setmin(T &a, T b) {
  a = (a > b ? a : b);
}
template <class T>
void setmax(T &a, T b) {
  a = (a < b ? a : b);
}
void fileio() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug.txt", "w", stderr);
}
void ofileio() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
void clock_out() {
  cerr << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  map<long long, long long> dp;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    dp[a[i]] = 0;
  }
  long long res = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
    if (res < dp[a[i]]) {
      res = dp[a[i]];
      mx = a[i];
    }
  }
  cout << res << "\n";
  vector<long long> pos;
  for (long long i = n - 1; i >= 0; i--) {
    if (a[i] == mx) {
      pos.push_back(i + 1);
      mx--;
    }
  }
  reverse((pos).begin(), (pos).end());
  for (auto c : pos) cout << c << " ";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  1;
  long long t = 1;
  while (t--) {
    solve();
  }
  1;
  return 0;
}
