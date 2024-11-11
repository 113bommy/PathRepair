#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 6.66;
const int MAXQ = 2e5 + 6.66;
vector<int> rooksx[MAXN];
vector<int> rooksy[MAXN];
struct Que {
  int x;
  int y1, y2;
  int cn;
};
vector<Que> quex[MAXN];
vector<Que> quey[MAXN];
bool ans[MAXQ];
struct Segment {
  int seg[200006];
  int n;
  Segment(int n = 1e5) : n(n) { memset(seg, 0, sizeof seg); }
  Segment(int *arr, int n = 1e5) : n(n) {
    memset(seg, 0, sizeof seg);
    build(arr);
  }
  void build(int *arr) {
    for (int i = n; i < 2 * n; i++) seg[i] = arr[i - n];
    for (int i = n - 1; i > 0; i--) seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
  }
  void alter(int x, int val) {
    for (seg[x += n] = val; x > 1; x >>= 1)
      seg[x >> 1] = min(seg[x], seg[x ^ 1]);
  }
  int get(int l, int r) {
    int ans = 1e9 + 7;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans = min(ans, seg[l++]);
      if (r & 1) ans = min(ans, seg[--r]);
    }
    return ans;
  }
};
void solve(int n, int m, vector<int> V[], vector<Que> qq[]) {
  Segment seg = Segment(m + 3);
  for (int i = 0; i <= n; i++) {
    for (auto w : V[i]) seg.alter(w, i);
    for (auto q : qq[i]) {
      int ww = seg.get(q.y1, q.y2);
      ans[q.cn] |= ww >= q.x;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    rooksx[x].push_back(y);
    rooksy[y].push_back(x);
  }
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    quex[x2].push_back({x1, y1, y2, i});
    quey[y2].push_back({y1, x1, x2, i});
  }
  solve(n, m, rooksx, quex);
  solve(m, n, rooksy, quey);
  for (int i = 0; i < q; i++) cout << (ans[i] ? "YES" : "NO") << endl;
  return 0;
}
