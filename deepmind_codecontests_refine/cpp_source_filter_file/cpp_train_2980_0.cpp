#include <bits/stdc++.h>
using namespace std;
int a[4][4], b[4][4];
vector<pair<int, int> > ppoints;
vector<pair<int, int> > npgames;
void calcpoint(int newa, int newb, long long int &palice, long long int &pbob) {
  int nexta = (newa + 1);
  int nextb = newb + 1;
  if (nexta == 4) nexta = 1;
  if (nextb == 4) nextb = 1;
  if (nexta == (newb)) {
    pbob++;
  } else {
    if (nextb == newa) palice++;
  }
}
int main() {
  long long k, starta, startb;
  scanf("%lld %lld %lld", &k, &starta, &startb);
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      scanf("%d", &b[i][j]);
    }
  }
  map<pair<int, int>, int> mp;
  mp[make_pair(starta, startb)] = 1;
  npgames.push_back(make_pair(starta, startb));
  int preva = starta;
  int prevb = startb;
  int period = 0;
  int points = 0;
  long long int palice = 0;
  long long int pbob = 0;
  long long int npalice = 0;
  long long int npbob = 0;
  long long alice = 0;
  long long bob = 0;
  while (1) {
    int newa = a[preva][prevb];
    int newb = b[preva][prevb];
    preva = newa;
    prevb = newb;
    if (mp.find(make_pair(newa, newb)) != mp.end()) break;
    mp[make_pair(newa, newb)] = 1;
    npgames.push_back(make_pair(newa, newb));
  }
  mp[make_pair(preva, prevb)] = 2;
  ppoints.push_back(make_pair(0, 0));
  while (1) {
    int newa = a[preva][prevb];
    int newb = b[preva][prevb];
    calcpoint(newa, newb, palice, pbob);
    ppoints.push_back(make_pair(palice, pbob));
    period++;
    preva = newa;
    prevb = newb;
    if (mp[make_pair(preva, prevb)] == 2) {
      mp.erase(make_pair(preva, prevb));
      break;
    }
    mp.erase(make_pair(preva, prevb));
  }
  int nonpgames = 0;
  for (int i = 0; i < npgames.size(); i++) {
    if (mp.find(npgames[i]) == mp.end()) break;
    map<pair<int, int>, int>::iterator it = mp.find(npgames[i]);
    nonpgames++;
    int newa = it->first.first;
    int newb = it->first.second;
    calcpoint(newa, newb, npalice, npbob);
    mp.erase(it);
    if (k == nonpgames) {
      printf("%lld %lld\n", npalice, npbob);
      return 0;
    }
  }
  k -= nonpgames;
  alice += npalice;
  bob += npbob;
  long long q = (k) / period;
  long long rem = (k) % period;
  alice += q * palice;
  bob += q * pbob;
  alice += ppoints[rem].first;
  bob += ppoints[rem].second;
  printf("%lld %lld\n", alice, bob);
  return 0;
}
