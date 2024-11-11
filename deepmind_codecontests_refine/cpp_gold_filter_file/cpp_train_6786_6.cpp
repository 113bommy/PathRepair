#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 500000;
const long long INF = 1LL << 60;
pair<long long, int> aint[1 + 8 * MAX_N];
long long lazy[1 + 8 * MAX_N];
void init(int nod = 1, int l = 1, int r = 2 * MAX_N) {
  if (l == r)
    aint[nod] = {0, l};
  else {
    int mid = (l + r) / 2;
    init(2 * nod, l, mid);
    init(2 * nod + 1, mid + 1, r);
    aint[nod] = min(aint[2 * nod], aint[2 * nod + 1]);
  }
}
void pushLazy(int nod, int l, int r) {
  aint[nod].first += lazy[nod];
  if (l < r) {
    lazy[2 * nod] += lazy[nod];
    lazy[2 * nod + 1] += lazy[nod];
  }
  lazy[nod] = 0;
}
void update(int i, int j, long long val, int l = 1, int r = 2 * MAX_N,
            int nod = 1) {
  pushLazy(nod, l, r);
  if (r < i || j < l || j < i) return;
  if (i <= l && r <= j) {
    lazy[nod] += val;
    pushLazy(nod, l, r);
  } else {
    int mid = (l + r) / 2;
    update(i, j, val, l, mid, 2 * nod);
    update(i, j, val, mid + 1, r, 2 * nod + 1);
    aint[nod] = max(aint[2 * nod], aint[2 * nod + 1]);
  }
}
pair<long long, int> query(int i, int j, int l = 1, int r = 2 * MAX_N,
                           int nod = 1) {
  pushLazy(nod, l, r);
  if (r < i || j < l || j < i) return {-INF, l};
  if (i <= l && r <= j)
    return aint[nod];
  else {
    int mid = (l + r) / 2;
    return max(query(i, j, l, mid, 2 * nod),
               query(i, j, mid + 1, r, 2 * nod + 1));
  }
}
struct Event {
  int type, poz, anormpoz, pozaux, cost;
} evs[2 * MAX_N];
int* pnt[4 * MAX_N];
bool cmp(int* a, int* b) { return *a < *b; }
int normtable[1 + 2 * MAX_N];
void normalize(int N) {
  for (int i = 0; i < N; ++i) {
    pnt[2 * i] = &evs[i].poz;
    pnt[2 * i + 1] = &evs[i].pozaux;
  }
  sort(pnt, pnt + 2 * N, cmp);
  int last = *pnt[0], j = 1;
  for (int i = 0; i < 2 * N; ++i)
    if (*pnt[i] == last) {
      normtable[j] = last;
      *pnt[i] = j;
    } else {
      last = *pnt[i];
      normtable[++j] = last;
      *pnt[i] = j;
    }
}
bool cmpE(Event a, Event b) { return a.poz < b.poz; }
bool first[1 + MAX_N];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    if (x > y) swap(x, y);
    if (x == y && x <= MAX_N) first[x] = true;
    evs[2 * i] = {0, x, x, y, c};
    evs[2 * i + 1] = {1, y, y, x, c};
  }
  normalize(2 * N);
  sort(evs, evs + 2 * N, cmpE);
  int i, j, lastx = evs[0].poz, anormlastx = evs[0].anormpoz;
  long long rez = 0LL;
  int x, y;
  x = y = 0;
  i = 0;
  init();
  while (i < 2 * N) {
    j = i;
    update(1, lastx, -(evs[i].anormpoz - anormlastx));
    lastx = evs[i].poz;
    anormlastx = evs[i].anormpoz;
    while (j < 2 * N && evs[i].poz == evs[j].poz) {
      if (evs[j].type == 1) update(1, evs[j].pozaux, evs[j].cost);
      ++j;
    }
    pair<long long, int> qaint = query(1, evs[i].poz);
    if (qaint.first > rez) {
      rez = qaint.first;
      x = normtable[qaint.second];
      y = evs[i].anormpoz;
    }
    i = j;
  }
  if (rez == 0) {
    x = 0;
    while (first[x]) ++x;
    y = x;
  }
  printf("%lld\n%d %d %d %d", rez, x, x, y, y);
  return 0;
}
