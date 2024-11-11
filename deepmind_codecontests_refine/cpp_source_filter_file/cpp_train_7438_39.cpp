#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
  int dis;
} q[100000];
int n, r;
int tail = 0;
int dis(node a, node b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool cmp(node a, node b) { return a.dis > b.dis; }
int ans = 0;
int id[100];
int ansid[100];
void gao(int now, int pre, int sum) {
  if (now == n) {
    if (ans < sum) {
      ans = sum;
      for (int j = 0; j < now; ++j) ansid[j] = id[j];
    }
    return;
  }
  for (int i = pre; i < tail; ++i) {
    int tmp = 0;
    for (int j = 0; j < now; ++j) tmp += dis(q[id[j]], q[i]);
    id[now] = i;
    gao(now + 1, i, sum + tmp);
  }
}
int main() {
  scanf("%d%d", &n, &r);
  for (int i = -r; i <= r; ++i)
    for (int j = -r; j <= r; ++j)
      if (i * i + j * j <= r * r) {
        q[tail].x = i;
        q[tail].y = j;
        q[tail++].dis = i * i + j * j;
      }
  sort(q, q + tail, cmp);
  if (tail > 12) tail = 12;
  gao(0, 0, 0);
  printf("%d\n", ans);
  for (int i = 0; i < n; ++i) printf("%d %d\n", q[ansid[i]].x, q[ansid[i]].y);
}
