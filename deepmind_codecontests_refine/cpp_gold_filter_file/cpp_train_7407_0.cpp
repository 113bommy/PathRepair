#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[n];
  map<long long, long long> mp;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == -1) mp[i + 1] = 0;
  }
  queue<long long> q;
  for (auto x : mp) {
    q.push(x.first);
  }
  while (!q.empty()) {
    long long tp = q.front();
    for (int i = 0; i < n; ++i) {
      if (a[i] == tp) {
        mp[i + 1] = mp[tp] + 1;
        q.push(i + 1);
      }
    }
    q.pop();
  }
  long long ans = 0;
  for (auto x : mp) ans = max(ans, x.second);
  cout << ans + 1;
}
