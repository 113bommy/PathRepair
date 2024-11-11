#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> arr(n);
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  map<long long int, long long int> mp;
  queue<long long int> q;
  for (long long int i = 0; i < n; i++) {
    mp[arr[i]] = 0;
    q.push(arr[i]);
  }
  vector<long long int> res;
  long long int ans = 0;
  while (!q.empty()) {
    if (res.size() == m) break;
    long long int curr = q.front();
    q.pop();
    if (mp[curr] != 0) {
      ans += mp[curr];
      res.push_back(curr);
    }
    if (mp.count(curr + 1) == 0) {
      q.push(curr + 1);
      mp[curr + 1] = mp[curr] + 1;
    }
    if (mp.count(curr - 1) == 0) {
      q.push(curr - 1);
      mp[curr - 1] = mp[curr] + 1;
    }
  }
  cout << ans << endl;
  for (auto it : res) cout << it << " ";
  cout << endl;
}
