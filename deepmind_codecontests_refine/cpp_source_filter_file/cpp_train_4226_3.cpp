#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<unsigned long long, unsigned long long>,
            pair<unsigned long long, unsigned long long> > >
    vm;
vector<pair<unsigned long long, pair<unsigned long long, unsigned long long> > >
    v;
unsigned long long n, m, pg, ps, i, a, b, g, s, gs, nr, mn, dad[205], bgo;
unsigned long long cost(unsigned long long g, unsigned long long s) {
  unsigned long long c = g * pg + s * ps;
  return c;
}
unsigned long long
calc(vector<
     pair<unsigned long long, pair<unsigned long long, unsigned long long> > >
         v) {
  unsigned long long mx = 0, s = v.size();
  for (unsigned long long i = 0; i < s; i++) mx = max(mx, v[i].first);
  return mx;
}
unsigned long long fdad(unsigned long long nr) {
  if (dad[nr] == nr) return nr;
  dad[nr] = fdad(dad[nr]);
  return dad[nr];
}
vector<pair<unsigned long long, pair<unsigned long long, unsigned long long> > >
go(vector<
    pair<unsigned long long, pair<unsigned long long, unsigned long long> > >
       v) {
  vector<
      pair<unsigned long long, pair<unsigned long long, unsigned long long> > >
      vr;
  sort(v.begin(), v.end());
  unsigned long long i, da, db;
  for (i = 0; i < n + 5; i++) dad[i] = i;
  unsigned long long k = 0;
  unsigned long long s = v.size();
  for (i = 0; i < s; i++) {
    da = fdad(v[i].second.first);
    db = fdad(v[i].second.second);
    if (da != db) {
      vr.push_back(v[i]);
      k++;
      dad[da] = db;
    }
    if (k == n - 1) return vr;
  }
  bgo = 1;
  return vr;
}
int main(void) {
  scanf("%I64d%I64d", &n, &m);
  scanf("%I64d%I64d", &pg, &ps);
  for (i = 1; i <= m; i++) {
    scanf("%I64d%I64d%I64d%I64d", &a, &b, &g, &s);
    vm.push_back(make_pair(make_pair(g, s), make_pair(a, b)));
  }
  vm.push_back(make_pair(make_pair(2000000000, 2000000000), make_pair(0, 0)));
  sort(vm.begin(), vm.end());
  mn = 1000000000000000000;
  for (i = 0; i < m; i = i) {
    gs = vm[i].first.first;
    while (vm[i].first.first == gs) {
      v.push_back(make_pair(vm[i].first.second, vm[i].second));
      i++;
    }
    bgo = 0;
    v = go(v);
    if (bgo == 0) {
      nr = calc(v);
      nr = cost(gs, nr);
      if (nr < mn) mn = nr;
    }
  }
  if (mn == 1000000000000000000)
    cout << "-1";
  else
    cout << mn;
  return 0;
}
