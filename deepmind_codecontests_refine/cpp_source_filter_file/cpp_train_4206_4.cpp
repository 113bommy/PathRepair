#include <bits/stdc++.h>
using namespace std;
using u64 = uint64_t;
vector<long long> v[300];
vector<bool> vis(300);
vector<long long> ans, tmp, tmp_ans;
bool dfs(long long fr, long long to) {
  if (fr == to) {
    tmp_ans.push_back(fr);
    return true;
  }
  vis[fr] = true;
  for (auto x : v[fr]) {
    if (!vis[x]) {
      vis[x] = true;
      if (dfs(x, to)) {
        tmp_ans.push_back(fr);
        return true;
      }
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1LL;
  while (t--) {
    long long n;
    cin >> n;
    long long x, y;
    for (int i = 1; i < n; i++) {
      cin >> x >> y;
      v[--x].push_back(--y), v[y].push_back(x);
    }
    long long q = 0LL;
    for (int i = 1; i < n; i++)
      if (v[i].size() == 1) q++;
    tmp.push_back(0);
    for (int i = 0; i < q; i++) {
      cin >> x;
      tmp.push_back(--x);
    }
    tmp.push_back(0);
    ans.push_back(1);
    for (int i = 0; i < tmp.size() - 1; i++) {
      vis.assign(n + 1, false);
      if (dfs(tmp[i], tmp[i + 1])) {
        reverse(tmp_ans.begin(), tmp_ans.end());
        for (auto x : tmp_ans) ans.push_back(x + 1);
        ans.pop_back();
        tmp_ans.clear();
      }
    }
    if (ans.size() == 2 * n - 1) {
      for (auto x : ans) cout << x << " ";
      cout << "\n";
    } else
      cout << "-1\n";
  }
}
