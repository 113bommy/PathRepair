#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000;
const long long LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const long long MOD = INF + 7;
long long v[5000500];
long long da[5000500];
int m;
void add(long long& a, long long b) {
  a += b;
  while (a >= m) a -= m;
}
long long sub(long long& a, long long b) {
  long long q = a - b;
  if (q < 0) q += m;
  return q;
}
long long mult(long long a, long long b) { return (a * b) % m; }
void solve() {
  int n;
  cin >> n >> m;
  v[1] = 1;
  long long a = 0;
  long long pf = 0;
  for (int i = 1; i < n + 1; ++i) {
    add(pf, da[i]);
    add(v[i], pf);
    add(v[i], a);
    add(a, v[i]);
    for (int j = 2; j * i <= n; j++) {
      add(da[j * i], v[i]);
      da[j * (i + 1)] = sub(da[j * (i + 1)], v[i]);
    }
  }
  cout << v[n] << endl;
  cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
