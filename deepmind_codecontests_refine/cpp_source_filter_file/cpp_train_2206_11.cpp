#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
mt19937 rng(steady_clock::now().time_since_epoch().count());
void usaco(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
const long double pi = 3.14159265358979323846;
long long n, m, k, q, l, r, x, y, z;
long long a[1000005];
long long b[1000005];
long long c[1000005];
string second, t;
long long ans = 0;
int lcs[105][105][105];
long long rec(int a, int b, int c) {
  if (b > c) return 1;
  if (a < 0) return 0;
  if (lcs[a][b][c] != -1) return lcs[a][b][c];
  lcs[a][b][c] = 0;
  if (second[a] == t[c]) lcs[a][b][c] |= rec(a - 1, b, c - 1);
  lcs[a][b][c] |= rec(a - 1, b, c);
  return lcs[a][b][c];
}
void solve(int tc) {
  string a, b;
  cin >> n >> second >> t;
  a = second;
  b = t;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (a != b) {
    cout << -1 << '\n';
    return;
  }
  for (long long i = 0; i < (n); ++i)
    for (long long j = 0; j < (n); ++j)
      for (long long k = 0; k < (n); ++k) lcs[i][j][k] = -1;
  ans = 0;
  for (long long i = 0; i < (n); ++i)
    for (long long j = 0; j < (n); ++j)
      for (long long k = (j + 1); k < (n); ++k)
        if (rec(i, j, k) == 1) ans = max(ans, k - j + 1);
  cout << n - ans << '\n';
}
int main() {
  { ios_base::sync_with_stdio(false); }
  {
    cin.tie(NULL);
    cout.tie(NULL);
  }
  int tc;
  cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}
