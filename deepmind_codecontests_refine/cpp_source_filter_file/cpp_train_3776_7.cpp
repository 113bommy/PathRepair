#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long mod = 998244353;
const long long linf = 0x3f3f3f3f3f3f3f3f;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int l[300100], r[300100];
int a[30], b[30];
int p[300100][42];
int cnt[300100];
void sol(vector<int> v) {
  int m = v.size();
  vector<int> ans(1 << m);
  for (int i = 1; i < (1 << m); i++) {
  }
}
long long fat[300100];
long long ifat[300100];
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void comp_fac(int MAX) {
  fat[0] = 1;
  for (long long i = 1; i <= MAX; i++) {
    fat[i] = (fat[i - 1] * i) % mod;
  }
  ifat[MAX] = power(fat[MAX], mod - 2, mod);
  for (long long i = MAX - 1; i >= 0; i--)
    ifat[i] = (ifat[i + 1] * (i + 1)) % mod;
}
long long choose(int x, int y) {
  if (y > x || y < 0 || x < 0) return 0;
  return (fat[x] * ((ifat[y] * ifat[x - y]) % mod)) % mod;
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    cnt[l[i]]++;
    cnt[r[i] + 1]--;
  }
  for (int i = 0; i <= n; i++) cnt[i + 1] += cnt[i];
  comp_fac(300000);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m + m; j++) {
      p[i][j] = (p[i - 1][j] + choose(cnt[i] - j, i - j)) % mod;
    }
  }
  long long ans = 0;
  for (int mask = 0; mask < (1 << m); mask++) {
    int sign = __builtin_popcount(mask) & 1 ? -1 : 1;
    set<int> s;
    for (int j = 0; j < m; j++) {
      if (mask & (1 << j)) {
        s.insert(a[j]);
        s.insert(b[j]);
      }
    }
    int left = 1, right = n;
    for (auto q : s) {
      left = max(left, l[q]);
      right = max(right, r[q]);
    }
    if (left > right) continue;
    ans = (ans + (sign * (p[right][s.size()] - p[left - 1][s.size()])) % mod +
           mod) %
          mod;
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  ;
  solve();
  return 0;
}
