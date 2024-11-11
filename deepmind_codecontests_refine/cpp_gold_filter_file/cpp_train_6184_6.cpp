#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
using namespace std;
const int maxNoeuds = (int)(1e5) + 5;
vector<int> arbre[maxNoeuds];
vector<int> cendec[maxNoeuds];
int tsa[maxNoeuds];
bool marque[maxNoeuds];
int root = -1;
int nbNoeuds;
char lettre[maxNoeuds];
void dfs(int nod, int par) {
  tsa[nod] = 1;
  for (int voisin : arbre[nod]) {
    if (voisin != par && (!marque[voisin])) {
      dfs(voisin, nod);
      tsa[nod] += tsa[voisin];
    }
  }
}
int getCentroid(int nod, int par, int tot) {
  bool estCentroid = true;
  int suiv = -1, tsaMax = -1;
  for (int voisin : arbre[nod]) {
    if (voisin != par && (!marque[voisin])) {
      if (tsa[voisin] > tot / 2) {
        estCentroid = false;
      }
      if (tsa[voisin] > tsaMax) {
        suiv = voisin;
        tsaMax = tsa[voisin];
      }
    }
  }
  if (estCentroid) {
    return nod;
  } else {
    return getCentroid(suiv, nod, tot);
  }
}
void centroidDecomposition(int nod, int par) {
  dfs(nod, par);
  int cent = getCentroid(nod, par, tsa[nod]);
  if (par != -1)
    cendec[par].push_back(cent);
  else
    root = cent;
  marque[cent] = true;
  for (int voisin : arbre[cent]) {
    if ((!marque[voisin])) {
      centroidDecomposition(voisin, cent);
    }
  }
}
void dfsFinal(int nod, int par) {
  if (nod != root) lettre[nod] = lettre[par] + 1;
  for (int voisin : cendec[nod]) {
    if (voisin != par) {
      dfsFinal(voisin, nod);
    }
  }
}
int main() {
  scanf("%d", &nbNoeuds);
  for (int indLien = 0; indLien < nbNoeuds - 1; ++indLien) {
    int x, y;
    scanf("%d%d", &x, &y);
    arbre[x].push_back(y);
    arbre[y].push_back(x);
  }
  centroidDecomposition(1, -1);
  lettre[root] = 'A';
  dfsFinal(root, -1);
  for (int indNoeud = 1; indNoeud <= nbNoeuds; ++indNoeud) {
    printf("%c ", lettre[indNoeud]);
  }
  printf("\n");
}
