#include <bits/stdc++.h>
using namespace std;
int ecnt;
struct Edge {
  int to, w, c, num;
  Edge *next;
} * mat[300 * 3], edges[300 * 20];
void link(int x, int to, int w, int c) {
  edges[ecnt].num = ecnt;
  edges[ecnt].to = to;
  edges[ecnt].w = w;
  edges[ecnt].c = c;
  edges[ecnt].next = mat[x];
  mat[x] = &edges[ecnt++];
  edges[ecnt].num = ecnt;
  edges[ecnt].to = x;
  edges[ecnt].w = 0;
  edges[ecnt].c = -c;
  edges[ecnt].next = mat[to];
  mat[to] = &edges[ecnt++];
}
int cal(int x) {
  int ret = 0;
  while (x) {
    ret += x & 1;
    x >>= 1;
  }
  return ret;
}
int n, m, data[300];
int source, remit, dis[300 * 3], from[300 * 3][2];
bool in_que[300 * 3];
queue<int> que;
bool spfa() {
  memset(dis, 0x37373737, sizeof(dis));
  dis[source] = 0;
  que.push(source);
  while (!que.empty()) {
    int i = que.front();
    que.pop();
    in_que[i] = false;
    for (Edge *p = mat[i]; p; p = p->next) {
      int to = p->to;
      if (p->w == 0) continue;
      if (dis[to] > dis[i] + p->c) {
        dis[to] = dis[i] + p->c;
        from[to][0] = i;
        from[to][1] = p->num;
        if (!in_que[to]) {
          in_que[to] = true;
          que.push(to);
        }
      }
    }
  }
  return dis[remit] != 0x37373737;
}
bool mark[30];
int v[300];
vector<pair<int, int> > ans;
int get_v() {
  for (int i = 0; i < m; i++)
    if (mark[i]) {
      mark[i] = false;
      return i;
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &data[i]);
  source = 3 * n, remit = 3 * n + 1;
  link(source, 0, m, 0);
  link((n - 1) * 3 + 2, remit, m, 0);
  link((n - 1) * 3, remit, m, 0);
  for (int i = 0; i < n; i++) {
    if (i != n - 1) {
      link(i * 3, (i + 1) * 3, m, 0);
      link(i * 3 + 2, (i + 1) * 3, 1, 0);
    }
    link(i * 3, i * 3 + 1, 1, cal(data[i]));
    link(i * 3 + 1, i * 3 + 2, 1, -100000);
    int j = i + 1;
    for (; j < n; j++)
      if (data[j] == data[i]) break;
    if (j < n) {
      link(i * 3 + 2, j * 3 + 1, 1, 0);
    }
  }
  int ff = 0;
  while (spfa()) {
    int i = remit;
    ff += dis[remit];
    while (i != source) {
      edges[from[i][1]].w--;
      edges[from[i][1] ^ 1].w++;
      i = from[i][0];
    }
  }
  memset(mark, true, sizeof(mark));
  for (int i = 0; i < n; i++) {
    Edge *p;
    for (p = mat[i * 3 + 1]; p; p = p->next)
      if (p->to != i * 3 + 2 && p->w == 1) break;
    if (p->to == i * 3) {
      v[i] = get_v();
      ans.push_back(make_pair(0, i));
    } else
      v[i] = v[p->to / 3];
    ans.push_back(make_pair(1, i));
    if (i == n - 1) continue;
    for (p = mat[i * 3 + 2]; p; p = p->next)
      if (p->to == (i + 1) * 3) break;
    if (p->w == 0) mark[v[i]] = true;
  }
  printf("%d %d\n", (int)ans.size(), ff + (n * 100000));
  for (__typeof(ans.begin()) iter = ans.begin(); iter != ans.end(); iter++) {
    int i = iter->second;
    if (iter->first == 0)
      printf("%c=%d\n", v[i] + 'a', data[i]);
    else
      printf("printf(%c)\n", v[i] + 'a');
  }
  return 0;
}
