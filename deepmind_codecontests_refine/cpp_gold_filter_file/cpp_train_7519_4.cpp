#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
struct node {
  int a, b, c;
};
bool operator<(const node &x, const node &y) { return x.a > y.a; }
priority_queue<node> pq;
int road[10002][1002];
int ara[10005];
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &ara[i]);
  sort(ara + 1, ara + 1 + m);
  int g, r;
  scanf("%d", &g);
  scanf("%d", &r);
  node k;
  k.a = 1;
  k.b = 1;
  k.c = 0;
  pq.push(k);
  int ans = -1;
  road[0][0] = 1;
  while (!pq.empty()) {
    node tmp = pq.top();
    pq.pop();
    if (tmp.b == m) {
      ans = (tmp.a);
      break;
    }
    if (tmp.b >= 2) {
      int now = tmp.c + (ara[tmp.b] - ara[tmp.b - 1]);
      if (now <= g) {
        int tot = (tmp.a) + (ara[tmp.b] - ara[tmp.b - 1]);
        if (now == g) {
          now %= g;
          tot += r;
        }
        if (road[tmp.b - 1][now] == 0 || road[tmp.b - 1][now] > tot) {
          road[tmp.b - 1][now] = tot;
          k.a = (tot);
          k.b = tmp.b - 1;
          k.c = now;
          pq.push(k);
        }
      }
    }
    if (tmp.b < m) {
      int now = tmp.c + ara[tmp.b + 1] - ara[tmp.b];
      if (now <= g) {
        int tot = (tmp.a) + (ara[tmp.b + 1] - ara[tmp.b]);
        if (ara[tmp.b + 1] != n && now == g) {
          now %= g;
          tot += r;
        }
        if (road[tmp.b + 1][now] > tot || road[tmp.b + 1][now] == 0) {
          road[tmp.b + 1][now] = tot;
          k.a = (tot);
          k.b = tmp.b + 1;
          k.c = now;
          pq.push(k);
        }
      }
    }
  }
  if (ans == -1)
    printf("-1\n");
  else {
    printf("%d\n", ans - 1);
  }
}
