#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
vector<int> g[400005], o;
int N, A[400005], B[400005], C[400005], I, a, b, S[400005], E[400005], J,
    P[400005];
void del(int a, int b) {
  for (int i(0); i < (int)g[a].size(); i++)
    if (g[a][i] == b) g[a][i] = g[a].back(), g[a].pop_back();
  for (int i(0); i < (int)g[b].size(); i++)
    if (g[b][i] == a) g[b][i] = g[b].back(), g[b].pop_back();
}
int ctr(int u, int p) {
  S[u] = 1;
  int x = 1;
  for (auto &h : g[u])
    if (h ^ p) S[u] += a = ctr(h, u), x &= a * 2 < N;
  x &= S[u] * 2 >= N;
  if (x) o.push_back(u);
  return S[u];
}
void dfs(int u, int p) {
  for (auto &h : g[u])
    if (h ^ p) dfs(h, u);
  P[E[J++] = u] = p;
}
void dc(int u) {
  for (auto &h : g[u]) {
    J = 1, dfs(h, u), P[u] = h, *E = u;
    A[I] = u, B[I] = h, C[I++] = E[1];
    for (int k(1); k < J - 1; k++)
      A[I] = E[k], B[I] = P[E[k]], C[I++] = E[k + 1];
    for (int i = J - 4; i >= 0; --i)
      A[I] = E[i], B[I] = E[i + 1], C[I++] = E[J - 2];
  }
}
int main(void) {
  scanf("%d", &N);
  for (int i(0); i < N - 1; i++)
    scanf("%d%d", &a, &b), g[--a].push_back(--b), g[b].push_back(a);
  ctr(0, 0), assert(o.size() > 0u && o.size() < 3u);
  if (o.size() == 2u) del(o[0], o[1]), dc(o[1]);
  dc(o[0]);
  printf("%d\n", I);
  for (int i(0); i < I; i++) printf("%d %d %d\n", A[i] + 1, B[i] + 1, C[i] + 1);
  return 0;
}
