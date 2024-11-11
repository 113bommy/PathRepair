#include <bits/stdc++.h>
using namespace std;
map<int, int> d;
map<int, bool> mp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    q.push(x);
    mp[x] = 1;
    d[x] = 0;
  }
  vector<int> ans;
  long long sum = 0;
  int cnt = 0;
  while (cnt < m) {
    int u = q.front();
    q.pop();
    if (mp[u - 1] == 0) {
      ans.push_back(u - 1);
      mp[u - 1] = 1;
      q.push(u - 1);
      d[u - 1] = d[u] + 1;
      sum += d[u - 1];
      cnt++;
    }
    if (cnt < m && mp[u + 1] == 0) {
      ans.push_back(u + 1);
      mp[u + 1] = 1;
      q.push(u + 1);
      d[u + 1] = d[u] + 1;
      sum += d[u + 1];
      cnt++;
    }
  }
  cout << sum << "\n";
  for (auto i : ans) cout << i << " ";
}
