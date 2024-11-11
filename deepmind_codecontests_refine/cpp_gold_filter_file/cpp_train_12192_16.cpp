#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100000;
namespace Graph {
vector<int> adiast[NMAX];
int st[NMAX], dr[NMAX];
bool viz[NMAX];
bool activst[NMAX];
bool activdr[NMAX];
bool cuplaj(int nod) {
  viz[nod] = 1;
  for (auto i : adiast[nod]) {
    if (!dr[i]) {
      dr[i] = nod;
      st[nod] = i;
      return true;
    }
  }
  for (auto i : adiast[nod]) {
    if (!viz[dr[i]] && cuplaj(dr[i])) {
      dr[i] = nod;
      st[nod] = i;
      return true;
    }
  }
  return false;
}
void disable(int nod) {
  activst[nod] = 0;
  for (auto i : adiast[nod]) {
    if (!activdr[i]) {
      activdr[i] = 1;
      if (activst[dr[i]]) disable(dr[i]);
    }
  }
}
void solve(int n) {
  bool ok = 1;
  while (ok) {
    ok = 0;
    memset(viz, 0, sizeof viz);
    for (int i = 1; i <= n; i++)
      if (!viz[i] && !st[i] && cuplaj(i)) ok = 1;
  }
  for (int i = 1; i <= n; i++)
    if (st[i]) activst[i] = 1;
  for (int i = 1; i <= n; i++)
    if (!st[i]) disable(i);
}
}  // namespace Graph
struct Interv {
  int st, dr, h, from;
};
vector<pair<int, int>> sortx, sorty;
bool viz[2][NMAX], urm[2][NMAX];
vector<Interv> intervs[2];
bool intersect(Interv a, Interv b) {
  return (a.h > b.st && a.h < b.dr && b.h > a.st && b.h < a.dr);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int cardans = 2 * n;
  sortx.resize(n);
  for (auto& i : sortx) cin >> i.first >> i.second;
  sorty = sortx;
  sort(sortx.begin(), sortx.end());
  sort(sorty.begin(), sorty.end(), [](pair<int, int>& a, pair<int, int>& b) {
    return make_pair(a.second, a.first) < make_pair(b.second, b.first);
  });
  intervs[0].emplace_back();
  intervs[1].emplace_back();
  for (int i = 0; i < n - 1; i++) {
    if (sortx[i].first == sortx[i + 1].first)
      intervs[0].push_back(
          {sortx[i].second, sortx[i + 1].second, sortx[i].first, i});
    if (sorty[i].second == sorty[i + 1].second)
      intervs[1].push_back(
          {sorty[i].first, sorty[i + 1].first, sorty[i].second, i});
  }
  for (int i = 1; i < intervs[0].size(); i++)
    for (int j = 1; j < intervs[1].size(); j++)
      if (intersect(intervs[0][i], intervs[1][j]))
        Graph::adiast[i].push_back(j);
  Graph::solve(intervs[0].size() - 1);
  vector<Interv> ans[2];
  for (int i = 1; i < intervs[0].size(); i++)
    if (!Graph::activst[i]) urm[0][intervs[0][i].from] = 1, cardans--;
  for (int i = 1; i < intervs[1].size(); i++)
    if (!Graph::activdr[i]) urm[1][intervs[1][i].from] = 1, cardans--;
  Interv act[2];
  bool nou[2] = {1, 1};
  for (int i = 0; i < n; i++) {
    if (nou[0])
      act[0] = {sortx[i].second, sortx[i].second, sortx[i].first, 0};
    else
      act[0].dr = sortx[i].second;
    if (urm[0][i])
      nou[0] = 0;
    else
      ans[0].push_back(act[0]), nou[0] = 1;
    if (nou[1])
      act[1] = {sorty[i].first, sorty[i].first, sorty[i].second, 0};
    else
      act[1].dr = sorty[i].first;
    if (urm[1][i])
      nou[1] = 0;
    else
      ans[1].push_back(act[1]), nou[1] = 1;
  }
  assert(ans[1].size() + ans[0].size() == cardans);
  cout << ans[1].size() << '\n';
  for (auto i : ans[1])
    cout << i.st << ' ' << i.h << ' ' << i.dr << ' ' << i.h << '\n';
  cout << ans[0].size() << '\n';
  for (auto i : ans[0])
    cout << i.h << ' ' << i.st << ' ' << i.h << ' ' << i.dr << '\n';
  return 0;
}
