#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, q;
int bit[MAXN];
void update(int x, int value) {
  while (x <= n) {
    bit[x] += value;
    x += x & -x;
  }
}
int get(int x) {
  int ret = 0;
  while (x > 0) {
    ret += bit[x];
    x -= x & -x;
  }
  return ret;
}
int get(int start, int end) { return get(end) - get(start - 1); }
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i <= n; ++i) bit[i] = 0;
  for (int i = 1; i <= n; ++i) update(i, 1);
  bool upward = 1;
  int sz = n, init = 1;
  for (int i = 0; i < q; ++i) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int p;
      scanf("%d", &p);
      if (!upward) {
        p = sz - p;
      }
      if (p + p <= sz) {
        int front, back;
        for (front = init + p, back = front - 1; front < init + p + p;
             ++front, --back) {
          int w = get(back, back);
          update(back, -w);
          update(front, w);
        }
        init += p;
        sz -= p;
        if (!upward) {
          upward = true;
        }
      } else {
        int front, back;
        for (front = init + p, back = front - 1; front < init + sz;
             ++front, --back) {
          int w = get(front, front);
          update(front, -w);
          update(back, w);
        }
        sz = p;
        if (upward) {
          upward = false;
        }
      }
    } else {
      int start, end;
      scanf("%d%d", &start, &end);
      ++start;
      if (!upward) {
        start = sz - start + 1;
        end = sz - end + 1;
        swap(start, end);
      }
      printf("%d\n", get(init + start - 1, init + end - 1));
    }
  }
  return 0;
}
