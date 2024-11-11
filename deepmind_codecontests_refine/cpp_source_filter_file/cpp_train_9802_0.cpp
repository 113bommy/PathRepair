#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
multiset<int> ms[200010];
int deg[200010], N, b[200010], c[200010], dst, us[200010], cnt, yaz[200010];
void dfs(int pos) {
  while (ms[pos].size()) {
    int next = *ms[pos].begin();
    ms[pos].erase(ms[pos].begin());
    ms[next].erase(ms[next].find(pos));
    dfs(next);
  }
  yaz[cnt++] = pos;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N;
  int i, tk = 0, bas = 1;
  for (i = 0; i < N - 1; ++i) {
    cin >> b[i];
    if (!mp[b[i]]) {
      mp[b[i]] = ++dst;
      deg[dst] = b[i];
    }
  }
  for (i = 0; i < N - 1; i++) {
    cin >> c[i];
    if (b[i] > c[i]) {
      cout << "-1" << endl;
      return 0;
    }
    if (!mp[c[i]]) {
      mp[c[i]] = ++dst;
      deg[dst] = c[i];
    }
    ms[mp[c[i]]].insert(mp[b[i]]);
    ms[mp[b[i]]].insert(mp[c[i]]);
  }
  for (i = 1; i <= dst; i++)
    if (ms[i].size() == 1) {
      tk++;
      bas = i;
    }
  if (tk > 2 || tk == 1) {
    cout << tk << "-1" << endl;
    return 0;
  }
  dfs(bas);
  if (cnt != N) {
    cout << "-1" << endl;
    return 0;
  }
  for (i = 0; i < cnt; i++) cout << deg[yaz[i]] << ' ';
  cout << endl;
  return 0;
}
