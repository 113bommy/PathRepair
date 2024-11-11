#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    x = (x * x);
    y /= 2;
  }
  return res;
}
long long getSum(vector<long long> &BITree, long long index) {
  long long sum = 0;
  index = index + 1;
  while (index > 0) {
    sum += BITree[index];
    index -= index & (-index);
  }
  return sum;
}
void updateBIT(vector<long long> &BITree, long long n, long long index,
               long long val) {
  index = index + 1;
  while (index <= n) {
    BITree[index] += val;
    index += index & (-index);
  }
}
void dfs(vector<long long> adj[], long long x, vector<bool> &vis) {
  vis[x] = 1;
  for (auto it : adj[x]) {
    if (!vis[it]) {
      dfs(adj, it, vis);
    }
  }
}
int32_t main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cerr.tie(NULL);
  cout.precision(20);
  long long n, k;
  cin >> n >> k;
  if (__builtin_popcount(n) > k) {
    cout << "No";
    return 0;
  }
  cout << "Yes\n";
  map<long long, long long> m;
  for (long long i = 0; i < 64; i++) {
    if (n & (1ll << i)) m[i] = 1;
  }
  long long ctr = m.size();
  while (ctr < k && (--m.end())->second <= k - ctr) {
    auto it = (--m.end());
    m[it->first - 1] += 2;
    if (it->second == 1)
      m.erase(it->first);
    else
      m[it->first] -= 1;
    ctr++;
  }
  while (ctr < k) {
    auto it = m.begin();
    long long fi = it->first, se = it->second;
    m[fi - 1] += 2;
    if (se == 1)
      m.erase(fi);
    else
      m[fi] -= 1;
    ctr++;
  }
  vector<long long> ans;
  for (auto it = m.begin(); it != m.end(); it++) {
    while (it->second) {
      ans.push_back(it->first);
      it->second -= 1;
    }
  }
  sort(ans.begin(), ans.end(), greater<long long>());
  for (auto it : ans) cout << it << " ";
}
