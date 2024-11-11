#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (b); i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T& a, T b) {
   if (a > b) {
      a = b;
      return true;
   }
   return false;
}
template <class T>
inline bool chmax(T& a, T b) {
   if (a < b) {
      a = b;
      return true;
   }
   return false;
}
void hr() {
   cerr << "--------------" << endl;
}
const int INF = 1001001001;
const int MOD = 1000000007;
// const int MOD = 998244353;

const int MAX = 100005;
vector<P> g[MAX];
int x[MAX];
bool used[MAX];
vector<int> ans;
int dfs(int v) {
   used[v] = true;
   int res = x[v];
   for (P e : g[v]) {
      if (used[e.first]) continue;
      int r = dfs(e.first);
      if (r) ans.push_back(e.second);
      res ^= r;
   }
   return res;
}

int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n, m;
   cin >> n >> m;
   vector<P> a(n);
   rep(i, 0, n) cin >> a[i].first >> a[i].second;
   sort(a.begin(), a.end());
   x[0] = a[0].second;
   rep(i, 0, n - 1) x[i + 1] = a[i].second ^ a[i + 1].second;
   x[n] = a[n - 1].second;

   rep(i, 0, m) {
      int l, r;
      cin >> l >> r;
      l = lower_bound(a.begin(), a.end(), P(l, 0)) - a.begin();
      r = upper_bound(a.begin(), a.end(), P(r, 1)) - a.begin();
      g[l].emplace_back(r, i + 1);
      g[r].emplace_back(l, i + 1);
   }
   rep(i, 0, n + 1) {
      if (used[i]) continue;
      if (dfs(i)) {
         cout << -1 << endl;
         return 0;
      }
   }
   cout << ans.size() << endl;
   sort(ans.begin(), ans.end());
   rep(i, 0, ans.size())
       printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : '');
   return 0;
}