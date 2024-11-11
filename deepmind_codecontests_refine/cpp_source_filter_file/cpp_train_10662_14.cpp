#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long int INF = 1e18;
const int N = 100005;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;
const double PI = acos(-1.0);
long long int n, m;
long long int ara[2 * N];
long long int Start[2 * N], Finish[2 * N], Level[2 * N];
long long int Time = 0;
long long int Tree[2 * 4 * N], Lazy[2 * 4 * N];
vector<int> graph[2 * N];
void Propagate(long long int node, long long int b, long long int e) {
  if (Lazy[node] != 0) {
    Tree[node] += (Lazy[node]);
    if (b != e) {
      Lazy[2 * node] += Lazy[node];
      Lazy[2 * node + 1] += Lazy[node];
    }
    Lazy[node] = 0;
  }
}
void Update(long long int node, long long int b, long long int e,
            long long int i, long long int j, long long int val) {
  Propagate(node, b, e);
  if (i > e || j < b) return;
  if (i <= b && j >= e) {
    Tree[node] += val;
    if (b != e) {
      Lazy[2 * node] += val;
      Lazy[2 * node + 1] += val;
    }
    return;
  }
  long long int left = 2 * node, right = 2 * node + 1, mid = (b + e) / 2;
  Update(left, b, mid, i, j, val);
  Update(right, mid + 1, e, i, j, val);
  Tree[node] = Tree[left] + Tree[right];
}
long long int Query(long long int node, long long int b, long long int e,
                    long long int pos) {
  Propagate(node, b, e);
  if (pos > e || pos < b) return 0LL;
  if (b == e && b == pos) return Tree[node];
  long long int left = 2 * node, right = 2 * node + 1, mid = (b + e) / 2;
  long long int q1 = Query(left, b, mid, pos);
  long long int q2 = Query(right, mid + 1, e, pos);
  return (q1 + q2);
}
void dfs(int s, int p) {
  Start[s] = ++Time;
  Level[s] = Level[p] + 1;
  for (int i = 0; i < graph[s].size(); i++) {
    int next = graph[s][i];
    if (next == p) continue;
    dfs(next, s);
  }
  Finish[s] = Time;
}
int main(int argc, char const *argv[]) {
  scanf("%lld %lld", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &ara[i]);
  }
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  Time = 0;
  dfs(1, 0);
  while (m--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int pos, val;
      scanf("%d %d", &pos, &val);
      int from = Start[pos], to = Finish[pos];
      if (Level[pos] & 1)
        Update(1, 1, n, from, to, +val);
      else
        Update(1, 1, 2 * N, from, to, -val);
    } else {
      int pos;
      scanf("%d", &pos);
      int x = Start[pos];
      long long int ans = Query(1, 1, 2 * N, x);
      if (Level[pos] & 1)
        printf("%lld\n", ara[pos] + ans);
      else
        printf("%lld\n", ara[pos] - ans);
    }
  }
  return 0;
}
