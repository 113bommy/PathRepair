#include <bits/stdc++.h>
using namespace std;
char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int getnum() {
  int x = 0, f = 1;
  char ch = gc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = gc();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = gc();
  }
  return x * f;
}
const int N = 100010, M = 1000010;
int n;
int cnt;
int head[N];
struct edge {
  int v, nxt;
} vec[N];
int par[N];
int low[N];
int siz[N];
struct tnode {
  int id, S;
};
int ID[N];
int top;
int st[M];
int P[N];
int Line[N];
bool operator<(tnode a, tnode b) { return a.S < b.S; }
void addedge(int u, int v) {
  vec[++cnt] = (edge){v, head[u]};
  head[u] = cnt;
}
void get_read() {
  n = getnum();
  for (int i = 1; i <= n - 1; ++i) {
    par[i] = getnum();
    addedge(par[i], i);
  }
}
void init(int u, int dep) {
  low[u] = dep;
  siz[u] = 1;
  for (int i = head[u]; i; i = vec[i].nxt) {
    int v = vec[i].v;
    init(v, dep + 1);
    siz[u] += siz[v];
    low[u] = max(low[u], low[v]);
  }
}
void dfs(int u) {
  vector<tnode> C;
  C.clear();
  for (int i = head[u]; i; i = vec[i].nxt) {
    int v = vec[i].v;
    C.push_back((tnode){v, low[v]});
  }
  sort(C.begin(), C.end());
  int ret = ID[u] + 1;
  for (int i = 0, L = C.size(); i < L; ++i) {
    ID[C[i].id] = ret;
    ret += siz[C[i].id];
  }
  for (int i = head[u]; i; i = vec[i].nxt) dfs(vec[i].v);
}
void calc(int p) {
  while (P[Line[p]] != par[Line[p]])
    P[Line[p]] = par[P[Line[p]]], st[++top] = Line[p];
}
void get_work() {
  init(0, 0);
  ID[0] = 1;
  dfs(0);
  for (int i = 0; i <= n - 1; ++i) Line[ID[i]] = i;
  for (int i = 1; i <= n; ++i) P[Line[i]] = Line[i - 1];
  for (int i = 2; i <= n; ++i) calc(i);
  for (int i = 1; i <= n; ++i) printf("%d ", Line[i]);
  printf("\n");
  printf("%d\n", top);
  for (int i = 1; i <= top; ++i) printf("%d ", st[i]);
}
int main() {
  get_read();
  get_work();
  return 0;
}
