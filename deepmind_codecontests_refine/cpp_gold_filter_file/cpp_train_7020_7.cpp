#include <bits/stdc++.h>
class Cvor {
 public:
  int node, level, odd, even;
  Cvor(int n, int l, int o, int e) {
    node = n;
    level = l;
    odd = o;
    even = e;
  }
};
using namespace std;
vector<vector<int> > graf;
int init[100000], goal[100000], bio[100000];
int n, u, v, odd, even, t;
vector<int> sols;
stack<Cvor*> stek;
Cvor* p;
int main(void) {
  scanf("%d", &n);
  vector<int> vi;
  graf.insert(graf.begin(), n, vi);
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d %d", &u, &v);
    graf[u - 1].push_back(v - 1);
    graf[v - 1].push_back(u - 1);
  }
  for (int i = 0; i < n; ++i) scanf("%d", &init[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &goal[i]);
  stek.push(new Cvor(0, 1, 0, 0));
  while (!stek.empty()) {
    p = stek.top();
    stek.pop();
    if (bio[p->node]) continue;
    bio[p->node] = 1;
    if (p->level % 2 && p->odd % 2) init[p->node] = (init[p->node]) ? 0 : 1;
    if (p->level % 2 == 0 && p->even % 2)
      init[p->node] = (init[p->node]) ? 0 : 1;
    if (init[p->node] != goal[p->node]) {
      sols.push_back(p->node + 1);
      t = 1;
    } else
      t = 0;
    for (int i = 0; i < graf[p->node].size(); ++i)
      stek.push(new Cvor(graf[p->node][i], p->level + 1,
                         p->odd + ((t && p->level % 2) ? 1 : 0),
                         p->even + ((t && p->level % 2 == 0) ? 1 : 0)));
    delete p;
  }
  printf("%d\n", sols.size());
  for (int i = 0; i < sols.size(); ++i) printf("%d\n", sols[i]);
  return 0;
}
