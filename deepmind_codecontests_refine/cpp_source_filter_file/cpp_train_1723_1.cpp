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
const int MAXN = 3e6;
int cnt[MAXN + 1];
ll cnt_area[MAXN + 1];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int _ = (0); _ < (n); ++_) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  for (int i = 1; i * i <= MAXN; i++) {
    if (cnt[i] == 0) continue;
    cnt_area[i * i] += (ll)cnt[i] * (cnt[i] - 1);
    for (int j = i + 1; i * j <= MAXN; j++)
      cnt_area[i * j] += 2 * (ll)cnt[i] * cnt[j];
  }
  partial_sum(begin(cnt_area), end(cnt_area), begin(cnt_area));
  int m;
  cin >> m;
  ll res = n * (n - 1);
  while (m--) {
    int p;
    cin >> p;
    cout << res - cnt_area[p - 1] << '\n';
  }
  return 0;
}
