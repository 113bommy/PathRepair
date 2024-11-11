#include <bits/stdc++.h>
const int N = 1048576;
struct Tree {
  int val[N * 2];
  void init(int n);
  void set(int i, int v);
  int get(int v);
};
void Tree::init(int n) {
  memset(val, 0, sizeof val);
  for (int i = 0; i < n; i++) val[N + i] = 1;
  for (int i = N - 1; i > 0; i--) val[i] = val[i + i] + val[i + i + 1];
}
void Tree::set(int i, int v) {
  val[N + i] = v;
  for (i = (N + i) / 2; i > 0; i /= 2) val[i] = val[i + i] + val[i + i + 1];
}
int Tree::get(int v) {
  int cur = 1;
  while (cur < N) {
    cur *= 2;
    if (v >= val[cur]) v -= val[cur++];
  }
  return cur - N;
}
Tree left, right;
int ans[N];
int mov[N];
int use[N];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) ans[i] = -1, use[i] = 0;
  right.init(n);
  left.init(0);
  int k = 0, p = 0;
  for (int op = 0; op < m; op++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    if (y >= p) {
      if (use[x]) {
        printf("-1");
        return 0;
      }
      use[x] = 1;
      int pos = right.get(y - p++);
      right.set(pos, 0);
      ans[pos] = x;
      left.set(k, 1);
      mov[k++] = x;
    } else {
      int pos = left.get(p - y - 1);
      if (mov[pos] != x) {
        printf("-1");
        return 0;
      }
      left.set(pos, 0);
      left.set(k, 1);
      mov[k++] = x;
    }
  }
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (ans[i] < 0) {
      while (use[cur]) cur++;
      ans[i] = cur++;
    }
    printf("%d ", ans[i] + 1);
  }
  return 0;
}
