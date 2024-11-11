#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
const int maxm = 1e6 + 50;
const double eps = 1e-10;
const int max_index = 62;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
inline int read() {
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  int x = 0;
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
long long sum[maxn << 2];
int col[maxn << 2], dis[maxn << 2];
void pushup(int id) {
  sum[id] = sum[id << 1] + sum[id << 1 | 1];
  if (col[id << 1] == col[id << 1 | 1])
    col[id] = col[id << 1];
  else
    col[id] = -1;
}
void pushdown(int id, int l, int r) {
  if (col[id] != -1) {
    int mid = l + r >> 1;
    col[id << 1] = col[id << 1 | 1] = col[id];
    dis[id << 1] += dis[id];
    dis[id << 1 | 1] += dis[id];
    sum[id << 1] += (mid - l + 1) * dis[id];
    sum[id << 1 | 1] += (r - mid) * dis[id];
    dis[id] = 0;
    col[id] = -1;
  }
}
void build(int id, int l, int r) {
  sum[id] = 0;
  col[id] = -1;
  if (l == r) {
    col[id] = l;
    return;
  }
  int mid = l + r >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  pushup(id);
}
void update(int id, int l, int r, int L, int R, int val) {
  if (L <= l && r <= R) {
    if (col[id] != -1) {
      sum[id] += 1LL * abs(val - col[id]) * (r - l + 1);
      dis[id] += abs(val - col[id]);
      col[id] = val;
      return;
    }
  }
  pushdown(id, l, r);
  int mid = l + r >> 1;
  if (mid >= L) update(id << 1, l, mid, L, R, val);
  if (mid < R) update(id << 1 | 1, mid + 1, r, L, R, val);
  pushup(id);
}
long long query(int id, int l, int r, int L, int R) {
  if (L <= l && r <= R) return sum[id];
  pushdown(id, l, r);
  long long res = 0;
  int mid = l + r >> 1;
  if (mid >= L) res += query(id << 1, l, mid, L, R);
  if (mid < R) res += query(id << 1 | 1, mid + 1, r, L, R);
  return res;
}
int main() {
  int n = read(), m = read();
  build(1, 1, n);
  while (m--) {
    int op = read();
    if (op == 1) {
      int l = read(), r = read(), val = read();
      update(1, 1, n, l, r, val);
    } else {
      int l = read(), r = read();
      printf("%I64d\n", query(1, 1, n, l, r));
    }
  }
  return 0;
}
