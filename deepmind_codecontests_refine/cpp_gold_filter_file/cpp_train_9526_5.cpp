#include <bits/stdc++.h>
using namespace std;
int IN() {
  int c, f, x;
  while (!isdigit(c = getchar()) && c != '-')
    ;
  c == '-' ? (f = 1, x = 0) : (f = 0, x = c - '0');
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + c - '0';
  return !f ? x : -x;
}
const int N = 1e5 + 19;
const int S = 315;
struct Edge {
  int y, nxt;
} E[N];
long long Ans[N];
int t[N][26], pt[N], Fail[N], las[N], I[N], O[N];
char s[N];
string str[N];
int num, n, m, l, r, k, x, cnt, dfn;
void Add_Edge(int x, int y) {
  E[cnt] = (Edge){y, las[x]};
  las[x] = cnt++;
}
void dfs(int x, int fa) {
  I[x] = ++dfn;
  for (int i = las[x], y; ~i; i = E[i].nxt)
    if ((y = E[i].y) != fa) {
      dfs(y, x);
    }
  O[x] = dfn;
}
void Build() {
  static int Q[N];
  int f = 1, w = 0;
  Q[1] = 0;
  while (f > w) {
    int x = Q[++w];
    if (x) Add_Edge(Fail[x], x);
    for (int i = 0; i < 26; i++) {
      int &u = t[x][i];
      if (u) {
        Q[++f] = u;
        if (x) Fail[u] = t[Fail[x]][i];
      } else
        u = t[Fail[x]][i];
    }
  }
}
namespace Big {
struct QType {
  int l, r, id;
};
vector<QType> V[N];
long long val[N], sum[N];
void Ins(int l, int r, int k, int i) { V[k].push_back((QType){l, r, i}); }
void Main() {
  for (int i = 1; i < n + 1; i++)
    if (V[i].size()) {
      memset(val, 0, sizeof(val));
      x = 0;
      for (int j = 0; j < str[i].length(); j++) {
        x = t[x][str[i][j] - 'a'];
        val[I[x]]++;
      }
      for (int j = 1; j < dfn + 1; j++) val[j] += val[j - 1];
      for (int j = 1; j < n + 1; j++)
        sum[j] = val[O[pt[j]]] - val[I[pt[j]] - 1];
      for (int j = 1; j < n + 1; j++) sum[j] += sum[j - 1];
      for (int j = 0; j < V[i].size(); j++) {
        Ans[V[i][j].id] = sum[V[i][j].r] - sum[V[i][j].l - 1];
      }
    }
}
}  // namespace Big
namespace Sml {
struct QType {
  int f, x, k, id;
  bool operator<(const QType &B) const { return x < B.x; }
} Q[2 * N];
int plu[N], val[N];
int Qc, c;
void Add(int l, int r) {
  for (; l <= r && l % S != 0; l++) val[l]++;
  for (; l <= r && r % S != S - 1; r--) val[r]++;
  if (l <= r) {
    for (int i = l / S; i < r / S + 1; i++) plu[i]++;
  }
}
int Qry(int x) { return plu[x / S] + val[x]; }
void Ins(int l, int r, int k, int i) {
  Q[++Qc] = (QType){1, r, k, i};
  Q[++Qc] = (QType){-1, l - 1, k, i};
}
void Main() {
  sort(Q + 1, Q + Qc + 1);
  for (c = 1; c <= Qc && Q[c].x == 0; c++)
    ;
  for (int i = 1; i < n + 1; i++) {
    Add(I[pt[i]], O[pt[i]]);
    for (; c <= Qc && Q[c].x == i; c++) {
      x = 0;
      for (int j = 0; j < str[Q[c].k].length(); j++) {
        x = t[x][str[Q[c].k][j] - 'a'];
        Ans[Q[c].id] += Q[c].f * Qry(I[x]);
      }
    }
  }
}
}  // namespace Sml
int main() {
  memset(las, -1, sizeof(las));
  n = IN();
  m = IN();
  for (int w = 1; w < n + 1; w++) {
    scanf("%s", s + 1);
    x = 0;
    l = strlen(s + 1);
    for (int i = 1; i < l + 1; i++) {
      int &u = t[x][s[i] - 'a'];
      if (!u) u = ++num;
      x = u;
    }
    str[w] = string(s + 1);
    pt[w] = x;
  }
  Build();
  dfs(0, -1);
  for (int i = 1; i < m + 1; i++) {
    l = IN(), r = IN(), k = IN();
    if (str[k].length() > S) {
      Big::Ins(l, r, k, i);
    } else {
      Sml::Ins(l, r, k, i);
    }
  }
  Big::Main();
  Sml::Main();
  for (int i = 1; i < m + 1; i++) {
    printf("%I64d\n", Ans[i]);
  }
}
