#include <bits/stdc++.h>
using namespace std;
const int inf_int = 2e9;
const long long inf_ll = 2e18;
const int MAX = 100005;
int x, y, z;
int points;
int head[MAX], total;
int nxt[MAX], aim[MAX], length[MAX];
int dis[MAX];
bool v[MAX];
void Add(int x, int y) {
  nxt[++total] = head[x];
  aim[total] = y;
  length[total] = 1;
  head[x] = total;
}
void BFS(int start) {
  static queue<int> q;
  while (!q.empty()) q.pop();
  q.push(start);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    v[x] = true;
    for (int i = head[x]; i; i = nxt[i])
      if (!v[aim[i]]) {
        dis[aim[i]] = dis[x] + length[i];
        q.push(aim[i]);
      }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    Add(x, y), Add(y, x);
    points = max(max(x, y), points);
  }
  BFS(1);
  int pos_max = 1;
  for (int i = 1; i <= points; ++i)
    if (dis[i] > dis[pos_max]) pos_max = i;
  memset(dis, 0, sizeof(dis));
  memset(v, false, sizeof(v));
  BFS(pos_max);
  int _max = 0;
  for (int i = 1; i <= points; ++i)
    if (dis[i] > _max) _max = dis[i];
  cout << _max << endl;
  return 0;
}
