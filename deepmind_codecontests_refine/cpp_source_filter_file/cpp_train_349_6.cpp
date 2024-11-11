#include <bits/stdc++.h>
using namespace std;
struct edge {
  int y, next;
};
const int maxn = 550, maxm = 10010;
int n, m, num, head[maxn], d[maxn][maxn][2], ansa[maxn], ansb[maxn];
edge e[maxm << 1];
pair<int, int> pre[maxn][maxn][2];
void add(int a, int b) {
  num++;
  e[num].next = head[a];
  head[a] = num;
  e[num].y = b;
}
int main() {
  scanf("%d%d", &n, &m);
  memset(head, -1, sizeof head);
  num = -1;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
    add(b, a);
  }
  memset(d, -1, sizeof d);
  queue<pair<pair<int, int>, int> > Q;
  d[1][n][0] = 0;
  Q.push(make_pair(make_pair(1, n), 0));
  while (!Q.empty()) {
    pair<pair<int, int>, int> now = Q.front();
    Q.pop();
    int a = now.first.first, b = now.first.second, s = now.second;
    if (a == n && b == 1 && s == 0) break;
    if (s == 0) {
      for (int temp = head[a]; temp >= 0; temp = e[temp].next) {
        int na = e[temp].y;
        if (d[na][b][1] < 0) {
          d[na][b][1] = d[a][b][0] + 1;
          pre[na][b][1] = make_pair(a, b);
          Q.push(make_pair(make_pair(a, b), 1));
        }
      }
    } else {
      for (int temp = head[b]; temp >= 0; temp = e[temp].next) {
        int nb = e[temp].y;
        if (a != nb && d[a][nb][0] < 0) {
          d[a][nb][0] = d[a][b][1];
          pre[a][nb][0] = make_pair(a, b);
          Q.push(make_pair(make_pair(a, b), 0));
        }
      }
    }
  }
  printf("%d\n", d[n][1][0]);
  if (d[n][1][0] >= 0) {
    pair<int, int> p = make_pair(n, 1);
    int topa = 0, topb = 0;
    while (d[p.first][p.second][0] > 0) {
      ansa[topa++] = p.first;
      ansb[topb++] = p.second;
      p = pre[p.first][p.second][0];
      p = pre[p.first][p.second][1];
    }
    printf("1");
    for (int i = topa - 1; i >= 0; i--) printf(" %d", ansa[i]);
    printf("\n%d", n);
    for (int i = topb - 1; i >= 0; i--) printf(" %d", ansb[i]);
    printf("\n");
  }
  return 0;
}
