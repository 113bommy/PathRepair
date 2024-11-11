#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
vector<int> edge[maxn];
map<unsigned long long, int> all;
unsigned long long myhash[maxn];
int name[maxn];
int num_down[maxn];
int ans;
int tot;
int finnum;
unsigned long long seed[maxn];
int who;
unsigned long long make() {
  return (unsigned long long)rand() << 48 | (unsigned long long)rand() << 32 |
         (unsigned long long)rand() << 16 | (unsigned long long)rand();
}
int get_id(unsigned long long x) {
  if (all[x] == 0) {
    all[x] = tot;
    tot++;
  }
  return all[x];
}
void dfs(int node, int pre) {
  int len = edge[node].size();
  myhash[node] = seed[0];
  for (int i = 0; i < len; ++i) {
    if (edge[node][i] == pre) continue;
    dfs(edge[node][i], node);
    myhash[node] += seed[name[edge[node][i]]];
  }
  int me = get_id(myhash[node]);
  num_down[me]++;
  name[node] = me;
}
unsigned long long head[maxn];
int as[maxn];
void dfs2(int node, int pre) {
  int len = edge[node].size();
  unsigned long long tmp = myhash[node];
  num_down[name[node]]--;
  if (num_down[name[node]] == 0) finnum--;
  if (finnum > ans) {
    ans = finnum;
    who = node;
  }
  if (pre) tmp += seed[head[node]];
  for (int i = 0; i < len; ++i) {
    if (edge[node][i] == pre) continue;
    unsigned long long test = tmp - seed[name[edge[node][i]]];
    int me = get_id(test);
    head[edge[node][i]] = me;
    if (num_down[me] == 0) finnum++;
    num_down[me]++;
    dfs2(edge[node][i], node);
    num_down[me]--;
    if (num_down[me] == 0) finnum--;
  }
  if (num_down[name[node]] == 0) finnum++;
  num_down[name[node]]++;
}
int main() {
  int n;
  srand(time(NULL));
  scanf("%d", &n);
  tot = 1;
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  for (int i = 0; i < maxn; ++i) seed[i] = make();
  dfs(1, 0);
  ans = tot - 2;
  who = 1;
  finnum = tot - 2;
  dfs2(1, 0);
  printf("%d\n", who);
  return 0;
}
