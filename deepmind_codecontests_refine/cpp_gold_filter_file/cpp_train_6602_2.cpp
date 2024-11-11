#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
inline int FIX(int a) { return (a % Mod + Mod) % Mod; }
const int N = 300000 + 5;
int n, m;
int x[N], y[N];
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
set<pair<int, int>> S;
map<int, int> M;
vector<int> E[N], Ex;
vector<pair<int, int>> R[N], go[N];
int main() {
  scanf("%d %d", &n, &m);
  Ex.emplace_back(1);
  Ex.emplace_back(n);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &x[i], &y[i]);
    Ex.push_back(x[i]);
  }
  (sort(begin(Ex), end(Ex)), Ex.erase(unique(begin(Ex), end(Ex)), end(Ex)));
  vector<int> tmp;
  for (int i = 0; i < Ex.size(); i++) {
    tmp.push_back(Ex[i]);
    if (Ex[i] > Ex[i - 1] + 1) {
      tmp.push_back(Ex[i - 1] + 1);
    }
  }
  (sort(begin(tmp), end(tmp)),
   tmp.erase(unique(begin(tmp), end(tmp)), end(tmp)));
  Ex = std::move(tmp);
  int line = (int)Ex.size();
  for (int i = 0; i < line; i++) M[Ex[i]] = i;
  for (int i = 1; i <= m; i++) {
    E[M[x[i]]].push_back(y[i]);
  }
  for (int i = 0; i < line; i++) {
    sort(begin(E[i]), end(E[i]));
    if (E[i].size() == 0) {
      R[i].emplace_back(1, n);
      continue;
    }
    if (E[i][0] != 1) {
      R[i].emplace_back(1, E[i][0] - 1);
    }
    for (int j = 0; j < E[i].size() - 1; j++) {
      if (E[i][j] + 1 <= E[i][j + 1] - 1) {
        R[i].emplace_back(E[i][j] + 1, E[i][j + 1] - 1);
      }
    }
    if (E[i][E[i].size() - 1] != n) {
      R[i].emplace_back(E[i][E[i].size() - 1] + 1, n);
    }
  }
  for (int i = 0; i < line; i++) {
    if (i == 0) {
      go[i].push_back(R[i][0]);
      continue;
    }
    int idx = 0;
    for (int j = 0; j < R[i].size(); j++) {
      int l = R[i][j].first, r = R[i][j].second;
      while (idx < go[i - 1].size() && go[i - 1][idx].second < l) idx++;
      if (idx == go[i - 1].size() || go[i - 1][idx].first > r) continue;
      go[i].emplace_back(max(go[i - 1][idx].first, l), r);
    }
  }
  if (go[line - 1].size() > 0 && go[line - 1].back().second == n) {
    printf("%d\n", 2 * n - 2);
  } else
    printf("-1\n");
  return 0;
}
