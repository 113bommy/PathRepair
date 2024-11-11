#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int x;
  int y;
  long long z;
  long long o;
} H;
long long b, g, i, j, k, sz, t, p[200040], w[200040];
int pv[200040];
H e[400005];
int C(H a, H b) { return a.x < b.x; }
void BP(void);
void S(void);
long long dfs(int v);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for (cin >> t; t--;) {
    S();
    BP();
    k++;
    for (i = 0; i++ < k;) {
      if (w[i] < 2 && !p[e[pv[i]].y]) {
        dfs(pv[i]);
        p[e[pv[i]].y] = 1;
      }
    }
    for (b = g = i = 0; i < sz; i++) {
      if (!e[i].o) {
        if (w[e[i].y] < 2)
          e[i].o = 1;
        else
          e[i].o = k - 1;
      }
      if (e[i].o * 2 < k || e[i].o * 2 == k && e[i].x < e[i].y) {
        g += e[i].o % 2 * e[i].z;
        b += e[i].o * e[i].z;
      }
    }
    cout << g << ' ' << b << '\n';
    for (i = 0; i++ < k + 1;) p[i] = pv[i] = w[i] = 0;
    for (i = 0; i < sz + 1; i++) e[i].o = 0;
  }
}
void BP(void) {
  for (int i = 0; ++i < sz;) {
    if (e[i].x > e[i - 1].x) {
      for (int j = e[i - 1].x; j++ < e[i].x;) {
        pv[j] = i;
      }
    }
  }
  for (int j = e[sz - 1].x; j++ < k + 2;) pv[j] = sz;
}
void S(void) {
  cin >> k;
  k = 2 * k - 1;
  for (int i = 0; i < k; i++) {
    cin >> e[i].x >> e[i].y >> e[i].z;
    e[i + k].x = e[i].y;
    e[i + k].y = e[i].x;
    e[i + k].z = e[i].z;
    w[e[i].x]++;
    w[e[i].y]++;
  }
  sz = 2 * k;
  sort(e, e + sz, C);
}
long long dfs(int v) {
  long long s = 0;
  if (e[v].o) return e[v].o;
  for (int i = pv[e[v].y]; i < pv[e[v].y + 1]; i++) {
    if (e[i].y != e[v].x) s += dfs(i);
  }
  return e[v].o = s + 1;
}
