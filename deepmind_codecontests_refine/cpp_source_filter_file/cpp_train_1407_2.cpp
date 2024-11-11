#include <bits/stdc++.h>
using namespace std;
const int inft = 1000000009;
const int MAXM = 300006;
int ans[MAXM];
pair<pair<int, int>, pair<int, int> > E[MAXM], E2[MAXM];
int REP[MAXM];
int par[MAXM];
int bad;
int siz[MAXM];
vector<pair<int *, int> > hist;
void ustaw(int &gdzie, int co) {
  if (gdzie != co) {
    hist.push_back(make_pair(&gdzie, gdzie));
    gdzie = co;
  }
}
int find(int first) {
  if (REP[first] != first) ustaw(REP[first], find(REP[first]));
  return REP[first];
}
void onion(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  if (siz[a] < siz[b]) swap(a, b);
  ustaw(siz[a], siz[a] + siz[b]);
  if (par[b] && par[a]) ustaw(bad, bad - 2);
  ustaw(par[a], par[a] ^ par[b]);
  ustaw(REP[b], a);
}
void cofnij(int h) {
  while (hist.size() > h) {
    *(hist.back().first) = hist.back().second;
    hist.pop_back();
  }
}
int n;
void go(int l, int r, int lo, int hi) {
  if (l > r) return;
  int h = hist.size();
  int m = (l + r) / 2;
  int last = lo;
  for (int i = l; i <= m; ++i)
    if (E2[i].first.first < E[lo].first.first)
      onion(E2[i].second.first, E2[i].second.second);
  for (int i = lo; i <= hi && bad; ++i)
    if (E[i].first.second <= m) {
      onion(E[i].second.first, E[i].second.second);
      last = i;
    }
  if (bad == 0) {
    cofnij(h);
    ans[m] = E[last].first.first;
    for (int i = l; i <= m; ++i)
      if (E2[i].first.first < E[lo].first.first)
        onion(E2[i].second.first, E2[i].second.second);
    go(m + 1, r, lo, last);
    cofnij(h);
    for (int i = lo; i <= last; ++i)
      if (E[i].first.second < l) {
        onion(E[i].second.first, E[i].second.second);
      }
    go(l, m - 1, last, hi);
    cofnij(h);
  } else {
    for (int i = l; i <= m; ++i) {
      ans[i] = -1;
    }
    cofnij(h);
    for (int i = l; i <= m + 1; ++i)
      if (E2[i].first.first <= E[lo].first.first)
        onion(E2[i].second.first, E2[i].second.second);
    go(m + 1, r, lo, hi);
    cofnij(h);
  }
}
int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (m); ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a;
    --b;
    E[i] = pair<pair<int, int>, pair<int, int> >(pair<int, int>(c, i),
                                                 pair<int, int>(a, b));
    E2[i] = E[i];
  }
  bad = n;
  for (int i = 0; i < (n); ++i) par[i] = 1;
  for (int i = 0; i < (n); ++i) REP[i] = i;
  for (int i = 0; i < (n); ++i) siz[i] = 1;
  sort(E, E + m);
  go(0, m - 1, 0, m - 1);
  for (int i = 0; i < (m); ++i) printf("%d\n", ans[i]);
  return 0;
}
