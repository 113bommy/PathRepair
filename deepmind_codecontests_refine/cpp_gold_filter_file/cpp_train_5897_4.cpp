#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int n;
struct po {
  int a, b, c;
};
vector<int> e[N];
vector<po> ans;
int point[2], depth[N][2];
bool did[N];
long long val;
bool judge = false;
stack<int> s;
int maxdep = 0;
int bfs(int x) {
  memset(did, false, sizeof(did));
  queue<int> q;
  did[x] = true;
  q.push(x);
  int now = x;
  while (!q.empty()) {
    now = q.front();
    q.pop();
    for (int i = 0; i < e[now].size(); i++) {
      if (!did[e[now][i]]) {
        q.push(e[now][i]);
        did[e[now][i]] = true;
      }
    }
  }
  return now;
}
void dfs(int x, int y, int dep) {
  maxdep = max(maxdep, dep);
  did[x] = true;
  for (int i = 0; i < e[x].size(); i++) {
    if (!did[e[x][i]]) {
      depth[e[x][i]][y] = dep + 1;
      dfs(e[x][i], y, dep + 1);
    }
  }
}
void Find(int now, int fa) {
  s.push(now);
  did[now] = true;
  if (now == point[1]) {
    judge = true;
    return;
  }
  for (int i = 0; i < e[now].size(); i++) {
    if (e[now][i] != fa) {
      Find(e[now][i], now);
      if (judge)
        break;
      else {
        did[e[now][i]] = false;
      }
    }
  }
  if (!judge) {
    did[now] = false;
    s.pop();
  }
}
void get_ans(int now, int fa) {
  if (!did[now]) val += max(depth[now][0], depth[now][1]);
  for (int i = 0; i < e[now].size(); i++) {
    if (e[now][i] != fa) get_ans(e[now][i], now);
  }
  if (!did[now]) {
    po p;
    p.b = now;
    p.c = now;
    if (depth[now][0] > depth[now][1])
      p.a = point[0];
    else
      p.a = point[1];
    ans.push_back(p);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int ta, tb;
    scanf("%d%d", &ta, &tb);
    e[ta].push_back(tb);
    e[tb].push_back(ta);
  }
  point[0] = bfs(1);
  point[1] = bfs(point[0]);
  memset(did, false, sizeof(did));
  dfs(point[0], 0, 0);
  memset(did, false, sizeof(did));
  dfs(point[1], 1, 0);
  memset(did, false, sizeof(did));
  Find(point[0], 0);
  val = (long long)maxdep * (maxdep + 1) / 2;
  get_ans(point[0], 0);
  while (s.size() != 1) {
    po p;
    p.a = point[0];
    p.b = s.top();
    p.c = s.top();
    ans.push_back(p);
    s.pop();
  }
  printf("%I64d\n", val);
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d %d\n", ans[i].a, ans[i].b, ans[i].c);
}
