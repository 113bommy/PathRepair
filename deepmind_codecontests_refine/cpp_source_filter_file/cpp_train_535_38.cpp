#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long inf = mod * mod;
const long long d2 = (mod + 1) / 2;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);
int ABS(int a) { return max(a, -a); }
long long ABS(long long a) { return max(a, -a); }
long double ABS(long double a) { return max(a, -a); }
namespace MCF {
const int wEPS = 0;
const int wINF = 1001001001;
const long long cEPS = 0;
const long long cINF = 100100100100100100LL;
int n, m, ptr[15400], next[3100000], zu[3100000];
int capa[3100000], tof;
long long cost[3100000], toc, d[15400], pot[15400];
int vis[15400], pree[15400];
void init(int _n) {
  n = _n;
  m = 0;
  memset(ptr, ~0, n * 4);
}
void ae(int u, int v, int w, long long c) {
  next[m] = ptr[u];
  ptr[u] = m;
  zu[m] = v;
  capa[m] = w;
  cost[m] = +c;
  ++m;
  next[m] = ptr[v];
  ptr[v] = m;
  zu[m] = u;
  capa[m] = 0;
  cost[m] = -c;
  ++m;
}
bool solve(int src, int ink, int flo = wINF) {
  int i, u, v;
  int f;
  long long c, cc;
  memset(pot, 0, n * sizeof(long long));
  for (bool cont = 1; cont;) {
    cont = 0;
    for (u = 0; u < n; ++u)
      for (i = ptr[u]; ~i; i = next[i])
        if (capa[i] > wEPS) {
          if (pot[zu[i]] > pot[u] + cost[i] + cEPS) {
            pot[zu[i]] = pot[u] + cost[i];
            cont = 1;
          }
        }
  }
  for (toc = 0, tof = 0; tof + wEPS < flo;) {
    priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                   greater<pair<long long, int> > >
        q;
    for (u = 0; u < n; ++u) {
      d[u] = cINF;
      vis[u] = 0;
    }
    for (q.push(make_pair(d[src] = 0, src)); !q.empty();) {
      c = q.top().first;
      u = q.top().second;
      q.pop();
      if (vis[u]++) continue;
      for (i = ptr[u]; ~i; i = next[i])
        if (capa[i] > wEPS) {
          cc = c + cost[i] + pot[u] - pot[v = zu[i]];
          if (d[v] > cc + cEPS) {
            q.push(make_pair(d[v] = cc, v));
            pree[v] = i;
          }
        }
    }
    if (!vis[ink]) return 0;
    f = flo - tof;
    for (v = ink; v != src; v = zu[i ^ 1]) {
      i = pree[v];
      f = min(f, capa[i]);
    }
    for (v = ink; v != src; v = zu[i ^ 1]) {
      i = pree[v];
      capa[i] -= f;
      capa[i ^ 1] += f;
    }
    tof += f;
    toc += f * (d[ink] - pot[src] + pot[ink]);
    for (u = 0; u < n; ++u) pot[u] += d[u];
  }
  return 1;
}
}  // namespace MCF
int big[60];
int x[60];
int y[60];
int main() {
  int a, b, c, d, e;
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
  for (int i = 0; i < c; i++) {
    int p;
    scanf("%d", &p);
    p--;
    big[p]++;
  }
  for (int i = 0; i < b; i++) {
    scanf("%d%d", x + i, y + i);
    x[i]--;
    y[i]--;
  }
  MCF::init(a * 103 + 2);
  int S = a * 103;
  int T = a * 103 + 1;
  for (int i = 0; i < 103; i++) {
    MCF::ae(i * a, T, 50, i * d);
    if (i < 102) {
      for (int j = 0; j < b; j++) {
        for (int k = 0; k < a; k++) {
          MCF::ae(i * a + x[j], i * a + y[j] + a, 1, e * (k * 2 + 1));
          MCF::ae(i * a + y[j], i * a + x[j] + a, 1, e * (k * 2 + 1));
        }
      }
      for (int j = 0; j < a; j++) {
        MCF::ae(i * a + j, i * a + j + a, 50, 0);
      }
    }
  }
  for (int i = 0; i < a; i++) {
    MCF::ae(S, i, big[i], 0);
  }
  MCF::solve(S, T, c);
  printf("%lld\n", MCF::toc);
}
