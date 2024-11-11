#include <bits/stdc++.h>
using namespace std;
vector<long long> v[100005];
long long child[100005];
long long ans1, ans2, n;
long long leaff, pleaff;
long long dfs(long long x, long long p) {
  for (auto it : v[x]) {
    if (it == p) continue;
    child[x] += dfs(it, x);
  }
  child[x]++;
  for (auto it : v[x]) {
    if (it == p) continue;
    if (2 * child[it] == n) {
      ans1 = x;
      ans2 = it;
    }
  }
  return child[x];
}
void leaf(long long x, long long p) {
  if (v[x].size() == 1 && p != -1) {
    leaff = x;
    pleaff = p;
  }
  for (auto it : v[x]) {
    if (it == p) continue;
    leaf(it, x);
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long i, x, y, j;
    cin >> n;
    ans1 = -1;
    ans2 = -1;
    for (i = 1; i <= n; i++) {
      v[i].clear();
      child[i] = 0;
    }
    pair<long long, long long> p;
    for (i = 0; i < n - 1; i++) {
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
      p = {x, y};
    }
    dfs(1, -1);
    if (ans1 == -1) {
      cout << p.first << " " << p.second << endl;
      cout << p.first << " " << p.second << endl;
      continue;
    }
    leaf(ans2, -1);
    cout << pleaff << " " << leaff << endl;
    cout << leaff << " " << ans1 << endl;
  }
}
