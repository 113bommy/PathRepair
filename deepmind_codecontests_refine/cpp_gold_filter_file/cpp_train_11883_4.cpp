#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct Edge {
  int v;
  int next;
} edge[maxn * 2];
int head[maxn];
int tol;
void addEdge(int u, int v) {
  edge[tol].v = v;
  edge[tol].next = head[u];
  head[u] = tol++;
}
int a1[maxn], ans1[maxn], flag[maxn], id[maxn], res[maxn];
int in;
long long ans;
vector<int> vec[maxn];
int dfs(int s, int pre) {
  int cnt = 0;
  int mx = -1;
  int mxid = -1;
  id[s] = s;
  for (int i = head[s]; i != 0; i = edge[i].next) {
    int v = edge[i].v;
    if (v == pre) continue;
    int ele = dfs(v, s);
    if (mx < ele) {
      mx = ele;
      mxid = id[v];
    }
    cnt++;
  }
  for (int i = head[s]; i != 0; i = edge[i].next) {
    int v = edge[i].v;
    if (id[v] == mxid || v == pre) continue;
    int ele = res[v];
    if (mx == ele) {
      vec[id[v]].push_back(mxid);
      for (int j = 0; j < vec[mxid].size(); j++) {
        vec[id[v]].push_back(vec[mxid][j]);
      }
      vec[mxid].clear();
      break;
    }
  }
  if (cnt == 0) {
    flag[s] = 1;
    res[s] = a1[s];
  } else {
    if (a1[s] > mx) {
      id[s] = mxid;
      res[s] = mx;
    } else if (a1[s] == mx) {
      vec[mxid].push_back(s);
      res[s] = mx;
      id[s] = mxid;
    } else {
      flag[s] = 1;
      flag[mxid] = 0;
      res[s] = a1[s];
    }
  }
  return res[s];
}
int main() {
  int len1;
  scanf("%d", &len1);
  for (int i = 1; i <= len1; i++) {
    scanf("%d", &a1[i]);
  }
  tol = 1;
  for (int i = 1; i < len1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addEdge(u, v);
    addEdge(v, u);
  }
  dfs(1, 0);
  int s = 1;
  ans = 0;
  for (int s = 1; s <= len1; s++) {
    if (flag[s]) {
      ans += a1[s];
      ans1[++in] = s;
      for (int i = 0; i < vec[s].size(); i++) {
        if (flag[vec[s][i]] == 0) ans1[++in] = vec[s][i];
      }
    }
  }
  sort(ans1 + 1, ans1 + in + 1);
  int len = in;
  in = 0;
  for (int i = 1; i <= len; i++) {
    if (ans1[i - 1] != ans1[i]) ans1[++in] = ans1[i];
  }
  printf("%lld %d\n", ans, in);
  for (int i = 1; i < in; i++) {
    printf("%d ", ans1[i]);
  }
  printf("%d\n", ans1[in]);
}
