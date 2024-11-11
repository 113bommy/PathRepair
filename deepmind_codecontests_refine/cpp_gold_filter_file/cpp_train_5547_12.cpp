#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T>
ostream& operator<<(ostream& os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, unordered_set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, multiset<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream& operator<<(ostream& os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class T>
void RV(vector<T>& v) {
  for (auto& c : v) cin >> c;
}
template <class T>
void RV(vector<vector<T>>& v) {
  for (auto& c : v) RV(c);
}
auto clk = clock();
long long int mod = 1e9 + 7;
const long long inf = 1e17;
const double eps = 1e-6;
const long long int LOGN = 25;
template <class T, class U>
T pow_mod(T a, T b, long long int m = mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = ((long long)res * a) % m;
    a = ((long long)a * a) % m;
    b >>= 1;
  }
  return res;
}
template <typename T>
T inv(T a) {
  return pow_mod(a, mod - 2, mod);
}
template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
template <typename T>
string to_bin(T num) {
  string binary = "";
  while (num) {
    binary += (num % 2 == 1 ? "1" : "0");
    num >>= 1;
  }
  reverse(binary.begin(), binary.end());
  return binary;
}
const long long int R = 510;
const long long int N = 1e5 + 10;
long long int g[N][2];
long long int dp[N];
long long int arr[N];
long long int dist(long long int i, long long int j) {
  if (j == 0) {
    return abs(g[i][0] - 1) + abs(g[i][1] - 1);
  }
  return abs(g[i][0] - g[j][0]) + abs(g[i][1] - g[j][1]);
}
void __Solve__() {
  long long int r, n;
  cin >> r >> n;
  for (long long int i = 1; i <= n; i++) {
    cin >> arr[i] >> g[i][0] >> g[i][1];
  }
  dp[0] = 0;
  long long int mx = -inf;
  for (long long int i = 1; i <= n; i++) {
    dp[i] = -inf;
    for (long long int j = max(0LL, i - 2 * r); j < i; j++) {
      if (arr[i] - arr[j] >= dist(i, j)) {
        dp[i] = max(dp[i], 1 + dp[j]);
      }
    }
    dp[i] = max(dp[i], 1 + mx);
    if ((i - 2 * r) >= 0) {
      mx = max(mx, dp[i - 2 * r]);
    }
  }
  cout << *max_element(dp, dp + n + 1) << "\n";
}
signed main() {
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int test_case = 1;
  for (long long int i = 0; i < test_case; i++) {
    __Solve__();
  }
}
