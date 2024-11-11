#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = int(2e5) + 20;
vector<vector<int>> g(MAXN);
map<int, int> toV;
map<int, int> toCnt;
vector<int> used(MAXN);
long long dfs(int v) {
  used[v] = 1;
  long long ret = toCnt[v];
  for (auto u : g[v]) {
    if (!used[u]) {
      ret += dfs(u);
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(MAXN);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  vector<int> b;
  for (auto item : cnt) {
    b.push_back(item.second);
  }
  sort(b.begin(), b.end());
  long long ans = 0;
  for (int start = 1; start < 10; start++) {
    int curr = start;
    auto it = lower_bound(b.begin(), b.end(), curr);
    long long currLen = 0;
    while (it != b.end()) {
      currLen++;
      curr *= 2;
      it = lower_bound(it + 1, b.end(), curr);
    }
    ans = max((long long)start * ((1 << currLen) - 1), ans);
  }
  cout << ans;
  return 0;
}
