#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  queue<int> q;
  vector<int> d(n), s(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i] >> s[i];
    if (d[i] == 1) q.push(i);
  }
  set<pair<int, int> > ans;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (d[v] != 1) continue;
    ans.insert({v, s[v]});
    s[s[v]] ^= v;
    d[s[v]]--;
    if (d[s[v]] == 1) {
      q.push(s[v]);
    }
  }
  cout << ans.size() << endl;
  for (auto v : ans) {
    cout << v.first << ' ' << v.second << endl;
  }
  return 0;
}
