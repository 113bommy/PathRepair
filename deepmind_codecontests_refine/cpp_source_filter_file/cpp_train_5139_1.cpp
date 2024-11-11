#include <bits/stdc++.h>
using namespace std;
typedef struct Comp {
  vector<int> leafs;
  int center;
} X;
void run() {
  int n;
  scanf("%d", &n);
  vector<int> x(n);
  for (int i = (0); i < (n); ++i) {
    scanf("%d", &x[i]);
    --x[i];
  }
  vector<Comp> comps;
  vector<int> incomp(n, -1);
  for (int i = (0); i < (n); ++i)
    if (incomp[i] == -1) {
      int at = i;
      while (incomp[at] == -1) {
        incomp[at] = -2;
        at = x[at];
      }
      int nr;
      if (incomp[at] == -2) {
        Comp cur;
        cur.leafs.clear();
        cur.center = at;
        comps.push_back(cur);
        nr = ((int)(comps).size()) - 1;
      } else {
        nr = incomp[at];
      }
      at = i;
      while (incomp[at] == -2) {
        incomp[at] = nr;
        at = x[at];
      }
    }
  vector<int> indeg(n, 0);
  for (int i = (0); i < (n); ++i) indeg[x[i]]++;
  for (int i = (0); i < (n); ++i)
    if (indeg[i] == 0) comps[incomp[i]].leafs.push_back(i);
  vector<Comp> with, without;
  for (int i = (0); i < (((int)(comps).size())); ++i)
    if (((int)(comps[i].leafs).size()) == 0)
      without.push_back(comps[i]);
    else
      with.push_back(comps[i]);
  if (((int)(with).size()) == 0 && ((int)(without).size()) == 1) {
    printf("0\n");
    return;
  }
  vector<pair<int, int> > res;
  if (((int)(with).size()) == 0 && ((int)(without).size()) >= 2) {
    Comp a = without.back();
    without.pop_back();
    Comp b = without.back();
    without.pop_back();
    res.push_back(make_pair(a.center, b.center));
    b.leafs.push_back(a.center);
    with.push_back(b);
  }
  while (((int)(without).size()) > 0) {
    Comp a = without.back();
    without.pop_back();
    Comp &b = with[0];
    res.push_back(make_pair(a.center, b.leafs.back()));
    b.leafs.pop_back();
    b.leafs.push_back(a.center);
  }
  while (((int)(with).size()) > 2) {
    Comp a = with.back();
    with.pop_back();
    Comp &b = with[0];
    res.push_back(make_pair(a.center, b.leafs.back()));
    b.leafs.pop_back();
    for (int i = (0); i < (((int)(a.leafs).size())); ++i)
      b.leafs.push_back(a.leafs[i]);
  }
  while (((int)(with[0].leafs).size()) > 0) {
    Comp &b = with[0];
    res.push_back(make_pair(b.center, b.leafs.back()));
    b.leafs.pop_back();
  }
  printf("%d\n", ((int)(res).size()));
  for (int i = (0); i < (((int)(res).size())); ++i)
    printf("%d %d\n", res[i].first + 1, res[i].second + 1);
}
int main() {
  run();
  return 0;
}
