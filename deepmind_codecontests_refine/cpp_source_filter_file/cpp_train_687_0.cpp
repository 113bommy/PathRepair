#include <bits/stdc++.h>
using namespace std;
const int MX = 100005;
const int SQRT = 350;
int n;
int par[MX];
struct S {
  int cnt[MX];
  int dsu_par[MX];
  int off;
  int maxVal;
} comp[SQRT];
int dsu_find(int v, S& s) {
  if (v == s.dsu_par[v]) return v;
  return s.dsu_par[v] = dsu_find(s.dsu_par[v], s);
}
void dsu_merge(int u, int v, S& s) {
  u = dsu_find(u, s);
  v = dsu_find(v, s);
  s.dsu_par[u] = v;
  s.cnt[v] += s.cnt[u];
}
void updSingle(int i, int x, S& s) {
  int y = dsu_find(par[i], s);
  s.cnt[y]--;
  int val = y - s.off;
  if (val > x) val -= x;
  int z = val + s.off;
  par[i] = z;
  s.cnt[z]++;
}
void updComp(int x, S& s) {
  if (2 * x <= s.maxVal) {
    for (int i = 1; i <= x; i++) {
      dsu_merge(s.off + i, s.off + i + x, s);
    }
    s.off += x;
    s.maxVal -= x;
  } else if (x <= s.maxVal) {
    for (int i = x + 1; i <= s.maxVal; i++) {
      dsu_merge(s.off + i, s.off + i - x, s);
    }
    s.maxVal = x;
  }
}
int main() {
  int m;
  ignore = scanf("%d %d", &n, &m);
  for (int i = 0; i <= (n - 1) / SQRT; i++) {
    for (int j = 1; j < MX; j++) {
      comp[i].dsu_par[j] = j;
    }
  }
  for (int i = 0; i < n; i++) {
    int c = i / SQRT;
    int x;
    ignore = scanf("%d", &x);
    comp[c].cnt[x]++;
    comp[c].maxVal = max(comp[c].maxVal, x);
    par[i] = x;
  }
  while (m--) {
    int t, l, r, x;
    ignore = scanf("%d %d %d %d", &t, &l, &r, &x);
    l--, r--;
    if (t == 1) {
      int cl = l / SQRT;
      int cr = r / SQRT;
      if (cl == cr) {
        for (int i = l; i <= r; i++) {
          updSingle(i, x, comp[cl]);
        }
      } else {
        for (int i = l, e = (cl + 1) * SQRT - 1; i <= e; i++) {
          updSingle(i, x, comp[cl]);
        }
        for (int i = cl + 1; i <= cr - 1; i++) {
          updComp(x, comp[i]);
        }
        for (int i = cr * SQRT; i <= r; i++) {
          updSingle(i, x, comp[cr]);
        }
      }
    } else {
      int ans = 0;
      int cl = l / SQRT;
      int cr = r / SQRT;
      if (cl == cr) {
        for (int i = l; i <= r; i++) {
          if (dsu_find(par[i], comp[cl]) == x - comp[cl].off) {
            ans++;
          }
        }
      } else {
        for (int i = l, e = (cl + 1) * SQRT - 1; i <= e; i++) {
          if (dsu_find(par[i], comp[cl]) == x + comp[cl].off) {
            ans++;
          }
        }
        for (int i = cl + 1; i <= cr - 1; i++) {
          if (x <= comp[i].maxVal) {
            ans += comp[i].cnt[x + comp[i].off];
          }
        }
        for (int i = cr * SQRT; i <= r; i++) {
          if (dsu_find(par[i], comp[cr]) == x + comp[cr].off) {
            ans++;
          }
        }
      }
      printf("%d\n", ans);
    }
  }
}
