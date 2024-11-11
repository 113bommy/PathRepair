#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<pair<int, int>> VPII;
typedef vector<long long> VLL;
constexpr char nl = '\n';
template <class t, class u>
inline void mini(t& a, u&& b) {
  if (b < a) a = b;
}
template <class t, class u>
inline void maxi(t& a, u&& b) {
  if (b > a) a = b;
}
int ceil2(int h) {
  return h < 2 ? 1 : 1 << (sizeof(h) * 8 - __builtin_clz(h - 1));
}
template <class t>
struct Dump {
  t a, b;
};
template <class t>
auto dump(t&& h) -> Dump<decltype(begin(h))> {
  return {begin(h), end(h)};
}
template <class t>
auto stub(t* h) -> decltype(cerr << *h, 0);
template <class t>
char stub(...);
struct debug {
  operator int() { return 0; }
  template <class t>
  debug& operator<<(t&&) {
    return *this;
  }
};
const int N = (int)1e5 + 10;
int pocz[N], kon[N], d[N], w[N];
multiset<pair<long long, long long>> secik;
long long dp[N][210], sum[N], j[N];
vector<pair<long long, long long>> tab[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int a = 1; a <= k; a++) {
    cin >> pocz[a] >> kon[a] >> d[a] >> w[a];
    tab[pocz[a]].push_back({-1, a});
    tab[kon[a]].push_back({1, a});
  }
  for (int a = n; a >= 1; a--) {
    sort(tab[a].begin(), tab[a].end());
    while (!tab[a].empty() && tab[a].back().first == 1) {
      int i = tab[a].back().second;
      tab[a].pop_back();
      auto p = make_pair(w[i], d[i]);
      secik.insert(p);
    }
    auto p = secik.end();
    if (!secik.empty()) {
      p--;
      sum[a] = p->first;
      j[a] = p->second + 1;
    } else {
      sum[a] = 0;
      j[a] = a + 1;
    }
    while (!tab[a].empty() && tab[a].back().first == -1) {
      int i = tab[a].back().second;
      tab[a].pop_back();
      auto p = make_pair(w[i], d[i]);
      auto it = secik.find(p);
      secik.erase(p);
    }
  }
  long long inf = 1000000000000000000;
  dp[n + 1][m] = 0;
  for (int a = 1; a <= n; a++)
    for (int b = 0; b <= m; b++) dp[a][m] = inf;
  for (int a = n; a >= 1; a--) {
    for (int b = m; b >= 0; b--) {
      dp[a][b] = dp[j[a]][b] + sum[a];
      if (b != m) dp[a][b] = min(dp[a][b], dp[a + 1][b + 1]);
    }
  }
  long long ans = inf;
  for (int a = 0; a <= m; a++) {
    ans = min(ans, dp[1][a]);
  }
  cout << ans << nl;
  return 0;
}
