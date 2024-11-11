#include <bits/stdc++.h>
using namespace std;
int const N = 300000;
int to[N], V, n, x[N];
vector<int> an[N];
set<int> g[N];
struct S {
  int l, r;
  S() {}
  S(int x) : l(x), r(x) {}
  S operator+(int x) {
    S an;
    an.r = r + x - 2;
    if (l <= x && x <= r)
      an.l = 3 + !(an.r & 1);
    else
      an.l = min(abs(r - x), abs(l - x)) + 2;
    return an;
  }
} sg[N];
void aded(int a, int b) {
  g[a].insert(b);
  g[b].insert(a);
}
int st;
void go(int c, int i = n - 1) {
  an[i].resize(x[i]);
  if (i == 0) {
    for (int j = 0; j < (int)(x[i]); ++j) an[i][j] = j + 1;
    V = x[i];
    for (int j = 0; j < (int)(x[i] - 1); ++j) to[j] = j + 1;
    to[x[i] - 1] = 0;
    return;
  }
  int e = max(1, max(sg[i - 1].l + x[i] - c + 1 >> 1, x[i] - c + 1)),
      b = c - x[i] + 2 * e;
  go(b, i - 1);
  int t = st, o = t;
  for (int j = 0; j < (int)(e); ++j) o = to[o];
  if (to[t] != o && to[o] != t) {
    while (g[t].find(o) != g[t].end()) t = to[t], o = to[o];
    st = t;
  }
  an[i][0] = t + 1;
  for (int j = 0; j < (int)(e); ++j) {
    aded(t, to[t]);
    t = to[t];
    an[i][j + 1] = t + 1;
  }
  for (int j = e + 1; j < (int)(x[i]); ++j) an[i][j] = V + j - e;
  if (e + 1 == x[i])
    to[st] = t, aded(st, t);
  else {
    aded(V, t);
    to[V++] = t;
    for (int i = e + 1; i < (int)(x[i] - 1); ++i)
      aded(V, V - 1), to[V] = V - 1, ++V;
    to[st] = V - 1;
    aded(st, V - 1);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) scanf("%d", x + i);
  sg[0] = x[0];
  for (int i = 1; i < (int)(n); ++i) sg[i] = sg[i - 1] + x[i];
  go(sg[n - 1].l);
  printf("%d\n", V);
  for (int i = 0; i < (int)(n); ++i) {
    printf("%d", an[i][0]);
    for (int j = 1; j < (int)(x[i]); ++j) printf(" %d", an[i][j]);
    printf("\n");
  }
}
