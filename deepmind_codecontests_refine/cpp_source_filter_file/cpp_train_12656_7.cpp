#include <bits/stdc++.h>
using namespace std;
const int NBFEUILLE = 1 << 2;
struct noeud {
  int maximum, infoDescente;
} arbre[NBFEUILLE * 2];
int valeurElement[NBFEUILLE];
void update(int n) {
  if (n >= NBFEUILLE) return;
  for (int f = 2 * n; f < 2 * n + 2; f++) {
    arbre[f].infoDescente += arbre[n].infoDescente;
    arbre[f].maximum += arbre[n].infoDescente;
  }
  arbre[n].infoDescente = 0;
}
void inserer(int inf, int sup, int valeur, int debut = 0,
             int fin = NBFEUILLE - 1, int racine = 1) {
  if (inf > fin || sup < debut) return;
  if (inf <= debut && fin <= sup) {
    arbre[racine].maximum += valeur;
    arbre[racine].infoDescente += valeur;
    return;
  }
  update(racine);
  inserer(inf, sup, valeur, debut, (debut + fin) / 2, racine * 2);
  inserer(inf, sup, valeur, (debut + fin) / 2 + 1, fin, racine * 2 + 1);
  arbre[racine].maximum =
      max(arbre[racine * 2].maximum, arbre[racine * 2 + 1].maximum);
}
int trouverPos() {
  if (arbre[1].maximum < 1) return -1;
  int rep = 1;
  while (rep < NBFEUILLE) {
    update(rep);
    if (arbre[2 * rep + 1].maximum < 1)
      rep *= 2;
    else
      rep = rep * 2 + 1;
  }
  return valeurElement[rep - NBFEUILLE];
}
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int t, type, n;
    scanf("%d %d", &t, &type);
    if (type) {
      scanf("%d", &n);
      valeurElement[t] = n;
    }
    inserer(1, t, type * 2 - 1);
    printf("%d\n", trouverPos());
  }
}
