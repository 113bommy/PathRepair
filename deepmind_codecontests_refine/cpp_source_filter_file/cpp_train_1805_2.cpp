#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60000000")
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
template <class T>
T sqr(T x) {
  return x * x;
}
struct rec {
  int v, w, c, f, NEXTHUI, num;
};
int n, k, S, T;
int s[1000], t[1000], c[1000], lst;
vector<int> A;
map<int, int> MA;
int ver[10000], p[10000], d[10000], pr[10000];
rec reb[100000];
void _push(int v1, int v2, int c, int w, int num) {
  lst++;
  reb[lst].v = v2;
  reb[lst].c = c;
  reb[lst].w = w;
  reb[lst].f = 0;
  reb[lst].NEXTHUI = ver[v1];
  reb[lst].num = num;
  ver[v1] = lst;
}
void push(int v1, int v2, int c, int w, int num) {
  _push(v1, v2, c, w, num);
  _push(v2, v1, -c, 0, -1);
}
int main() {
  cin >> n >> k;
  memset(ver, 255, sizeof(ver));
  lst = -1;
  for (int i = 0; i < (int)(n); i++) cin >> s[i] >> t[i] >> c[i];
  for (int i = 0; i < (int)(n); i++) {
    t[i] += s[i];
    A.push_back(s[i]);
    A.push_back(t[i]);
  }
  sort(A.begin(), A.end());
  A.resize(unique(A.begin(), A.end()) - A.begin());
  for (int i = 0; i < (int)(A.size()); i++) MA[A[i]] = i;
  for (int i = 0; i < (int)(n); i++) {
    s[i] = MA[s[i]];
    t[i] = MA[t[i]];
  }
  lst = -1;
  S = 0;
  T = A.size() - 1;
  int N = T + 1;
  for (int i = S; i < T; i++) push(i, i + 1, k, 0, -1);
  for (int i = 0; i < (int)(n); i++) push(s[i], t[i], 1, c[i], i);
  for (int it = 0; it < (int)(k); it++) {
    for (int i = 0; i < (int)(N); i++) d[i] = -inf;
    d[0] = 0;
    memset(p, 255, sizeof(p));
    for (int jt = 0; jt < (int)(N); jt++)
      for (int v = 0; v < (int)(N); v++)
        for (int ptr = ver[v]; ptr != -1; ptr = reb[ptr].NEXTHUI)
          if (reb[ptr].c > reb[ptr].f)
            if (d[reb[ptr].v] < d[v] + reb[ptr].w) {
              d[reb[ptr].v] = d[v] + reb[ptr].w;
              p[reb[ptr].v] = v;
              pr[reb[ptr].v] = ptr;
            }
    int v = T;
    while (v > 0) {
      int ptr = pr[v];
      reb[ptr].f++;
      reb[ptr ^ 1].f--;
      v = p[v];
    }
  }
  memset(c, 0, sizeof(c));
  for (int i = 0; i <= lst; i++)
    if (reb[i].f == reb[i].c && reb[i].num >= 0) c[reb[i].num] = 1;
  for (int i = 0; i < (int)(n); i++) {
    printf("%d", c[i]);
    if (i + 1 < n)
      printf(" ");
    else
      puts("");
  }
  return 0;
}
