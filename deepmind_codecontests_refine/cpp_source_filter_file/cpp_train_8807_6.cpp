#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long POW(long long a, long long b, long long MMM = MOD) {
  long long ret = 1;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) {
  if (a == 0 || b == 0) return a + b;
  return a * (b / gcd(a, b));
}
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
struct Edge {
  int to, r, c;
  Edge* ori;
  Edge* rev;
  Edge(int T, int R, int C) { to = T, r = R, c = C; }
};
vector<Edge*> v[10002];
void addedge(int f, int t, int r, int c) {
  Edge* ori = new Edge(t, r, c);
  Edge* rev = new Edge(f, 0, -c);
  ori->rev = rev;
  rev->rev = ori;
  v[f].push_back(ori);
  v[t].push_back(rev);
}
const int S = 0, T = 10001;
int level[10002], work[10002];
bool bfs() {
  memset((level), -1, sizeof(level));
  ;
  level[S] = 0;
  queue<int> q;
  q.push(S);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto& nn : v[x]) {
      int next = nn->to;
      if (level[next] == -1 && nn->r > 0) {
        level[next] = level[x] + 1;
        q.push(next);
      }
    }
  }
  return level[T] != -1;
}
int dfs(int N, int des, int flow) {
  if (N == des) return flow;
  for (int& i = work[N]; i < v[N].size(); i++) {
    int next = v[N][i]->to;
    if (level[next] == level[N] + 1 && v[N][i]->r > 0) {
      int df = dfs(next, des, min(v[N][i]->r, flow));
      if (df > 0) {
        v[N][i]->r -= df;
        v[N][i]->rev->r += df;
        return df;
      }
    }
  }
  return 0;
}
int n, m;
int x[5001], y[5001];
bool ok(int k) {
  for (int(i) = (0); (i) <= (T); (i) += (1)) v[i].clear();
  for (int(i) = (1); (i) <= (m); (i) += (1)) {
    addedge(S, i, 1, 0);
    addedge(i, m + x[i], 1, 0);
    addedge(i, m + y[i], 1, 0);
  }
  for (int(i) = (m + 1); (i) <= (m + n); (i) += (1)) addedge(i, T, k, 0);
  int ans = 0;
  while (bfs()) {
    memset((work), 0, sizeof(work));
    ;
    while (1) {
      int f = dfs(S, T, 987654321);
      if (f == 0) break;
      ans += f;
    }
  }
  return ans == m;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int(i) = (1); (i) <= (m); (i) += (1)) scanf("%d%d", x + i, y + i);
  int l = 1, r = m;
  while (l <= r) {
    int k = (l + r) >> 1;
    if (ok(k))
      r = k - 1;
    else
      l = k + 1;
  }
  printf("%d\n", l);
  ok(l);
  for (int(i) = (1); (i) <= (m); (i) += (1)) {
    int t;
    for (auto next : v[i]) {
      if (next->to == S) continue;
      if (next->r == 0) t = next->to - m;
    }
    if (x[i] != t) swap(x[i], y[i]);
    printf("%d %d\n", x[i], y[i]);
  }
}
