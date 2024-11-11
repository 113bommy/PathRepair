#include <bits/stdc++.h>
using namespace std;
int n, m, K, S1, S2, F, l, r, x, y, z, res[110], first[10010];
long long dis[10010], inf = 1e17;
bool grb[4];
vector<pair<int, int> > R[10010];
vector<pair<pair<int, int>, pair<int, int> > > E[10010];
set<pair<long long, int> > A;
void read(int &x) {
  char ch = getchar();
  int mark = 1;
  for (; ch != '-' && (ch < '0' || ch > '9'); ch = getchar())
    ;
  if (ch == '-') mark = -1, ch = getchar();
  for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
  x *= mark;
}
void print() {
  for (int i = 1; i < K; i++) printf("%d ", res[i]);
  printf("%d\n", res[K]);
}
void updata(int u, int v, long long len) {
  if (dis[v] == len) first[v] |= first[u];
  if (dis[v] > len) {
    A.erase(make_pair(dis[v], v));
    dis[v] = len;
    A.insert(make_pair(dis[v], v));
    first[v] = first[u];
  }
}
void dijkstra() {
  memset(first, 0, sizeof(first));
  for (int i = 1; i <= n; i++) dis[i] = inf;
  dis[S1] = 0;
  first[S1] = 1;
  dis[S2] = 0;
  first[S2] = 2;
  for (int i = 1; i <= n; i++) A.insert(make_pair(dis[i], i));
  while (A.size()) {
    pair<long long, int> it = *A.begin();
    A.erase(A.begin());
    long long len = it.first;
    int u = it.second;
    for (int i = 0; i < R[u].size(); i++) {
      int v = R[u][i].first, l = R[u][i].second;
      updata(u, v, len + l);
    }
    for (int i = 0; i < E[u].size(); i++) {
      int ind = E[u][i].first.first, v = E[u][i].first.second;
      int l = E[u][i].second.first, r = E[u][i].second.second;
      if (grb[first[u]])
        res[ind] = l;
      else
        res[ind] = r;
      updata(u, v, len + res[ind]);
    }
  }
}
int main() {
  read(n);
  read(m);
  read(K);
  read(S1);
  read(S2);
  read(F);
  for (int i = 1; i <= m; i++) {
    read(x);
    read(y);
    read(z);
    R[x].push_back(make_pair(y, z));
  }
  for (int i = 1; i <= K; i++) {
    read(x);
    read(y);
    read(l);
    read(r);
    E[x].push_back(make_pair(make_pair(i, y), make_pair(l, r)));
    res[i] = l;
  }
  if (S1 == S2) {
    printf("DRAW\n");
    print();
    return 0;
  }
  grb[1] = 1;
  dijkstra();
  if (first[F] == 1) {
    printf("WIN\n");
    print();
    return 0;
  }
  grb[3] = 1;
  dijkstra();
  if (first[F] == 2)
    printf("LOSE\n");
  else {
    printf("DRAW\n");
    print();
    return 0;
  }
  return 0;
}
