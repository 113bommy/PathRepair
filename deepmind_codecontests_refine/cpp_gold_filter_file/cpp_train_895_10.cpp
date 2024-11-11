#include <bits/stdc++.h>
using namespace std;
const int MAX_CARACS = 100 * 1000;
const int MAX_PARENTS = 12;
const int MAX_POKEMONS = 100 * 1000 + 12;
const int MAX_ENSEMBLES = 4096;
int nbCaracs, nbParents, nbReqs;
int nbPokemons;
int caracs_parents[MAX_PARENTS][MAX_CARACS];
int pokemons_of_caracs[MAX_CARACS][MAX_PARENTS];
bitset<MAX_ENSEMBLES> pokemons[MAX_POKEMONS];
int main() {
  scanf("%d%d%d", &nbCaracs, &nbParents, &nbReqs);
  fill(pokemons, pokemons + MAX_POKEMONS, bitset<MAX_ENSEMBLES>(0));
  for (int iParent = 0; iParent < nbParents; iParent++) {
    for (int iCarac = 0; iCarac < nbCaracs; iCarac++) {
      scanf("%d", &caracs_parents[iParent][iCarac]);
      pokemons_of_caracs[iCarac][iParent] = iParent;
    }
    for (int ensemble = 0; ensemble < MAX_ENSEMBLES; ensemble++) {
      if (ensemble & (1 << iParent)) {
        pokemons[iParent][ensemble] = 1;
      }
    }
  }
  for (int iCarac = 0; iCarac < nbCaracs; iCarac++) {
    sort(pokemons_of_caracs[iCarac], pokemons_of_caracs[iCarac] + nbParents,
         [&](const int a, const int b) {
           return caracs_parents[a][iCarac] > caracs_parents[b][iCarac];
         });
  }
  nbPokemons = nbParents;
  for (int iReq = 0; iReq < nbReqs; iReq++) {
    int type_req, poke1, poke2;
    scanf("%d%d%d", &type_req, &poke1, &poke2);
    poke1--, poke2--;
    if (type_req == 1) {
      pokemons[nbPokemons] = pokemons[poke1] | pokemons[poke2];
      nbPokemons++;
    } else if (type_req == 2) {
      pokemons[nbPokemons] = pokemons[poke1] & pokemons[poke2];
      nbPokemons++;
    } else {
      int iCarac = poke2;
      int idMaster = -1;
      int parents_taken = 0;
      for (int iParent = 0; iParent < nbParents; iParent++) {
        int parent = pokemons_of_caracs[iCarac][iParent];
        parents_taken |= (1 << parent);
        if (pokemons[poke1][parents_taken]) {
          idMaster = parent;
          break;
        }
      }
      printf("%d\n", caracs_parents[idMaster][iCarac]);
    }
  }
}
