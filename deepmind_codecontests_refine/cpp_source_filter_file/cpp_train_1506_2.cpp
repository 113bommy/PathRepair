#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 18;
const int K = 4;
int M[K] = {1000 * 1000 * 1000 + 7, 1000 * 1000 * 1000 + 9,
            1000 * 1000 * 1000 + 33, 641230789};
int p2[N][K], n2, n;
struct drzewo {
  drzewo *l, *pr;
  long long int hasz[K];
  bool co;
  drzewo() {
    l = NULL;
    pr = NULL;
    co = 0;
    for (int i = 0; i < K; i++) hasz[i] = 0;
  }
  drzewo* lew() {
    if (l == NULL) l = new drzewo();
    return l;
  }
  drzewo* pra() {
    if (pr == NULL) pr = new drzewo();
    return pr;
  }
  void popraw(int x) {
    for (int i = 0; i < K; i++) {
      hasz[i] = (pra()->hasz[i] * p2[x][i] + lew()->hasz[i]) % M[i];
    }
  }
  void policz() {
    for (int i = 0; i < K; i++) hasz[i] = co;
  }
};
int mniej(drzewo* w, drzewo* v, int p, int k) {
  if (p == k) {
    if (w->co == v->co) return 0;
    if (w->co < v->co) return -1;
    return 1;
  }
  bool OK = 1;
  for (int i = 0; i < K; i++)
    if (w->pra()->hasz[i] != v->pra()->hasz[i]) OK = 0;
  if (OK == 0) return mniej(w->pra(), v->pra(), (p + k) / 2 + 1, k);
  return mniej(w->lew(), v->lew(), p, (p + k) / 2);
}
struct cmp {
  bool operator()(pair<drzewo*, int> a, pair<drzewo*, int> b) {
    if (a.first == NULL && b.first == NULL) return a.second < b.second;
    if (a.first == NULL) return 0;
    if (b.first == NULL) return 1;
    int ret = mniej(a.first, b.first, 0, n2 - 1);
    if (ret == 0) return a.second < b.second;
    if (ret == -1) return 1;
    return 0;
  }
};
bool dalej;
drzewo* dodaj(drzewo* w, int x, int p, int k) {
  drzewo* tem;
  tem = new drzewo();
  if (p == k) {
    if (w->co == 0) {
      tem->co = 1;
      tem->policz();
      dalej = 0;
    }
    return tem;
  }
  if (x <= (p + k) / 2) {
    tem->pr = w->pra();
    tem->l = dodaj(w->lew(), x, p, (p + k) / 2);
  } else {
    tem->l = w->lew();
    tem->pr = dodaj(w->pra(), x, (p + k) / 2 + 1, k);
  }
  tem->popraw((k - p + 1) / 2);
  return tem;
}
set<pair<drzewo*, int>, cmp> kol;
drzewo* d[N];
drzewo* kopia;
int pop[N], t;
bool vis[N];
vector<pair<int, int> > G[N];
void Dijkstra() {
  int z, a;
  scanf("%d%d", &z, &t);
  d[z] = new drzewo();
  kol.insert(make_pair(d[z], z));
  while (!kol.empty()) {
    a = kol.begin()->second;
    vis[a] = 1;
    if (a == t) return;
    kol.erase(kol.begin());
    for (int i = 0; i < G[a].size(); i++) {
      dalej = 1;
      int x = G[a][i].second;
      kopia = d[a];
      while (dalej) {
        kopia = dodaj(kopia, x, 0, n2 - 1);
        x++;
      }
      if ((d[G[a][i].first] == NULL) ||
          mniej(kopia, d[G[a][i].first], 0, n2 - 1) == -1) {
        kol.erase(make_pair(d[G[a][i].first], G[a][i].first));
        d[G[a][i].first] = kopia;
        kol.insert(make_pair(kopia, G[a][i].first));
        pop[G[a][i].first] = a;
      }
    }
  }
}
int main() {
  int m, a, b, c;
  scanf("%d%d", &n, &m);
  n2 = 1 << 18;
  for (int i = 0; i < K; i++) p2[0][i] = 1;
  for (int i = 1; i < n2; i++) {
    for (int x = 0; x < K; x++) p2[i][x] = (p2[i - 1][x] * 2) % M[x];
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    G[a].push_back(make_pair(b, c));
    G[b].push_back(make_pair(a, c));
  }
  Dijkstra();
  if (vis[t] == 0) {
    printf("-1\n");
    return 0;
  }
  printf("%lld\n", d[t]->hasz[1]);
  vector<int> roz;
  do {
    roz.push_back(t);
    t = pop[t];
  } while (t);
  printf("%d\n", roz.size());
  for (int i = roz.size() - 1; i >= 0; i--) printf("%d ", roz[i]);
}
