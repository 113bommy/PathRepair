#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
ll power(ll x, ll y);
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 18;
const int inf = 2e9;
const int N = 5e6 + 5;
vector<int> join[N], v[N];
int col[N];
bool vis[N];
void dfs(int s) {
  vis[s] = 1;
  for (auto i : v[s])
    if (!vis[i]) {
      col[i] = 1 - col[s];
      dfs(i);
    }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n & 1) {
    cout << "Second" << endl;
    for (int i = 1; i <= 2 * n; i++) {
      int inp;
      cin >> inp;
      join[inp].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
      v[join[i][0]].emplace_back(join[i][1]);
      v[join[i][1]].emplace_back(join[i][0]);
      v[i].emplace_back(i + n);
      v[i + n].emplace_back(i);
    }
    for (int i = 1; i <= n * 2; i++)
      if (!vis[i]) dfs(i);
    vector<int> a, b;
    int A = 0;
    for (int i = 1; i <= 2 * n; i++) {
      if (col[i])
        a.emplace_back(i), A += i;
      else
        b.emplace_back(i);
    }
    if (A % (n + n))
      for (auto i : b) cout << i << " ";
    else
      for (auto i : a) cout << i << " ";
    cout << endl;
  } else {
    cout << "First\n";
    for (int i = 1; i <= n; i++) cout << i << " ";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
  }
  int verdict;
  cin >> verdict;
  if (verdict == -1) verdict = 0 / 0;
}
ll power(ll x, ll y) {
  ll res = 1;
  x %= MOD;
  while (y > 0) {
    if (y & 1) res = (res * x) % MOD;
    y = y >> 1, x = (x * x) % MOD;
  }
  return res;
}
