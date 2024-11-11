#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int MAXM = 3005;
const double inf = 1e8;
const double eps = 1e-8;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
int n, m, U[MAXM], V[MAXM], A[MAXM], B[MAXM], C[MAXM], D[MAXM];
struct Edge {
  int v, nxt;
  double w;
} e[MAXM << 1];
int first[MAXN], used[MAXN], eCnt;
inline void AddEdge(int u, int v, double w) {
  e[++eCnt].v = v;
  e[eCnt].w = w;
  e[eCnt].nxt = first[u];
  first[u] = eCnt;
}
inline void Add(int u, int v, double w) {
  AddEdge(u, v, w);
  AddEdge(v, u, 0);
}
double in[MAXN];
int S, T, level[MAXN], q[MAXN], head, tail;
bool BFS() {
  for (int i = 1; i <= T; ++i) {
    level[i] = -1;
    used[i] = first[i];
  }
  level[S] = 0;
  q[head = tail = 1] = S;
  while (head <= tail) {
    int u = q[head++];
    if (u == T) return 1;
    for (int i = first[u]; i; i = e[i].nxt) {
      int v = e[i].v;
      if (e[i].w > eps && level[v] == -1) {
        level[v] = level[u] + 1;
        q[++tail] = v;
      }
    }
  }
  return 0;
}
double DFS(int u, double flow) {
  if (u == T) return flow;
  double ret = 0;
  for (int i = used[u]; i; i = e[i].nxt, used[u] = i) {
    int v = e[i].v;
    if (e[i].w > eps && level[v] == level[u] + 1) {
      double tmp = DFS(v, min(flow, e[i].w));
      e[i].w -= tmp;
      e[i ^ 1].w += tmp;
      flow -= tmp;
      ret += tmp;
      if (flow < eps) break;
    }
  }
  return ret;
}
double Check(double mid) {
  eCnt = 1;
  for (int i = 1; i <= T; ++i) {
    in[i] = first[i] = 0;
  }
  for (int i = 1; i <= m; ++i) {
    double l = mid * A[i] + B[i];
    double r = mid * C[i] + D[i];
    Add(U[i], V[i], r - l);
    in[V[i]] += l;
    in[U[i]] -= l;
  }
  double ret = 0;
  for (int i = 1; i <= n; ++i) {
    if (in[i] > eps) {
      ret += in[i];
      Add(S, i, in[i]);
    } else if (in[i] < -eps) {
      Add(i, T, -in[i]);
    }
  }
  while (BFS()) {
    ret -= DFS(S, inf);
  }
  return ret;
}
void init() {
  read(n);
  read(m);
  for (int i = 1; i <= m; ++i) {
    read(U[i]);
    read(V[i]);
    read(A[i]);
    read(B[i]);
    read(C[i]);
    read(D[i]);
  }
  S = n + 1, T = S + 1;
}
void solve() {
  double L = 0, R = 1, ok = -1;
  while (R - L > eps) {
    double M1 = L + (R - L) / 3, M2 = R - (R - L) / 3;
    double D1 = Check(M1), D2 = Check(M2);
    if (D1 < eps) {
      ok = M1;
      break;
    }
    if (D2 < eps) {
      ok = M2;
      break;
    }
    (D1 > D2) ? L = M1 : R = M2;
  }
  if (ok < 0) {
    printf("0\n");
    return;
  }
  double L1 = 0, R1 = ok;
  while (R1 - L1 > eps) {
    double M = (L1 + R1) / 2;
    (Check(M) > eps) ? L1 = M : R1 = M;
  }
  double L2 = ok, R2 = 1;
  while (R2 - L2 > eps) {
    double M = (L2 + R2) / 2;
    (Check(M) > eps) ? R2 = M : L2 = M;
  }
  printf("%.8lf\n", L2 - L1);
}
int main() {
  init();
  solve();
  return 0;
}
