#include <bits/stdc++.h>
using namespace std;
int n, a[1005];
vector<pair<int, int> > ans;
inline int getl() {
  for (int i = 1; i <= n; ++i)
    if (a[i] != i) return 1;
  return 0;
}
inline int getr() {
  for (int i = n; i > 0; --i)
    if (a[i] != i) return i;
  return 0;
}
inline int getx(int x) {
  for (int i = 1; i <= n; ++i)
    if (a[i] == x) return i;
  return 0;
}
int dfs(int p) {
  int l, r;
  l = getl();
  if (!l) return 1;
  if (p > 3) return 0;
  r = getx(l);
  reverse(a + l, a + r + 1);
  if (dfs(p + 1)) return ans.push_back(pair<int, int>(l, r)), 1;
  reverse(a + l, a + r + 1);
  r = getr();
  l = getx(r);
  reverse(a + l, a + r + 1);
  if (dfs(p + 1)) return ans.push_back(pair<int, int>(l, r)), 1;
  reverse(a + l, a + r + 1);
  return 0;
}
int main(int argc, char **argv) {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  dfs(1);
  cout << ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); ++i)
    cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}
