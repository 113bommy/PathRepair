#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
typedef tuple<int, int> i2;
typedef tuple<int, int, int> i3;
typedef tuple<int, int, int, int> i4;
typedef vector<int> vi;
typedef vector<i2> vi2;
typedef vector<i3> vi3;
typedef vector<i4> vi4;
typedef vector<vi> v2i;
typedef vector<vi2> v2i2;
typedef vector<string> vs;
typedef vector<long long> vll;
long long modPow(long long b, long long p, long long m) {
  b %= m;
  if (p <= 1) return p == 0 ? 1 : b;
  long long res = modPow(b * b, p / 2, m);
  return p % 2 == 0 ? res : (res * b) % m;
}
int mark[1234];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, y;
  cin >> n >> y;
  vi v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  cin >> m >> y;
  vi v2(m);
  for (int i = 0; i < m; ++i) cin >> v2[i];
  int res = 2;
  for (long long i = 1; i < 1e9; i <<= 1) {
    long long x = 2 * i;
    map<long long, int> mm;
    for (int j = 0; j < ((int)v.size()); ++j) ++mm[v[j] % x];
    for (int j = 0; j < ((int)v2.size()); ++j) ++mm[(v2[j] + i) % x];
    for (auto p : mm) res = max(res, p.second);
  }
  cout << res << '\n';
  return 0;
}
