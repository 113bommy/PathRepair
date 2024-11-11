#include <bits/stdc++.h>
using namespace std;
int read() {
  int ret = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return ret;
}
const int MAXN = 10000, MAXM = 10100;
const int MAXK = 100;
int n, m;
pair<int, int> front[MAXM + 10];
int orderx[MAXM + 10], stdx[MAXN + 10];
int cost[MAXM + 10];
void sortx() {
  static int num[MAXN + 10];
  memset(num, 0, sizeof(num));
  for (int i = 1; i <= m; i++) num[front[i].first]++;
  for (int i = 1; i <= n; i++) stdx[i] = num[i] += num[i - 1];
  for (int i = 1; i <= m; i++) orderx[++num[front[i].first - 1]] = i;
  return;
}
const long long inf = (1LL << 60);
long long d1[MAXN + 10], d2[MAXN + 10];
namespace Graph {
long long dis[MAXN + 10];
int pos[MAXN + 10];
int ht;
int id[MAXN + 10];
void up(int first) {
  while (first >> 1 && dis[id[first]] < dis[id[first >> 1]]) {
    swap(id[first], id[first >> 1]);
    swap(pos[id[first]], pos[id[first >> 1]]);
    first >>= 1;
  }
  return;
}
void down(int first) {
  while ((first << 1) <= ht) {
    int s =
        ((first << 1) == ht || dis[id[first << 1]] < dis[id[first << 1 | 1]])
            ? (first << 1)
            : (first << 1 | 1);
    if (dis[id[s]] < dis[id[first]]) {
      swap(id[s], id[first]);
      swap(pos[id[s]], pos[id[first]]);
      first = s;
    } else
      return;
  }
  return;
}
void insert(int first) {
  id[++ht] = first;
  pos[first] = ht;
  up(ht);
  return;
}
int pop() {
  int ret = id[1];
  swap(id[1], id[ht]);
  swap(pos[id[1]], pos[id[ht]]);
  ht--;
  down(1);
  return ret;
}
void dijkstra(int s) {
  ht = 0;
  for (int i = 1; i <= n; i++) dis[i] = inf;
  dis[s] = 0;
  for (int i = 1; i <= n; i++) insert(i);
  while (ht) {
    int first = pop();
    for (int i = stdx[first - 1] + 1; i <= stdx[first]; i++) {
      int next = front[orderx[i]].second;
      if (dis[next] > dis[first] + cost[orderx[i]]) {
        dis[next] = dis[first] + cost[orderx[i]];
        up(pos[next]);
      }
    }
  }
  return;
}
}  // namespace Graph
int l[MAXK + 10], r[MAXK + 10];
int k;
void init() {
  n = read();
  int M = read();
  k = read();
  int s1 = read(), s2 = read(), f = read();
  for (int i = 1; i <= M; i++) {
    int first = read(), second = read();
    front[++m] = make_pair(first, second);
    cost[m] = read();
  }
  for (int i = 1; i <= k; i++) {
    int first = read(), second = read();
    l[i] = read();
    r[i] = read();
    front[++m] = make_pair(first, second);
    cost[m] = r[i];
  }
  sortx();
  bool flag = true;
  while (flag) {
    flag = false;
    Graph::dijkstra(s1);
    for (int i = 1; i <= n; i++) d1[i] = Graph::dis[i];
    Graph::dijkstra(s2);
    for (int i = 1; i <= n; i++) d2[i] = Graph::dis[i];
    for (int i = 1; i <= k; i++) {
      int first = front[i + M].first;
      if (d1[first] < d2[first] && cost[i + M] != l[i]) {
        flag = true;
        cost[i + M] = l[i];
      }
    }
  }
  Graph::dijkstra(s1);
  long long ans1 = Graph::dis[f];
  Graph::dijkstra(s2);
  long long ans2 = Graph::dis[f];
  if (ans1 < ans2)
    puts("WIN");
  else if (ans1 == ans2)
    puts("DRAW");
  else
    puts("LOSE");
  if (ans1 <= ans2)
    for (int i = 1; i <= k; i++) printf("%d ", cost[i + M]);
  return;
}
int main() {
  init();
  return 0;
}
