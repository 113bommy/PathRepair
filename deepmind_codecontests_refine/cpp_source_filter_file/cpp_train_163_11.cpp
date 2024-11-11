#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
using ll = long long;
using ld = long double;
constexpr int nax = 1005;
constexpr ll infty = 1e14;
constexpr int mod = 1000 * 1000 * 1000 + 7;
int n, k;
ll p;
vector<ll> a, b;
ll dp[nax][nax];
bool juz[nax][nax];
ll Koszt(int x, int y) { return abs(a[x] - b[y]) + abs(b[y] - p); }
ll Dp(int x, int y);
ll Dp_(int x, int y) {
  if (x == 0) return 0;
  if (y == 0) return infty;
  return min(Dp(x, y - 1), max(Dp(x - 1, y - 1), Koszt(x, y)));
}
ll Dp(int x, int y) {
  if (juz[x][y]) return dp[x][y];
  juz[x][y] = true;
  return dp[x][y] = Dp_(x, y);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> p;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    b.push_back(x);
  }
  a.push_back(0);
  b.push_back(0);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  cout << Dp(n, k) << endl;
  return 0;
}
