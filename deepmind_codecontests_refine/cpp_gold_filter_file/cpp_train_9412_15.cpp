#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long inf = 1e18;
const long long mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long powm(long long a, long long b, long long m);
int arrays[20][100002];
int hola[1 << 20];
int sos[1 << 20];
void solve() {
  int n, m, d;
  cin >> n >> m >> d;
  for (int i = 0; i < m; i++) {
    int te, temp;
    cin >> te;
    for (int j = 0; j < te; j++) {
      cin >> temp;
      arrays[i][max(1, temp - d + 1)]++;
      if (temp < n - d + 1)
        arrays[i][temp + 1]--;
      else
        arrays[i][n + 1]--;
    }
    for (int j = 1; j <= n; j++) arrays[i][j] += arrays[i][j - 1];
  }
  int tol = (1 << m) - 1;
  for (int i = 1; i <= n; i++) {
    int bitc = 0;
    for (int j = 0; j < m; j++)
      if (arrays[j][i]) bitc |= (1 << j);
    hola[bitc ^ tol]++;
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < (1 << m); j++)
      if (j & (1 << i)) hola[j] += hola[j ^ (1 << i)];
  for (int i = 0; i < (1 << m); i += 2) swap(hola[i], hola[i ^ tol]);
  hola[0] = 0;
  for (int i = 0; i < (1 << m); i++)
    if (!(__builtin_popcount(i) & 1)) hola[i] *= -1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < (1 << m); j++)
      if (j & (1 << i)) hola[j] += hola[j ^ (1 << i)];
  int ans = m;
  for (int i = 0; i < (1 << m); i++)
    if (hola[i] == n) ans = min(ans, __builtin_popcount(i));
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::steady_clock::now().time_since_epoch().count());
  cout << fixed << setprecision(10);
  int t = 1;
  while (t--) solve();
  return 0;
}
long long powm(long long a, long long b, long long m) {
  long long te = 1;
  while (b) {
    if (b & 1) te = (te * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return te;
}
