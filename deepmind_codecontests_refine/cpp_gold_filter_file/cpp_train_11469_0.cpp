#include <bits/stdc++.h>
using namespace std;
const long long BIG = 1000000000000000000LL;
void solve();
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
const long long borne = 2 * (long long)(1e5) + 5;
long long nbTypes, nbOffres;
long long reqIni[borne];
vector<long long> spec[borne];
long long dejaVu[borne];
long long tps = 0;
bool ok(long long derJour) {
  ++tps;
  long long dep = min(derJour, borne - 2);
  vector<pair<long long, long long> > ordre;
  ordre.reserve(nbTypes + 5);
  for (long long jour = (dep + 1 - 1); jour >= (0); --jour) {
    for (long long reduc : spec[jour]) {
      if (dejaVu[reduc] == tps) continue;
      ordre.push_back({reduc, jour});
      dejaVu[reduc] = tps;
    }
  }
  reverse(ordre.begin(), ordre.end());
  long long curMonnaie = 0;
  long long lst = 0;
  vector<long long> req(nbTypes);
  for (long long mode = (0); mode < (nbTypes); ++mode) req[mode] = reqIni[mode];
  for (auto cx : ordre) {
    long long jour = cx.second;
    curMonnaie += (jour - lst);
    lst = jour;
    long long mode = cx.first;
    long long rem = min(curMonnaie, req[mode]);
    curMonnaie -= rem;
    req[mode] -= rem;
  }
  curMonnaie += (derJour - lst);
  for (long long mode = (0); mode < (nbTypes); ++mode)
    curMonnaie -= 2 * req[mode];
  return (curMonnaie >= 0);
}
void solve() {
  cin >> nbTypes >> nbOffres;
  for (long long i = (0); i < (nbTypes); ++i) cin >> reqIni[i];
  for (long long i = (0); i < (nbOffres); ++i) {
    long long jour, mode;
    cin >> jour >> mode;
    --mode;
    spec[jour].push_back(mode);
  }
  long long l = 1, r = borne * borne * 2;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << "\n";
}
