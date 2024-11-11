#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <typename Arg1>
void __p(const char* name, Arg1&& arg1) {
  cout << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __p(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout << arg1 << " ";
  __p(comma + 1, args...);
}
template <typename T>
string toString(T a) {
  return to_string(a);
}
template <typename T>
void toInt(string s, T& x) {
  stringstream str(s);
  str >> x;
}
const long long mod = (1e9) + 7;
const long long inf = 1034567891;
const long long INF = 1234567890123456789ll;
const long long MOD = (1e9) + 7;
const long long MAX = (1e5) + 5;
const long long NN = (1e6) + 1;
inline void rukk(long long& ans, long long M = mod) {
  if (ans >= M) ans -= M;
}
inline void bhagg(long long& ans, long long M = mod) {
  if (ans < 0) ans += M;
}
long long item, cnt, mn, mx, sz, sum;
long long ca, ans, ans1, ans2, ans3, val, num;
long long i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
char ch;
string S;
bool hasTestCases = 1;
long long solve() {
  long long n;
  cin >> n;
  if (n == 1)
    cout << "-1"
         << "\n";
  else {
    vector<long long> dp(n);
    long long s = 0;
    for (long long i = 0; i <= n - 1; ++i) {
      dp[i] = 2;
      s += 2;
    }
    dp[n - 1]++;
    s++;
    if (s % 3 == 0) {
      dp[i - 2] += 2;
    }
    for (long long i = 0; i <= n - 1; ++i) cout << dp[i];
    cout << "\n";
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  if (hasTestCases) cin >> t;
  long long test = t;
  while (t--) {
    solve();
  }
  return 0;
}
