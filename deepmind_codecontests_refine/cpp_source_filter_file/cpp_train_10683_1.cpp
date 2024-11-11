#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wmissing-declarations"
int const maxn = 100005;
vector<int> gr[maxn];
int mask[maxn];
void dfs(int v) {
  mask[v] = 1;
  for (int ne : gr[v])
    if (!mask[ne]) dfs(ne);
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> prev;
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    vector<int> cur(l);
    for (int& x : cur) cin >> x;
    int ind = 0;
    while (ind < prev.size() && ind < cur.size() && prev[ind] == cur[ind])
      ++ind;
    if (ind < prev.size() && ind < cur.size()) {
      gr[cur[ind]].push_back(prev[ind]);
    } else if (ind >= cur.size() && ind < prev.size()) {
      cout << ("No") << '\n';
      exit(0);
    };
    prev.swap(cur);
  }
  for (int i = 1; i <= n; ++i)
    for (int ne : gr[i])
      if (ne > i) dfs(ne);
  for (int i = 1; i <= n; ++i)
    for (int ne : gr[i])
      if (!((mask[i] == mask[ne] && i > ne) || (mask[i] < mask[ne]))) {
        cout << ("No") << '\n';
        exit(0);
      };
  cout << "Yes\n";
  vector<int> ans;
  for (int i = 0; i < maxn; ++i)
    if (mask[i]) ans.push_back(i);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << " \n"[i == ans.size() - 1];
}
