#include <bits/stdc++.h>
using namespace std;
struct NODE {
  int x, y;
  bool operator<(const struct NODE a) const {
    if (a.x == x) {
      return y < a.y;
    }
    return x < a.x;
  }
} nodes[200010];
int n;
int num[200010];
int sum[200010], bit[200010];
int lowbit(int x) { return x & (-x); }
void update(int pos, int val) {
  for (int i = pos; i <= n; i += lowbit(i)) {
    bit[i] += val;
  }
}
int query(int pos) {
  int sum = 0;
  for (int i = pos; i > 0; i -= lowbit(i)) {
    sum += bit[i];
  }
  return sum;
}
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &nodes[i].x);
      nodes[i].y = i;
    }
    sort(nodes + 1, nodes + 1 + n);
    for (int i = 1; i <= n;) {
      int temp = i;
      while (temp <= n && nodes[i].x == nodes[temp].x) {
        temp++;
      }
      for (int j = i; j < temp; j++) {
        for (int k = 1; k < n && k * (nodes[j].y - 1) + 2 <= n; k++) {
          sum[k] += query(min(k * nodes[j].y + 1, n)) -
                    query(k * (nodes[j].y - 1) + 1);
        }
      }
      for (int j = i; j < temp; j++) {
        update(nodes[i].y, 1);
      }
      i = temp;
    }
    for (int i = 1; i < n; i++) {
      printf("%d ", sum[i]);
    }
    printf("\n");
  }
  return 0;
}
