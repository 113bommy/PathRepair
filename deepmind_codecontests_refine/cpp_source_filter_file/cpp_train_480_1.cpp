#include <bits/stdc++.h>
using namespace std;
int gi() {
  int res = 0, w = 1;
  char ch = getchar();
  while (ch != '-' && !isdigit(ch)) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (isdigit(ch)) res = res * 10 + ch - '0', ch = getchar();
  return res * w;
}
const int MAX_N = 1e5 + 5;
void clear(vector<int> &vec) {
  vector<int> rub;
  vec.swap(rub);
}
vector<int> G[MAX_N];
int N, Q, B, fa[MAX_N], a[MAX_N], op[MAX_N];
int siz[MAX_N], top[MAX_N], son[MAX_N], dep[MAX_N];
int L[MAX_N], R[MAX_N], tim;
void dfs1(int x) {
  dep[x] = dep[fa[x]] + 1, siz[x] = 1;
  for (int v : G[x]) {
    dfs1(v), siz[x] += siz[v];
    if (siz[v] > siz[son[x]]) son[x] = v;
  }
}
void dfs2(int x, int tp) {
  top[x] = tp, L[x] = ++tim;
  if (son[x]) dfs2(son[x], tp);
  for (int v : G[x])
    if (v != son[x]) dfs2(v, v);
  R[x] = tim;
}
int LCA(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return dep[x] < dep[y] ? x : y;
}
int in(int x, int y) { return L[y] <= L[x] && L[x] <= R[y]; }
int pa[MAX_N];
vector<int> arr[MAX_N];
int Pos[MAX_N], ans;
void prepare(int x) {
  arr[x].resize(2 * B + 2);
  int anc = pa[x], bel = x;
  x = fa[x];
  while (x != anc) {
    if (abs(a[x]) <= B && !op[x]) arr[bel][a[x] + B]++;
    x = fa[x];
  }
  for (int i = 1; i <= 2 * B + 1; i++) arr[bel][i] += arr[bel][i - 1];
}
void mdf(int x) {
  int o = op[x], v = o ? 1 : -1;
  op[x] ^= 1;
  if (!o) ans -= a[x] < 0;
  a[x] += v;
  if (o) ans += a[x] < 0;
  while (x) {
    ans -= arr[x][Pos[x]];
    if (!o)
      Pos[x]++;
    else
      Pos[x]--;
    ans += arr[x][Pos[x]], x = pa[x];
    if (x) {
      if (!op[x]) ans -= a[x] < 0;
      a[x] += v;
      if (!op[x]) ans += a[x] < 0;
    }
  }
}
void Query(vector<int> &Q) {
  vector<int> S = Q;
  S.push_back(1);
  sort(S.begin(), S.end(),
       [](const int &i, const int &j) { return L[i] < L[j]; });
  S.erase(unique(S.begin(), S.end()), S.end());
  for (int t = S.size(), i = 0; i < t - 1; i++)
    S.push_back(LCA(S[i], S[i + 1]));
  sort(S.begin(), S.end(),
       [](const int &i, const int &j) { return L[i] < L[j]; });
  S.erase(unique(S.begin(), S.end()), S.end());
  static int stk[MAX_N], top;
  top = 0;
  for (int i : S) {
    while (top && !in(i, stk[top])) --top;
    if (stk[top]) pa[i] = stk[top];
    stk[++top] = i;
  }
  ans = 0;
  for (int i = 1; i <= N; i++)
    if (!op[i] && a[i] < 0) ans++;
  for (int i : S) prepare(i), Pos[i] = B - 1;
  for (int i : Q) mdf(i), printf("%d ", ans);
  for (int i : S) {
    int x = i, val = B - 1 - Pos[i], anc = pa[x];
    x = fa[x];
    while (x != anc) a[x] += val, x = fa[x];
  }
  for (int i : S) clear(arr[i]), Pos[i] = 0;
  Q.clear();
}
int main() {
  N = gi(), Q = gi();
  for (int i = 2; i <= N; i++) fa[i] = gi(), G[fa[i]].push_back(i);
  for (int i = 1; i <= N; i++) a[i] = gi();
  dfs1(1), dfs2(1, 1);
  B = ceil(sqrt(1.0 * Q) / 2.0);
  vector<int> vec;
  while (Q--) {
    int x = abs(gi());
    vec.push_back(x);
    if ((int)vec.size() >= B - 1) Query(vec);
  }
  Query(vec);
  putchar('\n');
  return 0;
}
