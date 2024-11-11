#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 100;
const int MM = 1e6 + 100;
int N, M;
int hp[MM];
int H, K;
struct G {
  int k, v;
  bool c;
  int a, b;
  G(int k = 0, int v = 0) : k(k), v(v) {
    c = 0;
    a = b = -1;
  }
};
G g[MM * 3];
int X = 0;
using si = stack<int>;
int create(int k, int v) {
  g[X] = G(k, v);
  return X++;
};
using vi = vector<int>;
int id[MM * 3], IDN;
int fv[MM];
vi fm[MM];
void workg(int i, int n, int c) {
  if (g[n].c)
    workg(i, g[n].a, c), workg(i, g[n].b, c);
  else {
    if (!id[n]) fv[id[n] = ++IDN] = g[n].v;
    for (int k = 0; k < c; k++) fm[id[n]].push_back(i);
  }
}
struct S {
  int g, c;
  S(int g = 0, int c = 0) : g(g), c(c) {}
  void work(int i) {
    if (!c) return;
    workg(i, g, c);
  }
};
using vs = vector<S>;
vs f[MM];
si s;
int main(void) {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) scanf("%d", hp + i), H += hp[i];
  K = (H + N - 1) / N;
  hp[M - 1] += K * N - H;
  s.push(create(K, N));
  for (int i = 0, n; i < M - 1; i++) {
    n = s.top();
    for (; g[n].k * g[n].v < hp[i]; s.pop(), n = s.top())
      hp[i] -= g[n].k * g[n].v, f[i].push_back({n, g[n].k});
    if (hp[i] % g[n].v != 0) {
      int d = hp[i] % g[n].v;
      int c = hp[i] / g[n].v;
      g[n].k -= c;
      g[n].c = 1;
      s.pop();
      s.push(g[n].a = create(g[n].k, g[n].v - d));
      int z;
      s.push(z = g[n].b = create(g[n].k - 1, d));
      f[i].push_back({n, c});
      f[i].push_back({z, 1});
      hp[i] -= g[n].v * c + d;
    } else {
      int c = hp[i] / g[n].v;
      hp[i] -= c * g[n].v;
      if (!(g[n].k -= c)) s.pop();
      f[i].push_back({n, c});
    }
  }
  for (int n; !s.empty(); s.pop()) f[M - 1].push_back({n = s.top(), g[n].k});
  for (int i = 0; i < M; i++)
    for (S& x : f[i]) x.work(i + 1);
  printf("%d\n", K);
  for (int i = 1; i <= M; i++) printf("%d ", i <= IDN ? fv[i] : 0);
  printf("\n");
  for (int i = 0; i < K; i++) {
    for (int j = 1; j <= M; j++) printf("%d ", j <= IDN ? fm[j][i] : 1);
    printf("\n");
  }
  return 0;
}
