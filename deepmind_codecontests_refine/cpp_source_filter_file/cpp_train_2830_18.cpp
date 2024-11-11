#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int INF = 1e17;
long long int NINF = (INF * -1);
priority_queue<pair<long long int, long long int>,
               vector<pair<long long int, long long int>>,
               greater<pair<long long int, long long int>>>
    pq;
vector<long long int> indegree;
vector<vector<pair<long long int, long long int>>> adj;
vector<long long int> distances;
vector<vector<long long int>> arr;
vector<bool> visited;
vector<long long int> level, height;
vector<long long int> ans;
long long int dfs(long long int src, long long int parent = -1,
                  long long int l = 0) {}
void solve() {
  long long int n;
  cin >> n;
  string a;
  string b;
  cin >> a >> b;
  vector<long long int> ab, ba;
  vector<pair<long long int, long long int>> ans;
  for (long long int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      continue;
    }
    if (a[i] == 'a' and b[i] == 'b') {
      if (ab.size() != 0) {
        ans.push_back({ab.back(), i + 1});
        ab.pop_back();
      } else {
        ab.push_back(i + 1);
      }
    } else {
      if (ba.size() != 0) {
        ans.push_back({ba.back(), i + 1});
        ba.pop_back();
      } else {
        ba.push_back(i + 1);
      }
    }
  }
  if (ab.size() == 1 and ba.size() == 1) {
    ans.push_back({ab.back(), ab.back()});
    ans.push_back({ab.back(), ba.back()});
    ab.pop_back();
    ba.pop_back();
  }
  if (ab.size() != 0 and ba.size() != 0) {
    cout << "-1\n";
    return;
  }
  cout << ans.size();
  cout << "\n";
  ;
  for (auto i : ans) {
    cout << i.first << " " << i.second;
    cout << "\n";
    ;
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
}
