#include <bits/stdc++.h>
using namespace std;
const int mxx = 1000069;
int n, m, x, y, z, p, q, r;
int ara[mxx];
vector<int> edges[mxx], perbit[mxx][3];
char str[5];
int val[mxx];
int getSize(int pos) {
  return (int)((int)perbit[pos][0].size() + (int)perbit[pos][1].size());
}
void sameUp(int chld, int par) {
  for (int i = 0; i < 2; i++) perbit[par][i].swap(perbit[chld][i]);
}
void revUp(int chld, int par) {
  for (int i = 0; i < 2; i++) perbit[par][1 - i].swap(perbit[chld][i]);
}
void dfs2(int pos) {
  if (ara[pos] == 4) return;
  for (int to : edges[pos]) dfs2(to);
  if (ara[pos] == 3) val[pos] = 1 - val[edges[pos][0]];
  if (ara[pos] == 2) val[pos] = val[edges[pos][0]] ^ val[edges[pos][1]];
  if (ara[pos] == 1) val[pos] = val[edges[pos][0]] | val[edges[pos][1]];
  if (ara[pos] == 0) val[pos] = val[edges[pos][0]] & val[edges[pos][1]];
}
void dfs(int pos) {
  if (ara[pos] == 4) {
    perbit[pos][1 - val[pos]].push_back(pos);
    return;
  }
  if (ara[pos] == 3) {
    dfs(edges[pos][0]);
    int to = edges[pos][0];
    perbit[pos][1].swap(perbit[to][0]);
    perbit[pos][0].swap(perbit[to][1]);
    perbit[to][0].clear();
    perbit[to][1].clear();
    return;
  }
  for (int to : edges[pos]) dfs(to);
  int to1 = edges[pos][0];
  int to2 = edges[pos][1];
  if (getSize(to1) > getSize(to2)) swap(to1, to2);
  if (ara[pos] == 2) {
    if (val[to1] == 0) {
      sameUp(to2, pos);
    } else
      revUp(to2, pos);
    int vall = val[to2];
    for (int i = 0; i < 2; i++) {
      int ccc = i ^ vall;
      for (int j : perbit[to1][i]) perbit[pos][ccc].push_back(j);
    }
  } else if (ara[pos] == 1) {
    if (val[to1] == 0) {
      sameUp(to2, pos);
    } else {
      if (perbit[to2][1].size() > perbit[to2][0].size()) {
        perbit[pos][1].swap(perbit[to2][1]);
        for (int j : perbit[to2][0]) perbit[pos][1].push_back(j);
      } else {
        perbit[pos][1].swap(perbit[to2][0]);
        for (int j : perbit[to2][1]) perbit[pos][1].push_back(j);
      }
    }
    if (val[to2] == 0) {
      for (int i = 0; i < 2; i++) {
        for (int j : perbit[to1][i]) perbit[pos][i].push_back(j);
      }
    } else {
      for (int i = 0; i < 2; i++) {
        for (int j : perbit[to1][i]) perbit[pos][1].push_back(j);
      }
    }
  } else {
    if (val[to1] == 1) {
      sameUp(to2, pos);
    } else {
      if (perbit[to2][1].size() > perbit[to2][0].size()) {
        perbit[pos][0].swap(perbit[to2][1]);
        for (int j : perbit[to2][0]) perbit[pos][0].push_back(j);
      } else {
        perbit[pos][0].swap(perbit[to2][0]);
        for (int j : perbit[to2][1]) perbit[pos][0].push_back(j);
      }
    }
    if (val[to2] == 1) {
      for (int i = 0; i < 2; i++) {
        for (int j : perbit[to1][i]) perbit[pos][i].push_back(j);
      }
    } else {
      for (int i = 0; i < 2; i++) {
        for (int j : perbit[to1][i]) perbit[pos][0].push_back(j);
      }
    }
  }
  perbit[to1][0].clear();
  perbit[to1][1].clear();
  perbit[to2][0].clear();
  perbit[to2][1].clear();
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%s", str);
    if (str[0] == 'A' || str[0] == 'O' || str[0] == 'X') {
      int x, y;
      scanf("%d %d", &x, &y);
      edges[i].push_back(x);
      edges[i].push_back(y);
      if (str[0] == 'A') ara[i] = 0;
      if (str[0] == 'O') ara[i] = 1;
      if (str[0] == 'X') ara[i] = 2;
    } else {
      int x;
      scanf("%d", &x);
      if (str[0] == 'I')
        val[i] = x, ara[i] = 4;
      else
        edges[i].push_back(x), ara[i] = 3;
    }
  }
  dfs2(1);
  dfs(1);
  vector<pair<int, int> > vec;
  for (int i = 1; i <= 1; i++) {
    for (int j = 0; j < 2; j++) {
      for (int val : perbit[i][j]) vec.push_back({val, j});
    }
  }
  sort(vec.begin(), vec.end());
  for (auto val : vec) printf("%c", '0' + val.second);
  return 0;
}
