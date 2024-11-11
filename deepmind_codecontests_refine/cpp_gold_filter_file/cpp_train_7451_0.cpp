#include <bits/stdc++.h>
using namespace std;
int tailleEnsemble[100 * 1000 + 3];
int dernierVu[100 * 1000 + 3], numero = 1;
int pere[100 * 1000 + 3];
map<long long, int> dictionnaire;
bool couleur[100 * 1000 + 3];
vector<int> frere[100 * 1000 + 3];
int trouverPere(int p) {
  if (pere[p] == p) return p;
  return pere[p] = trouverPere(pere[p]);
}
void echanger(int a) {
  if (dernierVu[a] == numero) return;
  couleur[a] ^= 1;
  dernierVu[a] = numero;
  for (int f : frere[a]) echanger(f);
}
long long lireChaine() {
  long long reponse = 0;
  char tmp = getchar();
  for (int j = 0; 'a' <= tmp && tmp <= 'z'; j++) {
    reponse += tmp;
    reponse *= 26ll;
    tmp = getchar();
  }
  return reponse;
}
int main() {
  int nbNoeud, nbArete, nbQuestion;
  scanf("%d%d%d\n", &nbNoeud, &nbArete, &nbQuestion);
  for (int i = 0; i < nbNoeud; i++) {
    pere[i] = i;
    tailleEnsemble[i] = 1;
    dictionnaire[lireChaine()] = i;
  }
  for (int i = 0; i < nbArete; i++) {
    int choix = getchar() - '1';
    getchar();
    int a = dictionnaire[lireChaine()], b = dictionnaire[lireChaine()];
    if (trouverPere(a) == trouverPere(b)) {
      if ((couleur[a] == couleur[b]) == choix)
        printf("NO\n");
      else
        printf("YES\n");
      continue;
    }
    if ((couleur[a] == couleur[b]) == choix) {
      if (tailleEnsemble[trouverPere(a)] < tailleEnsemble[trouverPere(b)])
        swap(a, b);
      numero++;
      echanger(b);
    }
    frere[a].push_back(b);
    frere[b].push_back(a);
    a = trouverPere(a);
    b = trouverPere(b);
    pere[b] = a;
    tailleEnsemble[a] += tailleEnsemble[b];
    printf("YES\n");
  }
  for (int i = 0; i < nbQuestion; i++) {
    int a = dictionnaire[lireChaine()], b = dictionnaire[lireChaine()];
    if (trouverPere(a) != trouverPere(b))
      printf("3\n");
    else if (couleur[a] == couleur[b])
      printf("1\n");
    else
      printf("2\n");
  }
}
