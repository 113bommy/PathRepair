#include <bits/stdc++.h>
using namespace std;
int n;
int u[200001], v[200001];
vector<int> ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> u[i] >> v[i];
  }
  ans.push_back(1);
  if (v[1] == v[u[1]] || v[1] == u[v[1]])
    ans.push_back(u[1]), ans.push_back(v[1]);
  else
    ans.push_back(v[1]), ans.push_back(u[1]);
  for (int i = 4; i <= n; i++) {
    if (v[ans[i - 3]] != ans[i - 2])
      ans.push_back(v[ans[i - 3]]);
    else if (u[ans[i - 3]] != ans[i - 2])
      ans.push_back(u[ans[i - 3]]);
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
}
