#include <bits/stdc++.h>
using namespace std;
int N;
int Res[200005];
int M, Q;
vector<pair<int, int> > G[1005], V[200005], V2[200005];
pair<int, int> E[200005];
bitset<1005> DP[200005];
int Lastl[1005], Lastr[1005];
bitset<1005> Aux;
struct Query {
  int l, r, u, v;
} X[200005];
int binS(int node, int time) {
  int mid, left = 0, right = G[node].size() - 1, sol = -1;
  while (left <= right) {
    mid = (left + right) / 2;
    if (G[node][mid].second <= time) {
      sol = mid;
      left = mid + 1;
    } else
      right = mid - 1;
  }
  if (sol != -1) sol = G[node][sol].second;
  return sol;
}
int binS2(int node, int time) {
  int mid, left = 0, right = G[node].size() - 1, sol = -1;
  while (left <= right) {
    mid = (left + right) / 2;
    if (G[node][mid].second >= time) {
      sol = mid;
      right = mid - 1;
    } else
      left = mid + 1;
  }
  if (sol != -1) sol = G[node][sol].second;
  return sol;
}
void precalcV() {
  for (int i = 1; i <= Q; i++) {
    scanf("%d%d%d%d", &X[i].l, &X[i].r, &X[i].u, &X[i].v);
    int l = binS2(X[i].u, X[i].l);
    int r = binS(X[i].v, X[i].r);
    X[i].l = l;
    X[i].r = r;
    if (l == -1 || r == -1) continue;
    V[l].push_back(make_pair(r, i));
    V2[r].push_back(make_pair(l, i));
  }
}
void Solve(int left, int right) {
  int mid = (left + right) / 2;
  if (left == right) {
    for (int i = 0; i < V[left].size(); i++) {
      int r = V[left][i].first, pos = V[left][i].second;
      if (r > right) continue;
      if ((X[pos].u == E[left].first && X[pos].v == E[left].second) ||
          (X[pos].v == E[left].first && X[pos].u == E[left].second))
        Res[pos] = 1;
    }
    return;
  }
  Solve(left, mid);
  Solve(mid + 1, right);
  for (int i = left; i <= right; i++) {
    int x = E[i].first, y = E[i].second;
    Lastl[x] = Lastr[x] = Lastl[y] = Lastr[y] = 0;
  }
  DP[mid].reset();
  for (int i = mid; i >= left; i--) {
    DP[i].reset();
    int x = E[i].first, y = E[i].second;
    DP[i][x] = 1;
    DP[i][y] = 1;
    if (Lastl[x] != 0) DP[i] |= DP[Lastl[x]];
    if (Lastl[y] != 0) DP[i] |= DP[Lastl[y]];
    Lastl[x] = Lastl[y] = i;
  }
  for (int i = mid; i <= right; i++) {
    DP[i].reset();
    int x = E[i].first, y = E[i].second;
    DP[i][x] = 1;
    DP[i][y] = 1;
    if (Lastr[x] != 0) DP[i] |= DP[Lastr[x]];
    if (Lastr[y] != 0) DP[i] |= DP[Lastr[y]];
    Lastr[x] = Lastr[y] = i;
  }
  for (int i = mid; i <= right; i++) {
    for (int j = 0; j < V2[i].size(); j++) {
      int l = V2[i][j].first, pos = V2[i][j].second;
      if (l > mid || l < left) continue;
      if ((DP[i] & DP[l]).count() != 0) Res[pos] = 1;
    }
  }
}
void Read() {
  scanf("%d%d%d", &N, &M, &Q);
  for (int i = 1; i <= M; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(make_pair(y, i));
    G[y].push_back(make_pair(x, i));
    E[i] = make_pair(x, y);
  }
}
int main() {
  Read();
  precalcV();
  Solve(1, M);
  for (int i = 1; i <= Q; i++) {
    if (Res[i] == 0)
      printf("No\n");
    else
      printf("Yes\n");
  }
  return 0;
}
