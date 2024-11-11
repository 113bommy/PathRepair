#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxN = 1 << 19;
template <class T1, class T2>
inline void remin(T1& a, T2 b) {
  a = min(a, (T1)b);
}
template <class T1, class T2>
inline void remax(T1& a, T2 b) {
  a = max(a, (T1)b);
}
int a[maxN];
long long suf[maxN];
vector<int> ans[maxN];
list<int> C;
set<pair<int, int> > E;
bool check(list<int>::iterator it, int e) {
  int u = *it;
  while (e--) it++;
  int v = *it;
  if (u > v) swap(u, v);
  return E.find(make_pair(u, v)) != E.end();
}
bool cmp(int i, int j) { return a[i] > a[j]; }
void add(int i, int j) { E.insert({min(i, j), max(i, j)}); }
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = (0); i < (int)(n); i++) scanf("%d", a + i);
  vector<int> ord(n);
  iota((ord).begin(), (ord).end(), 0);
  sort((ord).begin(), (ord).end(), cmp);
  long long S = 0;
  for (auto it = ord.rbegin(); it != ord.rend(); it++) {
    int i = *it;
    suf[i] = S;
    S += a[i] - 2;
  }
  int m = 0, j = ord[0];
  for (int _ = (0); _ < (int)(a[j]); _++) C.push_back(++m), ans[j].push_back(m);
  for (int i = (1); i < (int)(m); i++) add(i, i + 1);
  add(1, m);
  for (int i : ord)
    if (i != j) {
      long long glue = (C.size() + a[i] - 2 - suf[i]) / 2;
      remax(glue, 1);
      remin(glue, a[i] - 1);
      remin(glue, C.size() - 2);
      auto it = C.begin();
      if (glue == a[i] - 1 and check(it, glue)) it++;
      ans[i].push_back(*it++);
      for (int _ = (0); _ < (int)(glue - 1); _++)
        ans[i].push_back(*it), it = C.erase(it);
      int prv = *it;
      ans[i].push_back(prv);
      for (int _ = (0); _ < (int)(a[i] - glue - 1); _++) {
        ans[i].push_back(++m);
        it = C.insert(it, m);
        add(m, prv);
        prv = m;
      }
      add(*prev(it), prv);
    }
  printf("%d\n", m);
  for (int i = (0); i < (int)(n); i++) {
    for (int j : ans[i]) printf("%d ", j);
    printf("\n");
  }
}
int main() {
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
