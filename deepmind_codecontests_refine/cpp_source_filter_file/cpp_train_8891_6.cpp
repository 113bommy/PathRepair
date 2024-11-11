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
long long int BIT[2 * N];
vector<int> graph[2 * N];
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
void Update(long long int idx, long long int val) {
  for (; idx <= 2 * N; idx += (idx & -idx)) {
    BIT[idx] += val;
  }
}
long long int Query(long long int idx) {
  long long int ret = 0;
  for (; idx > 0; idx -= (idx & -idx)) {
    ret += BIT[idx];
  }
  return ret;
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
      if (Level[pos] & 1) {
        Update(from, +val);
        Update(to + 1, -val);
      } else {
        Update(from, -val);
        Update(to, +val);
      }
    } else {
      int pos;
      scanf("%d", &pos);
      int x = Start[pos];
      long long int ans = Query(x);
      if (Level[pos] & 1)
        printf("%lld\n", ara[pos] + ans);
      else
        printf("%lld\n", ara[pos] - ans);
    }
  }
  return 0;
}
