#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > sp[100010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    sp[n - b + 1].push_back(make_pair(b, i));
  }
  set<pair<int, int> > df;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    for (auto x : sp[i]) df.insert(x);
    while (df.size() && df.begin()->first < i) df.erase(df.begin());
    if (df.size()) {
      ans.push_back(df.begin()->second);
      df.erase(df.begin());
    }
  }
  cout << ans.size() << '\n';
  for (auto i : ans) cout << i + 1 << " ";
  cout << '\n';
}
