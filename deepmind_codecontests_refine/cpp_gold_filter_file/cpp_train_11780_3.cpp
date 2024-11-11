#include <bits/stdc++.h>
using namespace std;
template <class my>
my aabs(const my &a) {
  return (a > 0) ? a : -a;
}
long long int gcd(long long int a, long long int b) {
  return (b == 0) ? a : gcd(b, a % b);
}
long long int LSOne(long long int k) { return (k & (-k)); }
inline int inv(int o) {
  int b = 1000000007, u = 0, v = 1, t, a = o;
  while (a) {
    t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  if (u < 0) u += 1000000007;
  return u;
}
inline int add(const int &a, const int &b) {
  return a + b >= 1000000007 ? a + b - 1000000007 : a + b;
}
inline int sub(const int &a, const int &b) {
  return a - b < 0 ? a - b + 1000000007 : a - b;
}
inline int mul(const int &a, const int &b) {
  return int(a * 1ll * b % 1000000007);
}
inline int _div(const int &a, const int &b) { return mul(a, inv(b)); }
inline int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
void cord(int arr[], int n) {
  int ind = 0;
  map<int, int> mp;
  vector<int> brr(arr, arr + n);
  sort(brr.begin(), brr.end());
  brr.erase(unique(brr.begin(), brr.end()), brr.end());
  for (int i = 0; i < brr.size(); i++) mp[brr[i]] = ind++;
  for (int i = 0; i < n; i++) arr[i] = mp[arr[i]];
}
int par[200010][20], arr[200005], pos[200005], brr[200005], value[2000005];
void com(int diff, int m) {
  for (int i = 1; i < m + 1; i++) {
    arr[i] = i;
    for (int j = 0; j < 20; j++)
      if ((diff >> j) & 1) arr[i] = par[arr[i]][j];
  }
}
void solve() {
  int n, m, q, u, v;
  cin >> n >> m >> q;
  for (int i = 1; i < n + 1; i++) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }
  arr[n + 1] = arr[1];
  for (int i = 0; i < n + 2; i++) value[i] = m + 1;
  for (int i = 1; i < m + 1; i++) cin >> brr[i];
  par[m + 1][0] = m + 1;
  par[0][0] = m + 1;
  for (int i = m; i > 0; i--) {
    par[i][0] = value[arr[pos[brr[i]] + 1]];
    value[brr[i]] = i;
  }
  for (int j = 1; j < 20; j++)
    for (int i = 1; i < m + 2; i++) par[i][j] = par[par[i][j - 1]][j - 1];
  com(n - 1, m);
  for (int i = m - 1; i > 0; i--) arr[i] = min(arr[i + 1], arr[i]);
  while (q--) {
    cin >> u >> v;
    if (v >= arr[u])
      cout << 1;
    else
      cout << 0;
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
  while (t--) solve();
}
