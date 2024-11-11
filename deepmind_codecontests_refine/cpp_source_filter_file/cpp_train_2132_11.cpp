#include <bits/stdc++.h>
using namespace std;
struct edge {
  int a, b, c;
  int next;
  edge() {}
  edge(int a, int b, int c, int n) : a(a), b(b), c(c), next(n) {}
} e[1010000 + 1000];
int p[70200], tol;
void add(int a, int b, int c) {
  e[tol] = edge(a, b, c, p[a]);
  p[a] = tol++;
}
int n, m;
int h[70005], gap[70005];
int INF;
int s, t;
int min(int a, int b) { return a < b ? a : b; }
int dfs(int u, int inf) {
  if (u == t) return inf;
  int d = inf, minh = INF;
  for (int i = p[u]; i != -1; i = e[i].next)
    if (e[i].c) {
      if (h[e[i].b] + 1 == h[u]) {
        int ret = dfs(e[i].b, min(d, e[i].c));
        e[i].c -= ret;
        e[i ^ 1].c += ret;
        d -= ret;
        if (h[s] >= INF) return inf - d;
        if (!d) break;
      }
      minh = min(minh, h[e[i].b]);
    }
  if (d == inf) {
    if (--gap[h[u]] == 0) h[s] = INF;
    h[u] = minh + 1;
    gap[h[u]]++;
  }
  return inf - d;
}
int maxflow() {
  int n = t + 1;
  INF = n;
  for (int i = 0; i < n; i++) h[i] = 0, gap[i] = 0;
  gap[0] = n;
  int mflow = 0;
  while (h[s] < INF) {
    int ret = dfs(s, 1 << 30);
    mflow += ret;
  }
  return mflow;
}
int a[1000];
int is[100000];
int v[100010];
int pr[10010];
void getprime() {
  memset(is, 0, sizeof(is));
  int cnt = 0;
  for (int i = 2; i < 10001; ++i) {
    if (!is[i]) pr[cnt++] = i;
    for (int j = 0; j < cnt && pr[j] * i < 10001; ++j) is[i * pr[j]] = 1;
  }
}
int isprime(int t) { return !is[t]; }
int pos;
vector<int> ans[10000];
void findans(int t) {
  ans[pos].push_back(t);
  v[t] = 1;
  for (int i = p[t]; i != -1; i = e[i].next) {
    if (v[e[i].b]) continue;
    if (a[t] & 1) {
      if (e[i].c) continue;
    } else {
      if (e[i ^ 1].c) continue;
    }
    findans(e[i].b);
  }
}
void solve() {
  memset(p, -1, sizeof(p));
  tol = 0;
  getprime();
  s = n, t = n + 1;
  int num = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] & 1) {
      ++num;
      add(s, i, 2);
      add(i, s, 0);
    } else {
      add(i, t, 2);
      add(t, i, 0);
    }
    for (int j = 0; j < i; ++j) {
      if (isprime(a[i] + a[j])) {
        if (a[i] & 1) {
          add(i, j, 1);
          add(j, i, 0);
        } else {
          add(j, i, 1);
          add(i, j, 0);
        }
      }
    }
  }
  pos = 0;
  int ret = maxflow();
  if (num * 2 != ret || num * 2 != n) {
    cout << "Impossible" << endl;
    return;
  } else {
    memset(v, 0, sizeof(v));
    for (int i = p[s]; i != -1; i = e[i].next) {
      if (v[e[i].b] == 0) {
        findans(e[i].b);
        pos++;
      }
    }
  }
  cout << pos << endl;
  for (int i = 0; i < pos; ++i) {
    cout << ans[i].size() << " ";
    for (int j = 0; j < ans[i].size(); ++j) printf("%d ", ans[i][j] + 1);
    cout << endl;
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  solve();
}
