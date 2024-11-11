#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const int mod = 1e9 + 7;
long long binpow(long long num, long long pow);
int extendedEuclid(int a, int b, int &x, int &y);
inline int mul(int a, int b) { return (a * 1ll * b) % mod; }
inline int add(int a, int b) { return (a + 0ll + b) % mod; }
inline int sub(int a, int b) { return ((a + 0ll - b) % mod + mod) % mod; }
inline void intarr(vector<int> &a) {
  for (auto &i : a) cin >> i;
}
inline void larr(vector<long long> &a) {
  for (auto &i : a) cin >> i;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m + 1, vector<int>(n));
  for (int i = (int)0; i < (int)m; i++)
    for (int j = (int)0; j < (int)n; j++) {
      cin >> a[i][j];
      a[m][j] += a[i][j];
    }
  vector<int> r;
  int ans = INT_MAX;
  for (int i = (int)0; i < (int)n - 1; i++) {
    int l = 0;
    vector<int> lr;
    vector<pair<int, int>> diff;
    for (int j = (int)0; j < (int)m; j++) {
      diff.emplace_back(a[j][n - 1] - a[j][i], j);
    }
    sort(diff.begin(), diff.end());
    int d = a[m][n - 1] - a[m][i];
    for (int i = (int)m - 1; i > (int)-1; i--) {
      if (d <= 0) break;
      d -= diff[i].first;
      l++;
      lr.emplace_back(diff[i].second + 1);
    }
    if (l < ans) {
      ans = l;
      r = lr;
    }
  }
  cout << ans << "\n";
  for (int i : r) cout << i << " ";
  cout << "\n";
}
int main() {
  auto start = high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cerr << duration.count() << " microseconds\n";
  return 0;
}
long long binpow(long long num, long long pow) {
  if (pow == 0) return 1;
  long long val = binpow(num, pow / 2);
  val *= val;
  if (pow & 1) val *= num;
  return val;
}
int extendedEuclid(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  int x1, y1;
  int d = extendedEuclid(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
