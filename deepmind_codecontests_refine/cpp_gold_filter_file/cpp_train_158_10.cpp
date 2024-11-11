#include <bits/stdc++.h>
using namespace std;
struct E {
  int v, id;
  long long c;
};
vector<E> G[1000];
long long d2s[1000], d2t[1000];
bool mark[1000];
const long long INF = (long long)1e15;
int u[10000], v[10000];
long long c[10000];
int main() {
  int n, m, l, s, t;
  scanf("%d%d%d%d%d", &n, &m, &l, &s, &t);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%lld", u + i, v + i, c + i);
    G[u[i]].push_back(E{v[i], i, c[i]});
    G[v[i]].push_back(E{u[i], i, c[i]});
  }
  fill(d2t, d2t + n, INF);
  memset(mark, 0, sizeof(mark));
  d2t[t] = 0;
  for (int i = 0; i < n; i++) {
    int Minj = -1;
    long long Min = INF;
    for (int j = 0; j < n; j++) {
      if (!mark[j] && d2t[j] < Min) {
        Minj = j;
        Min = d2t[j];
      }
    }
    if (Minj < 0) break;
    mark[Minj] = 1;
    for (E &e : G[Minj]) {
      if (e.c == 0) continue;
      if (d2t[e.v] > Min + e.c) d2t[e.v] = Min + e.c;
    }
  }
  fill(d2s, d2s + n, INF);
  memset(mark, 0, sizeof(mark));
  d2s[s] = 0;
  for (int i = 0; i < n; i++) {
    int Minj = -1;
    long long Min = INF;
    for (int j = 0; j < n; j++) {
      if (!mark[j] && d2s[j] < Min) {
        Minj = j;
        Min = d2s[j];
      }
    }
    if (Minj < 0) break;
    mark[Minj] = 1;
    for (E &e : G[Minj]) {
      if (e.c == 0) {
        if (c[e.id] != 0)
          e.c = c[e.id];
        else if (d2t[e.v] == INF) {
          e.c = 1;
          c[e.id] = e.c;
        } else {
          e.c = l - d2t[e.v] - Min;
          if (e.c <= 0) {
            e.c = 1;
          }
          c[e.id] = e.c;
        }
      }
      if (d2s[e.v] > Min + e.c) d2s[e.v] = Min + e.c;
    }
  }
  if (d2s[t] != l) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 0; i < m; i++) {
    if (c[i] == 0) c[i] = 1;
    printf("%d %d %lld\n", u[i], v[i], c[i]);
  }
  return 0;
}
