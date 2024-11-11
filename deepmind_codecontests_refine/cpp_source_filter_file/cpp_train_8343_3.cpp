#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct Node {
  int l, r;
  long long val;
  long long add;
  int mid() { return (l + r) >> 1; }
  void work(int d) {
    val += d;
    add += d;
  }
} T[N * 4];
void build(int u, int l, int r) {
  T[u].l = l, T[u].r = r;
  T[u].val = T[u].add = 0;
  if (l == r) {
    return;
  }
  int mid = T[u].mid();
  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
}
inline void down(int u) {
  if (T[u].add) {
    T[u << 1].work(T[u].add);
    T[u << 1 | 1].work(T[u].add);
    T[u].add = 0;
  }
}
void modify(int u, int begin, int end, long long d) {
  if (T[u].l == begin && T[u].r == end) {
    T[u].work(d);
    return;
  }
  down(u);
  int mid = T[u].mid();
  if (end <= mid) {
    modify(u << 1, begin, end, d);
  } else if (begin > mid) {
    modify(u << 1 | 1, begin, end, d);
  } else {
    modify(u << 1, begin, mid, d);
    modify(u << 1 | 1, mid + 1, end, d);
  }
  T[u].val = max(T[u << 1].val, T[u << 1 | 1].val);
}
struct Point {
  int x, y, s;
  bool operator<(const Point &p) const { return y < p.y; }
};
int cost[N];
vector<Point> M;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%d", &cost[i]);
  }
  M.resize(m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &M[i].x, &M[i].y, &M[i].s);
    M[i].x--, M[i].y--;
  }
  sort(M.begin(), M.end());
  build(1, 0, n);
  long long ans = 0;
  for (int i = 0, k = 0; i < n; i++) {
    modify(1, 0, i, -cost[i]);
    while (k < m && M[k].y == i) {
      modify(1, 0, M[k].x, M[k].s);
      k++;
    }
    ans = max(ans, T[1].val);
    modify(1, i + 1, i + 1, ans);
  }
  cout << ans << endl;
}
