#include <bits/stdc++.h>
const int MOD = 1000000007;
using namespace std;
int N, K, S;
const int MX = 500005;
const int TMX = MX * 4;
vector<int> edges[MX];
vector<int> children[MX];
int height[MX];
int originalContribution[MX];
int currentAnswer;
map<int, int> minerMap;
set<pair<int, int>, greater<pair<int, int> > > minerMapSet;
int getIndexInTree(int h) {
  auto it = minerMapSet.lower_bound({h, ((int)1e9 + 10)});
  if (it == minerMapSet.end())
    return S;
  else
    return it->second;
}
int minPrefix[TMX], sum[TMX];
void add(int idx, int a, int b, int pos, int val) {
  if (pos < a || pos > b) return;
  if (a == b) {
    sum[idx] += val;
    minPrefix[idx] = min(sum[idx], 0);
  } else {
    int l = idx * 2 + 1;
    int r = idx * 2 + 2;
    int mid = (a + b) / 2;
    add(l, a, mid, pos, val);
    add(r, mid + 1, b, pos, val);
    sum[idx] = sum[l] + sum[r];
    minPrefix[idx] = minPrefix[l];
    minPrefix[idx] = min(minPrefix[idx], sum[l] + minPrefix[r]);
  }
}
void add(int pos, int val) { add(0, 0, S - 1, pos, val); }
void init(int x, int parent) {
  for (auto& o : (edges[x]))
    if (o != parent) {
      children[x].push_back(o);
      init(o, x);
    }
}
void dfs1(int x, int limit) {
  int h = min(height[x], limit);
  originalContribution[x] = getIndexInTree(h);
  add(originalContribution[x], 1);
  for (auto& o : (children[x])) dfs1(o, h);
}
void dfs2(int x, int limit, int direction) {
  int h = min(height[x], limit);
  int idx = getIndexInTree(h);
  add(originalContribution[x], -direction);
  add(idx, direction);
  for (auto& o : (children[x])) dfs2(o, h, direction);
}
int main() {
  scanf("%d", &(N));
  for (int i = (0); i < (N); i++) scanf("%d", &(height[i]));
  for (int k = (0); k < (N - 1); k++) {
    int a;
    scanf("%d", &(a));
    ;
    int b;
    scanf("%d", &(b));
    ;
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  init(0, -1);
  scanf("%d", &(K));
  int miners[K];
  for (int i = (0); i < (K); i++) scanf("%d", &(miners[i]));
  sort(miners, miners + K);
  reverse(miners, miners + K);
  priority_queue<pair<int, int> > Q;
  Q.push({height[0], 0});
  for (int i = (0); i < (K); i++) {
    int x = Q.top().second;
    if (height[x] < miners[i]) {
      set<int, greater<int> > minerSet;
      for (int j = (i); j < (K); j++) minerSet.insert(miners[j]);
      S = minerSet.size();
      int crnt = 0;
      for (auto& v : (minerSet)) minerMap[v] = crnt++;
      for (auto& p : (minerMap)) {
        minerMapSet.insert(p);
      }
      for (int j = (i); j < (K); j++) add(minerMap[miners[j]], -1);
      vector<int> V;
      while (!Q.empty()) {
        x = Q.top().second;
        V.push_back(x);
        Q.pop();
      }
      for (auto& n : (V)) dfs1(n, ((int)1e9 + 10));
      for (auto& n : (V)) {
        int change = miners[i] - height[n];
        height[n] = miners[i];
        dfs2(x, ((int)1e9 + 10), 1);
        if (minPrefix[0] == 0) {
          printf("%d\n", change);
          return 0;
        }
        dfs2(x, ((int)1e9 + 10), -1);
      }
      printf("-1\n");
      return 0;
    } else {
      Q.pop();
      for (auto& v : (children[x])) Q.push({height[v], v});
    }
  }
  printf("0\n");
}
