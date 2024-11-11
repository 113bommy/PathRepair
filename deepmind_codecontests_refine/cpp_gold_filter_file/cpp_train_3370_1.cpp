#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int sup, sud;
int swp, swd;
set<int> elp;
set<int>::iterator cel;
set<int>::iterator cwai;
set<int> wai;
pair<int, int> tim[100001];
int sta[100001];
int des[100001];
vector<int> fdst[100001];
vector<int> fwai[100001];
long long int ct;
int cf = 1, cip = 0;
long long int ans[100001];
bool up;
pair<int, int> nulf;
int pout() {
  int r;
  cel = elp.find(cf);
  if (cel == elp.end()) return 0;
  for (r = 0; r < fdst[cf].size(); ++r) {
    ans[fdst[cf][r]] = ct;
  }
  fdst[cf].clear();
  elp.erase(cel);
  return r;
}
int pin() {
  int j;
  cwai = wai.find(cf);
  if (cwai == wai.end()) return 0;
  for (j = 0; j < fwai[cf].size(); ++j) {
    int i = fwai[cf][j];
    int de = des[i];
    fdst[de].push_back(i);
    elp.insert(de);
    if (de > cf)
      sup++;
    else
      sud++;
  }
  wai.erase(cwai);
  fwai[cf].clear();
  return j;
}
inline void arriv() {
  if (cip >= n) return;
  while ((tim[cip].first == ct) && (cip < n)) {
    int i = tim[cip].second;
    int f = sta[i];
    wai.insert(f);
    fwai[f].push_back(i);
    if (f > cf)
      swp++;
    else if (f < cf)
      swd++;
    else
      (up ? swp++ : swd++);
    ++cip;
  }
  return;
}
inline int nearf(set<int>& flos, bool up) {
  cel = flos.lower_bound(cf);
  if (up) {
    if (cel != flos.end()) return (*cel - cf);
  } else {
    --cel;
    if (cel != flos.end()) return (cf - *cel);
  }
  return 1000000001;
}
int mintime() {
  int tm = 1000000001;
  if (cip < n) tm = tim[cip].first - (int)ct;
  if (!elp.empty()) {
    tm = min(tm, nearf(elp, up));
  }
  if (!wai.empty()) {
    tm = min(tm, nearf(wai, up));
  }
  return tm;
}
int main() {
  cin >> n >> m;
  int t, st, fi;
  for (int i = 0; i < n; ++i) {
    scanf("%i%i%i", &t, &sta[i], &des[i]);
    tim[i] = make_pair(t, i);
  }
  sort(tim, tim + n);
  int mint = 0;
  int ou, in;
  int itr = 0;
  while (cip < n || !elp.empty() || !wai.empty()) {
    up = ((sup + swp) >= (sud + swd));
    mint = mintime();
    ct += (long long int)mint;
    if (!elp.empty() || !wai.empty()) {
      if (up)
        cf += mint;
      else
        cf -= mint;
    }
    arriv();
    ou = 0;
    in = 0;
    if (!elp.empty()) ou = pout();
    if (!wai.empty()) in = pin();
    if (up) {
      sup -= ou;
      swp -= in;
    } else {
      sud -= ou;
      swd -= in;
    }
    ++itr;
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << endl;
  }
  return 0;
}
