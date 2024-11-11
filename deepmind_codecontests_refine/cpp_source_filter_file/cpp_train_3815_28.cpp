#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
const double error = 1e-7;
const double PI = acos(-1);
mt19937 rng(
    (unsigned int)chrono::system_clock::now().time_since_epoch().count());
inline long long int MOD(long long int x, long long int m = mod) {
  long long int y = x % m;
  return (y >= 0) ? y : y + m;
}
const int inf = 1e9 + 2;
const long long int infl = 1e18 + 1;
const int nmax = 1e6 + 10;
int master[nmax];
void init(int n) {
  for (int i = 1; i <= n; i++) master[i] = i;
}
int fnd(int u) {
  if (master[u] == u) return u;
  return master[u] = fnd(master[u]);
}
int unite(int a, int b) {
  a = fnd(a), b = fnd(b);
  if (rng() & 1) swap(a, b);
  master[b] = a;
  return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n, m;
  cin >> n >> m;
  init(n);
  long long int two = 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (fnd(a) == fnd(b)) {
      two *= 2;
      two %= mod;
    } else
      unite(a, b);
    cout << two - 1 << "\n";
  }
}
