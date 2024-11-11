#include <bits/stdc++.h>
using namespace std;
mt19937 bruh(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rofl(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 200;
const int M = 1e5;
const int mod = 0;
const int inf = 2e9 + 3;
const long long INF = 1e18;
const long double pi2 = 2.0 * 3.141592;
const int dx[] = {+1, -1, -1, -2, -2, -3};
const int dy[] = {-2, -2, -3, -1, +1, -1};
void files() {
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
}
int n, G[N], pr[N], ans = inf;
vector<pair<int, int> > go[N];
set<int> s;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (int i = 1; i <= 100000; ++i) {
    int cnt = 0;
    for (int j = i; cnt <= 100000; ++j) {
      cnt += j;
      if (i != j) go[cnt].push_back({i, j});
    }
  }
  for (int i = 1; i <= M; ++i) {
    s.clear();
    s.insert(inf);
    for (auto it : go[i]) s.insert(pr[it.first - 1] ^ pr[it.second]);
    int cnt = 0;
    for (auto it : s)
      if (it != cnt) {
        G[i] = cnt;
        break;
      } else
        cnt++;
    pr[i] = pr[i - 1] ^ G[i];
  }
  cin >> n;
  if (G[n]) {
    for (auto it : go[n])
      if (pr[it.first - 1] == pr[it.second])
        ans = min(ans, it.second - it.first + 1);
    cout << ans << '\n';
    ;
  } else
    cout << "-1\n";
  ;
}
