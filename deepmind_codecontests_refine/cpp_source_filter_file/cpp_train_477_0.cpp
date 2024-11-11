#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> p[100005];
vector<int> ch[100005];
pair<int, int> dp[100005][18];
int d[100005];
void dfs(int cn) {
  for (auto nn : ch[cn]) {
    d[nn] = d[cn] + 1;
    dfs(nn);
  }
}
void prepro() {
  for (int i = (1); i <= (signed)(n); i++) {
    dp[i][0] = p[i];
  }
  for (int i = (1); i <= (signed)(18 - 1); i++) {
    for (int j = (1); j <= (signed)(n); j++) {
      dp[j][i].first = dp[dp[j][i - 1].first][i - 1].first;
      dp[j][i].second =
          dp[j][i - 1].second | dp[dp[j][i - 1].first][i - 1].second;
    }
  }
}
pair<int, pair<int, int> > lca(int a, int b) {
  bool swp = false;
  if (d[b] < d[a]) {
    swap(a, b);
    swp = true;
  }
  int bm1 = 0, bm2 = 0;
  int dif = d[b] - d[a];
  for (int i = (18 - 1); i >= 0; i--) {
    if (dif >= (1 << i)) {
      dif -= (1 << i);
      bm2 |= dp[b][i].second;
      b = dp[b][i].first;
    }
  }
  if (a == b) {
    if (swp)
      return {a, {bm2, 0}};
    else
      return {a, {0, bm2}};
  }
  for (int i = (18 - 1); i >= 0; i--) {
    if (dp[a][i].first != dp[b][i].first) {
      bm1 |= dp[a][i].second;
      bm2 |= dp[b][i].second;
      a = dp[a][i].first;
      b = dp[b][i].first;
    }
  }
  bm1 |= p[a].second;
  bm2 |= p[b].second;
  a = p[a].first;
  b = p[b].first;
  if (a != b || a == 0) return {-1, {3, 3}};
  if (swp)
    return {a, {bm2, bm1}};
  else
    return {a, {bm1, bm2}};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = (1); i <= (signed)(n); i++) {
    cin >> p[i].first >> p[i].second;
    ++p[i].second;
    if (p[i].first == -1) p[i].first = 0;
    ch[p[i].first].push_back(i);
  }
  for (int i = (1); i <= (signed)(n); i++) {
    if (p[i].first == -1) {
      d[i] = 0;
      dfs(i);
    }
  }
  prepro();
  int q;
  cin >> q;
  for (int _ = 0; _ < (signed)(q); _++) {
    int t, u, v;
    cin >> t >> u >> v;
    pair<int, pair<int, int> > res = lca(u, v);
    if (t == 1) {
      if (u != v && res.first == u && res.second.second == 1) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      if (res.first != v && !(res.second.first & 2) &&
          !(res.second.second & 1)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
