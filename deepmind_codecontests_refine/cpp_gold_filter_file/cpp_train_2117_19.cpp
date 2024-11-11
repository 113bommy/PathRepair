#include <bits/stdc++.h>
using namespace std;
struct event {
  int tip, idx, pos;
  event(int _tip = 0, int _idx = 0, int _pos = 0) {
    tip = _tip;
    idx = _idx;
    pos = _pos;
  }
};
struct itrvl {
  int a, b, t;
};
bool cmpf(event A, event B) {
  if (A.pos != B.pos) return A.pos < B.pos;
  if (A.tip != B.tip) return A.tip < B.tip;
  return A.idx < B.idx;
}
map<int, int> Mapa;
int off, from, to, N, M, ans[100005], T;
set<int> a[2000005];
vector<event> E;
itrvl I[100005], P[100005];
vector<int> vec;
void init(int n) {
  for (off = 1; off <= n; off *= 2)
    ;
}
void insert(int i, int val) {
  i += off;
  a[i].insert(val);
  for (i >>= 1; i > 0; i >>= 1) a[i].insert(val);
}
void erase(int i, int val) {
  i += off;
  a[i].erase(val);
  for (i >>= 1; i > 0; i >>= 1) a[i].erase(val);
}
int calc(int i, int lo, int hi) {
  if (lo >= to || from >= hi || a[i].size() == 0) return 2000000000;
  if (lo >= from && hi <= to) {
    set<int>::iterator it = a[i].lower_bound(T);
    if (it == a[i].end()) return 2000000000;
    return *it;
  }
  return min(calc(2 * i, lo, (lo + hi) >> 1),
             calc(2 * i + 1, (lo + hi) >> 1, hi));
}
int calc(int lo, int hi) {
  from = lo;
  to = hi + 1;
  return calc(1, 0, off);
}
int main(void) {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; ++i) {
    scanf("%d %d %d", &I[i].a, &I[i].b, &I[i].t);
    vec.push_back(I[i].a);
    vec.push_back(I[i].b);
  }
  for (int i = 0; i < M; ++i) {
    scanf("%d %d %d", &P[i].a, &P[i].b, &P[i].t);
    vec.push_back(P[i].a);
    vec.push_back(P[i].b);
  }
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  for (int i = 0; i < N; ++i) {
    I[i].a = lower_bound(vec.begin(), vec.end(), I[i].a) - vec.begin();
    I[i].b = lower_bound(vec.begin(), vec.end(), I[i].b) - vec.begin();
    E.push_back(event(0, i, I[i].a));
    E.push_back(event(1, i, I[i].b + 1));
    Mapa[I[i].t] = i + 1;
  }
  for (int i = 0; i < M; ++i) {
    P[i].a = lower_bound(vec.begin(), vec.end(), P[i].a) - vec.begin();
    P[i].b = lower_bound(vec.begin(), vec.end(), P[i].b) - vec.begin();
    E.push_back(event(2, i, P[i].a));
  }
  init(1000000);
  sort(E.begin(), E.end(), cmpf);
  for (int i = 0; i < E.size(); ++i)
    if (E[i].tip == 0) {
      insert(I[E[i].idx].b, I[E[i].idx].t);
    } else if (E[i].tip == 1) {
      erase(I[E[i].idx].b, I[E[i].idx].t);
    } else {
      T = P[E[i].idx].t;
      ans[E[i].idx] = calc(P[E[i].idx].b, 700000);
    }
  for (int i = 0; i < M; ++i)
    printf("%d ", ans[i] == 2000000000 ? -1 : Mapa[ans[i]]);
  printf("\n");
  return 0;
}
