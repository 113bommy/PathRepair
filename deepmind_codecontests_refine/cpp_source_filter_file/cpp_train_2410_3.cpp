#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
vector<int> ans;
long long a[100005];
void dfs(long long s, long long p) {
  long long flag = 1;
  for (auto i : v[s]) {
    if (i == p) continue;
    dfs(i, s);
    if (a[i] == 0) flag = 0;
  }
  if (flag && a[s] == 1) {
    ans.push_back(s);
  }
}
int main() {
  long long n;
  cin >> n;
  long long s, i;
  for (i = 1; i <= n; i++) {
    long long x, y;
    cin >> x >> y;
    a[i] = y;
    if (x == -1) {
      s = i;
      continue;
    }
    v[i].push_back(x);
    v[x].push_back(i);
  }
  dfs(s, -1);
  if (ans.size() == 0)
    cout << "-1\n";
  else {
    reverse(ans.begin(), ans.end());
    for (auto k : ans) cout << k << " ";
  }
}
