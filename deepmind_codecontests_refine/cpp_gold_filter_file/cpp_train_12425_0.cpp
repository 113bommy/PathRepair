#include <bits/stdc++.h>
using namespace std;
int N;
int reach[5000 + 1][2];
list<pair<int, int> > adj[5000];
int child[5000];
bool res[5000 + 1];
int id[5000][5000];
int res_tot;
void foo(int s) {
  memset(reach, 0, sizeof reach);
  reach[0][0] = 1;
  reach[0][1] = -1;
  for (int i = 0; i <= N / 2; i++)
    if (reach[i][0])
      for (list<pair<int, int> >::iterator it = adj[s].begin();
           it != adj[s].end(); it++)
        if (id[s][it->first] > reach[i][1]) {
          reach[i + it->second][1] =
              min(((reach[i + it->second][0]) ? reach[i + it->second][1]
                                              : 5000 * 2 + 3),
                  id[s][it->first]);
          reach[i + it->second][0] = 1;
        }
  for (int i = 1; i <= N / 2 - (N % 2 == 0); i++)
    if (reach[i][0]) {
      res_tot += (!res[i]) * (2 - (i == N - i - 1));
      res[i] = 1;
    }
}
int getSub(int s, int a) {
  if (child[s] == 1) return 1;
  int tot = 0;
  for (list<pair<int, int> >::iterator it = adj[s].begin(); it != adj[s].end();
       it++)
    if (it->first != a) {
      if (!it->second) it->second = getSub(it->first, s);
      tot += it->second;
    }
  return tot + 1;
}
int main() {
  scanf("%d", &N);
  int i, a, b;
  for (i = 0; i < N - 1; i++) {
    scanf("%d %d", &a, &b);
    adj[a - 1].push_back(make_pair(b - 1, 0));
    adj[b - 1].push_back(make_pair(a - 1, 0));
    child[a - 1]++;
    child[b - 1]++;
    id[a - 1][b - 1] = i * 2;
    id[b - 1][a - 1] = i * 2 + 1;
  }
  for (i = 0; i < N; i++)
    for (list<pair<int, int> >::iterator it = adj[i].begin();
         it != adj[i].end(); it++) {
      if (!it->second) it->second = getSub(it->first, i);
    }
  for (i = 0; i < N; i++)
    if (child[i] > 1) {
      foo(i);
    }
  printf("%d\n", res_tot);
  for (i = 1; i < N; i++)
    if (res[i] || res[N - i - 1]) printf("%d %d\n", i, N - i - 1);
  return 0;
}
