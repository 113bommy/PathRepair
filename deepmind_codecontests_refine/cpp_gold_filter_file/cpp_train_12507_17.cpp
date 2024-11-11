#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:367772116")
using namespace std;
int n, k;
vector<vector<int>> e;
int cur = 0;
vector<int> color;
long long mod = 1e9 + 7;
void dfs(int pos, int last) {
  cur++;
  for (auto to : e[pos]) {
    if (!color[to]) {
      color[to] = 1;
      dfs(to, pos);
    }
  }
}
long long pw(int a, int b) {
  long long buf = 1;
  for (size_t i = 0; i < b; i++) {
    buf *= a;
    buf %= mod;
  }
  return buf;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int k;
  vector<pair<int, int>> v(n);
  for (size_t i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());
  cin >> k;
  int pos = 0;
  int ans = 0;
  while (pos != n && v[pos].second < k) {
    pos++;
    ans++;
  }
  cout << n - ans;
}
