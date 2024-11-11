#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <class T>
using V = vector<T>;
const ll MOD = 1e9 + 7;
const int MX = 2e+5;
const ll INF = 1e18;
const db PI = acos((db)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
void setIO() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
}
int main() {
  setIO();
  int n, k;
  cin >> n >> k;
  if (k >= n * (n - 1) / 2) {
    cout << "no solution" << endl;
    return 0;
  }
  for (int i = (0); i < (n); ++i) cout << 0 << ' ' << i << endl;
  return 0;
}
