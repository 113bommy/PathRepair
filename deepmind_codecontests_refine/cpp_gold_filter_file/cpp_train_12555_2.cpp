#include <bits/stdc++.h>
using namespace std;
int N;
pair<int, int> padre[5000];
list<pair<int, int> > adj[5000];
int carg[5000][2 * 5000 + 5];
int res[5000];
pair<int, int> prior[5000];
int dis[5000];
bool usd[5000];
void busca(int pos, pair<int, int> ant, int W) {
  list<pair<int, int> >::iterator it;
  padre[pos] = ant;
  dis[pos] = W;
  for (it = adj[pos].begin(); it != adj[pos].end(); it++) {
    if ((*it).first != ant.first)
      busca((*it).first, pair<int, int>(pos, (*it).second), W + 1);
  }
}
int main() {
  int i, j, pos;
  int A, B, C, t, t2;
  pair<int, int> tmp;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &prior[i].first);
    prior[i].second = i;
  }
  sort(prior, prior + N);
  for (i = 1; i < N; i++) {
    scanf("%d%d%d", &A, &B, &C);
    A--, B--;
    adj[A].push_back(pair<int, int>(B, C));
    adj[B].push_back(pair<int, int>(A, C));
  }
  busca(0, pair<int, int>(-1, -1), 0);
  for (i = 0; i < N; i++) {
    tmp = pair<int, int>((1 << 30), (1 << 30));
    for (j = 0; j < N; j++)
      if (!usd[j]) tmp = min(tmp, pair<int, int>(prior[j].first, dis[j]));
    for (j = 0; j < N; j++)
      if (!usd[j] && pair<int, int>(prior[j].first, dis[j]) == tmp) break;
    pos = prior[j].second;
    usd[j] = 1;
    t = 0;
    while (pos) {
      t2 = 1;
      for (j = t; carg[pos][j] >= padre[pos].second; j++) {
        t2 += carg[pos][j] / padre[pos].second;
      }
      carg[pos][j]++;
      t += t2;
      pos = padre[pos].first;
    }
    res[prior[i].second] = t;
  }
  for (i = 0; i < N; i++) printf("%d ", res[i]);
  printf("\n");
  return 0;
}
