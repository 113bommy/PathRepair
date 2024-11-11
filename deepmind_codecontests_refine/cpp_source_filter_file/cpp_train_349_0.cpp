#include <bits/stdc++.h>
using namespace std;
int vist[502][502][2], n, m;
int pathRet[502][502][2];
vector<int> gra[502];
struct state {
  int indA;
  int indB;
  int cantMov;
  int pers;
};
queue<state> cola;
void bfs() {
  vector<int> pathA, pathB;
  memset(vist, 0, sizeof(vist));
  memset(pathRet, 0, sizeof(pathRet));
  state act, next;
  act.indA = 1;
  act.indB = n;
  act.cantMov = 0;
  act.pers = 0;
  cola.push(act);
  vist[act.indA][act.indB][act.pers] = 1;
  while (!cola.empty()) {
    act = cola.front();
    cola.pop();
    if (act.indA == n && act.indB == 1 && act.pers == 0) break;
    if (act.pers == 0) {
      next.indB = act.indB;
      next.cantMov = act.cantMov + 1;
      next.pers = 1;
      for (int i = 0; i < gra[act.indA].size(); i++) {
        next.indA = gra[act.indA][i];
        if (!vist[next.indA][act.indB][next.pers]) {
          vist[next.indA][act.indB][next.pers] = 1;
          pathRet[next.indA][act.indB][next.pers] = act.indA;
          cola.push(next);
        }
      }
    } else {
      next.indA = act.indA;
      next.cantMov = act.cantMov;
      next.pers = 0;
      for (int i = 0; i < gra[act.indB].size(); i++) {
        next.indB = gra[act.indB][i];
        if (next.indA == next.indB) continue;
        if (!vist[act.indA][next.indB][next.pers]) {
          vist[act.indA][next.indB][next.pers] = 0;
          pathRet[act.indA][next.indB][next.pers] = act.indB;
          cola.push(next);
        }
      }
    }
  }
  if (act.indA != n || act.indB != 1 || act.pers != 0)
    printf("-1\n");
  else {
    for (int i = 0; i < act.cantMov * 2 + 2; i++) {
      if (act.pers == 0) {
        pathB.push_back(act.indB);
        act.indB = pathRet[act.indA][act.indB][act.pers];
        act.pers = 1;
      } else {
        pathA.push_back(act.indA);
        act.indA = pathRet[act.indA][act.indB][act.pers];
        act.pers = 0;
      }
    }
    reverse(pathA.begin(), pathB.end());
    reverse(pathA.begin(), pathB.end());
    printf("%d\n", act.cantMov);
    for (int i = 0; i < pathB.size(); i++)
      printf("%d%c", pathB[i], i + 1 != pathB.size() ? ' ' : '\n');
    for (int i = 0; i < pathA.size(); i++)
      printf("%d%c", pathA[i], i + 1 != pathA.size() ? ' ' : '\n');
  }
}
int main() {
  int a, b;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    gra[a].push_back(b);
    gra[b].push_back(a);
  }
  bfs();
  return 0;
}
