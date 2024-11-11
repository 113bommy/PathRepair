#include <bits/stdc++.h>
using namespace std;
int N, Q;
vector<int> E[200005];
int P[21][200005], D[200005];
void dfs(int cur) {
  for (__typeof(E[cur].begin()) it = E[cur].begin(); it != E[cur].end(); it++)
    if (*it != P[0][cur]) D[*it] = D[cur] + 1, P[0][*it] = cur, dfs(*it);
}
int lca(int a, int b) {
  int ret = 0, i, aa = a, bb = b;
  if (D[aa] > D[bb]) swap(aa, bb);
  for (i = 19; i >= 0; i--)
    if (D[bb] - D[aa] >= 1 << i) bb = P[i][bb];
  for (i = 19; i >= 0; i--)
    if (P[i][aa] != P[i][bb]) aa = P[i][aa], bb = P[i][bb];
  return (aa == bb) ? aa : P[0][aa];
}
int dist(int a, int b) { return D[a] + D[b] - 2 * D[lca(a, b)]; }
int hoge(int S, int T, int F) {
  int ST = lca(S, T);
  int FT = lca(F, T);
  int SF = lca(S, F);
  int STD = dist(S, T);
  int FTD = dist(F, T);
  int SFD = dist(S, F);
  if (SFD + STD == FTD) return STD + 1;
  if (SFD + FTD == STD) return FTD + 1;
  if (D[ST] > D[SF]) {
    return D[T] - D[ST] + 1;
  } else if (D[FT] > D[SF]) {
    return D[T] - D[SF] + 1;
  } else {
    return dist(SF, T) + 1;
  }
}
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> Q;
  for (i = 0; i < (N - 1); i++) {
    cin >> x;
    E[i + 1].push_back(x - 1);
    E[x - 1].push_back(i + 1);
  }
  dfs(0);
  for (i = 0; i < (19); i++)
    for (x = 0; x < (N); x++) P[i + 1][x] = P[i][P[i][x]];
  while (Q--) {
    int A, B, C;
    cin >> A >> B >> C;
    A--, B--, C--;
    cout << max({hoge(A, B, C), hoge(A, C, B), hoge(B, A, C)}) << endl;
  }
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}
