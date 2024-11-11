#include <bits/stdc++.h>
using namespace std;
const int MAXFN = 12000;
const int MAXFE = 150000;
const int INF = 0x3FFFFFFF;
const int To_Posi = 350000;
int NS, NE, NC, S, T;
int head[MAXFN], e[MAXFE], enxt[MAXFE], ec;
int cp[MAXFE];
int tag[MAXFN], lyr[MAXFN], Nid, cur[MAXFN], pre[MAXFN], prn[MAXFN];
int supp[MAXFN], comp[MAXFN], ans;
bool Gap;
void regi(int u, int v, int w) {
  ec++;
  e[ec] = v;
  cp[ec] = w;
  enxt[ec] = head[u];
  head[u] = ec;
}
void directed(int u, int v, int w) {
  regi(u, v, w);
  regi(v, u, 0);
}
void undirected(int u, int v, int w) {
  regi(u, v, w);
  regi(v, u, w);
}
void sap_graph_init() {
  NC = NE - NS + 1;
  ec = 0;
  int i;
  for (i = NS; i <= NE; i++) head[i] = 0;
}
void push(int Eid, int fs) {
  cp[Eid] -= fs;
  cp[((Eid - 1) ^ 1) + 1] += fs;
}
void relabel(int x) {
  int ol = tag[x];
  int nl = NC;
  for (int E = head[x]; E; E = enxt[E])
    if ((cp[E]) && (tag[x] <= tag[e[E]] + 1)) nl = min(nl, tag[e[E]] + 1);
  lyr[nl]++;
  lyr[ol]--;
  tag[x] = nl;
  Gap |= (lyr[ol] == 0);
  cur[x] = head[x];
}
void sap_initialize() {
  int i;
  for (i = NS; i <= NE; i++) {
    tag[i] = lyr[i] = 0;
    cur[i] = head[i];
  }
  lyr[0] = NC;
  Nid = S;
  Gap = false;
  supp[Nid] = INF;
  comp[Nid] = 0;
}
int sap() {
  int ans = 0;
  while ((tag[S] != NC) && (!Gap)) {
    if (Nid == T) {
      int increment = supp[Nid] - comp[Nid];
      ans += increment;
      for (int x = T; x != S; x = prn[x]) {
        comp[x] += increment;
        push(pre[x], increment);
      }
    }
    bool Aug = false;
    if (supp[Nid] > comp[Nid])
      for (; cur[Nid]; cur[Nid] = enxt[cur[Nid]]) {
        int E = cur[Nid];
        if ((cp[E]) && (tag[Nid] == tag[e[E]] + 1)) {
          Aug = true;
          supp[e[E]] = min(cp[E], supp[Nid] - comp[Nid]);
          comp[e[E]] = 0;
          prn[e[E]] = Nid;
          pre[e[E]] = E;
          Nid = e[E];
          break;
        }
      }
    if (!Aug) {
      if (Nid != T) relabel(Nid);
      if (Nid == S)
        comp[Nid] = 0;
      else
        Nid = prn[Nid];
    }
  }
  return ans;
}
int Y[55][205], a[55], b[55], c[55], l[55], r[55];
int N, M;
int f(int a, int b, int c, int x) { return c + x * (b + x * a); }
int main() {
  scanf("%d%d", &N, &M);
  NS = 1;
  NE = 0;
  S = ++NE;
  T = ++NE;
  int i, j;
  for (i = 1; i <= N; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
  for (i = 1; i <= N; i++) {
    scanf("%d%d", &l[i], &r[i]);
    l[i] += 100;
    r[i] += 100;
  }
  for (i = 1; i <= N; i++)
    for (j = l[i]; j <= r[i] + 1; j++) Y[i][j] = ++NE;
  sap_graph_init();
  for (i = 1; i <= N; i++) {
    directed(S, Y[i][l[i]], INF);
    directed(Y[i][r[i] + 1], T, INF);
    for (j = l[i]; j <= r[i]; j++)
      directed(Y[i][j], Y[i][j + 1], To_Posi - f(a[i], b[i], c[i], j - 100));
  }
  for (i = 1; i <= M; i++) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    for (j = l[u]; j <= r[u] + 1; j++)
      if ((j - d >= l[v]) && (j - d <= r[v] + 1))
        directed(Y[u][j], Y[v][j - d], INF);
  }
  sap_initialize();
  printf("%d\n", N * To_Posi - sap());
}
