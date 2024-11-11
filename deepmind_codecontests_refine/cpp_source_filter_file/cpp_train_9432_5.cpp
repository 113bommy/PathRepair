#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 2147483647;
int n;
long long ans, ans1;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) (ch == '-') && (f = -f), ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int head[MAXN], trump;
struct Edge {
  int to, next, val;
  Edge(int u = 0, int v = 0, int w = 0) : to(v), next(head[u]), val(w){};
} e[MAXN << 1];
int in[MAXN];
inline void addedge(int u, int v, int w) {
  e[++trump] = Edge(u, v, w);
  head[u] = trump;
  e[++trump] = Edge(v, u, w);
  head[v] = trump;
  ++in[u];
  ++in[v];
}
queue<int> q;
long long d[MAXN], maxdis[MAXN];
int c[MAXN << 1];
long long len[MAXN << 1], dis[MAXN << 1], cnt;
int que[MAXN];
long long A[MAXN], B[MAXN], C[MAXN], D[MAXN];
int main() {
  register int i;
  n = read();
  for (i = 1; i <= n; ++i) {
    int u = read(), v = read(), w = read();
    addedge(u, v, w);
  }
  for (i = 1; i <= n; ++i)
    if (in[i] == 1) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (i = head[u]; i; i = e[i].next) {
      int v = e[i].to;
      if (--in[v] == 0) continue;
      d[v] = max(d[v], maxdis[u] + maxdis[v] + e[i].val);
      maxdis[v] = max(maxdis[v], maxdis[u] + e[i].val);
      if (in[v] == 1) q.push(v);
    }
  }
  for (i = 1; i <= n; ++i) {
    ans = max(ans, d[i]);
    if (in[i] == 2 && q.empty()) q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    c[++cnt] = u;
    for (i = head[u]; i; i = e[i].next) {
      int v = e[i].to;
      if (in[v] - 1 != 1 || v == c[cnt - 1]) continue;
      --in[v];
      len[cnt] = e[i].val;
      q.push(v);
      break;
    }
  }
  --cnt;
  for (i = 1; i <= cnt; ++i) dis[i] = maxdis[c[i]];
  long long sum = 0, maxn = 0;
  for (i = 1; i <= cnt; ++i) {
    sum += len[i - 1];
    A[i] = max(A[i - 1], dis[i] + sum);
    B[i] = max(B[i - 1], dis[i] + sum + maxn);
    maxn = max(maxn, dis[i] - sum);
  }
  long long tmp = len[cnt];
  len[cnt] = sum = maxn = 0;
  for (i = cnt - 1; i; --i) {
    sum += len[i];
    C[i] = max(C[i + 1], dis[i] + sum);
    D[i] = max(D[i - 1], dis[i] + sum + maxn);
    maxn = max(maxn, dis[i] - sum);
  }
  ans1 = B[cnt];
  for (i = 1; i < cnt; ++i)
    ans1 = min(ans1, max(max(B[i], D[i]), A[i] + C[i + 1] + tmp));
  printf("%lld\n", max(ans, ans1));
  return 0;
}
