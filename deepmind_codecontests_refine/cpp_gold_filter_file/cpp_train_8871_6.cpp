#include <bits/stdc++.h>
using namespace std;
struct Arco {
  int v, next;
  Arco() {}
  Arco(int vv, int n) : v(vv), next(n) {}
} edges[100000];
int last[3003], E;
int num[3003], inS[3003];
vector<pair<int, int> > brdg;
vector<vector<int> > tecomp;
int S[3003], roots[3003];
int n, ndfs, topS, topR;
int i, m;
void visit(int v, int u) {
  inS[v] = num[v] = ++ndfs;
  S[topS++] = roots[topR++] = v;
  for (int i = last[v]; i; i = edges[i].next) {
    int w = edges[i].v;
    if (!num[w])
      visit(w, v);
    else if (u != w && inS[w])
      while (num[roots[topR - 1]] > num[w]) topR--;
  }
  if (v == roots[topR - 1]) {
    brdg.push_back(make_pair(u, v));
    tecomp.push_back(vector<int>());
    while (1) {
      int w = S[--topS];
      inS[w] = false;
      tecomp.back().push_back(w);
      if (v == w) break;
    }
    topR--;
  }
}
void Bridges_CompBiCnx() {
  for (int i = 0; i < n; i++) num[i] = inS[i] = 0;
  topS = topR = 0;
  brdg.clear();
  tecomp.clear();
  ndfs = 1;
  for (int i = 0; i < n; i++)
    if (!num[i]) {
      visit(i, n);
      brdg.pop_back();
    }
}
void addEdge(int v, int u) {
  edges[E] = Arco(u, last[v]);
  last[v] = E++;
}
bool marcas[3003];
int D[3003];
int main() {
  int v, u, i;
  E = 1;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &v, &u);
    v--, u--;
    addEdge(v, u);
    addEdge(u, v);
  }
  Bridges_CompBiCnx();
  for (i = (int)tecomp.size() - 1; i >= 0; i--)
    if (tecomp[i].size() > 1) {
      queue<int> cola;
      for (u = tecomp[i].size() - 1; u >= 0; u--) {
        cola.push(tecomp[i][u]);
        marcas[tecomp[i][u]] = 1;
      }
      while (!cola.empty()) {
        v = cola.front();
        cola.pop();
        for (i = last[v]; i; i = edges[i].next) {
          u = edges[i].v;
          if (!marcas[u]) {
            cola.push(u);
            marcas[u] = 1;
            D[u] = 1 + D[v];
          }
        }
      }
      break;
    }
  for (i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", D[i]);
  }
  printf("\n");
  return 0;
}
