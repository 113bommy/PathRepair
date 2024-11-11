#include <bits/stdc++.h>
using namespace std;
const long long CPU_TIME = 3;
const long long MAX_FILE_SIZE = 1024 * 1024;
template <typename Arg1>
void ZZ(const char* name, Arg1&& arg1) {
  std::cerr << name << " = " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void ZZ(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " = " << arg1;
  ZZ(comma, args...);
}
const long long MOD = 1000000007LL;
const long long MAX = 100010LL;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
T power(T x, T y, long long m = MOD) {
  T ans = 1;
  x %= m;
  while (y > 0) {
    if (y & 1LL) ans = (ans * x) % m;
    y >>= 1LL;
    x = (x * x) % m;
  }
  return ans % m;
}
template <typename T>
istream& operator>>(istream& cin, vector<T>& a) {
  for (auto& i : a) cin >> i;
  return cin;
}
template <typename T>
ostream& operator<<(ostream& cout, vector<T>& a) {
  for (auto& i : a) cout << i << " ";
  return cout;
}
int t;
int n;
vector<int> a;
int dp[200005][2];
int ans(int i, int j) {
  if (i < 0) return 1e9 + 7;
  if (i == 0) {
    return a[i];
  }
  if (i == 1) {
    if (j == 0)
      return min(ans(0, 0), ans(0, 1));
    else
      return a[i] + min(ans(0, 0), ans(0, 1));
  }
  int& res = dp[i][j];
  if (res != -1) return res;
  if (j == 0)
    res = min(ans(i - 1, 1), ans(i - 2, 1));
  else if (j == 1)
    res = min(ans(i - 1, 0) + a[i], ans(i - 2, 0) + a[i - 1] + a[i]);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    a.assign(n, 0);
    for (int i(0); i <= ((n)-1); i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << min(ans(n - 1, 0), ans(n - 1, 1)) << "\n";
  }
  return 0;
}
