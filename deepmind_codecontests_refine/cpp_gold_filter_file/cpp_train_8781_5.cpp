#include <bits/stdc++.h>
using namespace std;
const int X = 1005;
const int maxn = 100005;
const int maxm = 3000005;
const int inf = 1e9;
int dis[maxn], pre[maxn], arc[maxn];
int po[maxn], tol;
bool use[maxn];
int map[X][X];
int n, m, s, t, k, p, ans;
int d[maxn];
int num[30];
struct node {
  int y, f, c, next;
} edge[maxm];
void add(int x, int y, int c, int f) {
  edge[++tol].y = y;
  edge[tol].c = c;
  edge[tol].f = f;
  edge[tol].next = po[x];
  po[x] = tol;
  edge[++tol].y = x;
  edge[tol].c = -c;
  edge[tol].f = 0;
  edge[tol].next = po[y];
  po[y] = tol;
}
bool spfa() {
  memset(use, false, sizeof(use));
  for (int i = 1; i <= n; i++) dis[i] = inf;
  dis[s] = 0;
  queue<int> q;
  q.push(s);
  pre[s] = 0;
  int x, y;
  while (q.size()) {
    x = q.front();
    q.pop();
    use[x] = false;
    for (int i = po[x]; i; i = edge[i].next) {
      y = edge[i].y;
      if (edge[i].f > 0 && edge[i].c + dis[x] < dis[y]) {
        dis[y] = edge[i].c + dis[x];
        pre[y] = i;
        if (!use[y]) {
          use[y] = true;
          q.push(y);
        }
      }
    }
  }
  if (dis[t] == inf) return false;
  int aug = inf;
  for (int i = pre[t]; i; i = pre[edge[i ^ 1].y]) aug = min(aug, edge[i].f);
  for (int i = pre[t]; i; i = pre[edge[i ^ 1].y]) {
    edge[i].f -= aug;
    edge[i ^ 1].f += aug;
  }
  ans += dis[t] * aug;
  return true;
}
int main() {
  char str[105];
  while (cin >> str >> n) {
    memset(po, 0, sizeof(po));
    tol = 1;
    int sum = 0;
    memset(num, 0, sizeof(num));
    int len = strlen(str);
    for (int i = 0; i < len; i++) num[str[i] - 'a' + 1]++;
    s = 26 + n + 1;
    t = s + 1;
    for (int i = 1; i <= 26; i++) {
      add(s, i, 0, num[i]);
      sum += num[i];
    }
    int x;
    for (int i = 1; i <= n; i++) {
      scanf("%s%d", str, &x);
      memset(num, 0, sizeof(num));
      for (int j = 0; str[j]; j++) num[str[j] - 'a' + 1]++;
      for (int j = 1; j <= 26; j++)
        if (num[j]) add(j, i + 26, i, num[j]);
      add(i + 26, t, 0, x);
    }
    n = t;
    ans = 0;
    int ok = 0;
    while (spfa())
      ;
    for (int i = po[t]; i; i = edge[i].next) ok += edge[i].f;
    if (ok != sum)
      puts("-1");
    else
      cout << ans << endl;
  }
  return 0;
}
