#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, a[N];
unordered_map<int, int> mp[N];
vector<int> b[N], bb[N];
int dfs(int l, int r) {
  if (mp[r].count(l)) return mp[r][l];
  int &ret = mp[r][l];
  for (auto &i : b[r])
    if (r - i * 2 + 1 >= l) ret = max(ret, dfs(l, r - i) + 1);
  for (auto &i : bb[l])
    if (l + i * 2 - 1 <= r) ret = max(ret, dfs(l + i, r) + 1);
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  int ans = 0;
  while (n--) {
    int tt;
    cin >> tt;
    a[m + 1] = tt;
    if (a[m] == tt) b[m + 1] = {1};
    for (auto &i : b[m])
      if (a[m - i * 2] == tt) b[m + 1].push_back(i + 1);
    ++m;
    int pp = 0;
    for (auto &i : b[m])
      if (binary_search(b[m - i].begin(), b[m - i].end(), i)) pp = i;
    for (auto &i : b[m]) bb[m - i * 2 + 1].push_back(i);
    if (!pp)
      dfs(1, m);
    else
      for (pp *= 2, ++ans; pp > 0; --pp) {
        for (auto &i : bb[m]) bb[m - i * 2 + 1].pop_back();
        b[m].clear();
        mp[--m].clear();
      }
    cout << ans * 2 + mp[m][1] << ' ';
  }
  return 0;
}
