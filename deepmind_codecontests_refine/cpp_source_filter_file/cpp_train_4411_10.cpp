#include <bits/stdc++.h>
using namespace std;
long long int M, N, K, modatos[16066];
vector<long long int> e[100666];
vector<long long int> d[100666];
map<pair<long long int, long long int>, long long int> kabourhs;
long long int retard(long long int pios, long long int pote) {
  long long int dvorak;
  dvorak = kabourhs[make_pair(pios, pote)];
  if (dvorak == 0) {
    return 0;
  } else if (dvorak == 1) {
    kabourhs[make_pair(pios, pote)] += retard(pios, pote + 1);
    return kabourhs[make_pair(pios, pote)];
  } else {
    return dvorak;
  }
}
long long int Diejcraft(long long int sak, long long int se) {
  set<pair<long long int, long long int> > setparas;
  long long int who, trexalasa, son;
  long long int dvorak, tmp;
  memset(modatos, -1, sizeof(modatos));
  modatos[sak] = 0;
  modatos[sak] += retard(sak, modatos[sak]);
  setparas.insert(make_pair(modatos[sak], sak));
  while (setparas.size() != 0) {
    who = (*(setparas.begin())).second;
    if (who == se) {
      return modatos[who];
    }
    dvorak = (*(setparas.begin())).first;
    setparas.erase(setparas.begin());
    for (trexalasa = 1; trexalasa <= e[who].size(); ++trexalasa) {
      tmp = d[who][trexalasa - 1] + modatos[who];
      son = e[who][trexalasa - 1];
      if (modatos[son] == -1) {
        modatos[son] = tmp;
        modatos[son] += retard(son, modatos[son]);
        setparas.insert(make_pair(modatos[son], son));
      } else if (modatos[son] > tmp) {
        setparas.erase(setparas.find(make_pair(modatos[son], son)));
        modatos[son] = tmp;
        modatos[son] += retard(son, modatos[son]);
        setparas.insert(make_pair(modatos[son], son));
      }
    }
  }
  return -1;
}
int main() {
  long long int patatas, trexalasa, trexalasb, polak, koulak, dvorak, paparas;
  scanf("%lld %lld", &N, &M);
  for (trexalasa = 1; trexalasa <= M; ++trexalasa) {
    scanf("%lld %lld %lld", &polak, &koulak, &dvorak);
    e[polak].push_back(koulak);
    e[koulak].push_back(polak);
    d[polak].push_back(dvorak);
    d[koulak].push_back(dvorak);
  }
  for (trexalasa = 1; trexalasa <= N; ++trexalasa) {
    scanf("%lld", &dvorak);
    for (trexalasb = 1; trexalasb <= dvorak; ++trexalasb) {
      scanf("%lld", &paparas);
      if (trexalasa != N) {
        kabourhs[make_pair(trexalasa, paparas)] = 1;
      }
    }
  }
  patatas = Diejcraft(1, N);
  printf("%lld\n", patatas);
}
