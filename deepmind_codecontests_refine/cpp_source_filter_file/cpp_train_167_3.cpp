#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
set<long long int> v[200005], unvis;
long long int k = 0;
void dfs(long long int r) {
  k++;
  unvis.erase(r);
  vector<long long int> nex;
  for (auto i : unvis) {
    if (v[r].find(i) == v[r].end()) nex.push_back(i);
  }
  for (auto i : nex) unvis.erase(i);
  for (auto i : nex) dfs(i);
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int n, m, x, y;
  cin >> n >> m;
  for (long long int i = 1; i <= n; i++) {
    cin >> x >> y;
    v[x].insert(y);
    v[y].insert(x);
  }
  for (long long int i = 1; i <= n; i++) unvis.insert(i);
  vector<long long int> ans;
  for (long long int i = 1; i <= n; i++)
    if (unvis.find(i) != unvis.end()) {
      k = 0;
      dfs(i);
      ans.push_back(k);
    }
  sort(ans.begin(), ans.end());
  cout << (long long int)ans.size() << "\n";
  for (auto i : ans) cout << i << " ";
}
