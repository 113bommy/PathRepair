#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
  int v;
} node1[200005], node2[200005];
bool cmp1(const Point &a, const Point &b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cmp2(const Point &a, const Point &b) { return a.y < b.y; }
int main() {
  int n;
  long long ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &node1[i].x, &node1[i].y);
  sort(node1, node1 + n, cmp1);
  int cnt = 1, h = 0, k = 0;
  node2[0] = node1[0];
  for (int i = 1; i < n; i++) {
    if (node1[i].x != node1[i - 1].x || node1[i].y != node1[i - 1].y) {
      node2[cnt - 1].v = i - k;
      node2[cnt++] = node1[i];
      k = i;
    }
    if (node1[i].x != node1[i - 1].x) {
      ans += (long long)(i - h) * (i - h - 1) / 2;
      h = i;
    }
  }
  node2[cnt - 1].v = n - k;
  ans += (long long)(n - h) * (n - h - 1) / 2;
  sort(node2, node2 + cnt, cmp2);
  h = 0;
  int maxs = node2[0].v;
  for (int i = 1; i < cnt; i++) {
    maxs += node2[i].v;
    if (node2[i].y != node2[i - 1].y) {
      maxs -= node2[i].v;
      for (int j = h; j < i; j++) {
        maxs -= node2[j].v;
        ans += (long long)maxs * node2[j].v;
      }
      maxs = node2[i].v;
      h = i;
    }
  }
  for (int j = h; j < cnt; j++) {
    maxs -= node2[j].v;
    ans += (long long)maxs * node2[j].v;
  }
  printf("%d\n", ans);
  return 0;
}
