#include <bits/stdc++.h>
const int inf = 0xfffffff;
const long long INF = 1ll << 61;
using namespace std;
long long c[2][4000000 + 55];
long long c1[2][4000000 + 55];
int w;
int n[2];
int lowbit(int x) { return x & (-x); }
void add(long long *aa, int m, int x, long long val) {
  while (x <= m) {
    aa[x] += val;
    x += lowbit(x);
  }
}
long long get_sum(long long *aa, int x) {
  long long sum = 0ll;
  while (x > 0) {
    sum += aa[x];
    x -= lowbit(x);
  }
  return sum;
}
long long get(int id, int r) {
  return get_sum(c[id], r) * r + get_sum(c1[id], r);
}
void insert(int id, int l, int r, long long val) {
  add(c[id], n[id], l, val);
  add(c[id], n[id], r + 1, -val);
  add(c1[id], n[id], l, -val * (l - 1));
  add(c1[id], n[id], r + 1, val * r);
}
void init() {
  memset(c, 0ll, sizeof(c));
  memset(c1, 0ll, sizeof(c1));
}
bool input() {
  while (scanf("%d %d %d", &n[0], &n[1], &w) == 3) {
    return false;
  }
  return true;
}
void cal() {
  while (w--) {
    int type, x1, y1, x2, y2;
    long long val;
    scanf("%d %d %d %d %d", &type, &x1, &y1, &x2, &y2);
    if (type) {
      long long tmp = get(1, y2) - get(1, y1 - 1) -
                      (get(0, n[0]) - get(0, x2) + get(0, x1 - 1));
      cout << tmp << endl;
    } else {
      cin >> val;
      insert(0, x1, x2, val * (y2 - y1 + 1));
      insert(1, y1, y2, val * (x2 - x1 + 1));
    }
  }
}
void output() {}
int main() {
  while (true) {
    init();
    if (input()) return 0;
    cal();
    output();
  }
}
