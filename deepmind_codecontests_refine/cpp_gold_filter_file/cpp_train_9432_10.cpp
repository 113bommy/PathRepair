#include <bits/stdc++.h>
using namespace std;
const int MAX = 200050;
struct Edge {
  int des;
  long long length;
  Edge(int des_, int length_) : des(des_), length(length_) {}
};
vector<Edge> E[MAX];
int n;
bool vis[MAX];
bool inCircle[MAX];
int circleNode[MAX];
int circleNum;
long long circleLength[MAX];
int father[MAX];
long long father_length[MAX];
long long f[MAX];
void dfs_find(int x, int fa) {
  vis[x] = true;
  for (Edge temp : E[x]) {
    int v = temp.des;
    int length = temp.length;
    if (v == fa) continue;
    if (vis[v]) {
      if (inCircle[v]) {
        continue;
      }
      int u = x;
      while (u != v) {
        inCircle[u] = true;
        circleNode[++circleNum] = u;
        circleLength[circleNum] = father_length[u];
        u = father[u];
      }
      inCircle[v] = true;
      circleNode[++circleNum] = v;
      circleLength[circleNum] = length;
      continue;
    }
    father[v] = x;
    father_length[v] = length;
    dfs_find(v, x);
  }
}
long long chain = -1;
void dfs_dp(int x, int fa) {
  for (Edge temp : E[x]) {
    int v = temp.des;
    long long length = temp.length;
    if (v == fa || inCircle[v]) {
      continue;
    }
    dfs_dp(v, x);
    chain = max(chain, f[x] + f[v] + length);
    f[x] = max(f[x], f[v] + length);
  }
}
long long good[MAX], good1[MAX], best[MAX], best1[MAX];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int u, v, l;
    scanf("%d%d%d", &u, &v, &l);
    E[u].push_back(Edge(v, l));
    E[v].push_back(Edge(u, l));
  }
  dfs_find(1, 0);
  for (int i = 1; i <= circleNum; i++) {
    dfs_dp(circleNode[i], 0);
  }
  long long sum = 0;
  long long support = -0x3f3f3f3f;
  for (int i = 1; i <= circleNum; i++) {
    sum += circleLength[i - 1];
    good[i] = max(good[i - 1], sum + f[circleNode[i]]);
    best[i] = max(best[i - 1], sum + f[circleNode[i]] + support);
    support = max(support, f[circleNode[i]] - sum);
  }
  sum = -circleLength[circleNum];
  support = -0x3f3f3f3f;
  for (int i = circleNum; i >= 1; i--) {
    sum += circleLength[i];
    good1[i] = max(good1[i + 1], sum + f[circleNode[i]]);
    best1[i] = max(best1[i + 1], sum + f[circleNode[i]] + support);
    support = max(support, f[circleNode[i]] - sum);
  }
  long long ans = best[circleNum];
  int lastLength = circleLength[circleNum];
  for (int i = 1; i < circleNum; i++) {
    long long temp = good[i] + good1[i + 1] + lastLength;
    temp = max(max(best[i], best1[i + 1]), temp);
    ans = min(ans, temp);
  }
  ans = max(chain, ans);
  printf("%I64d\n", ans);
  return 0;
}
