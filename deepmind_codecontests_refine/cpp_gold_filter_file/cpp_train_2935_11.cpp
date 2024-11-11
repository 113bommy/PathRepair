#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
using ll = long long;
using db = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF64 = ll(4e18) + 5;
const db EPS = 1e-9;
const db PI = acos((db)-1);
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> M(n, vi(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0) {
        M[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << (M[i][j] ? 'W' : 'B');
    }
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
