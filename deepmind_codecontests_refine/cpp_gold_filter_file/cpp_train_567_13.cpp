#include <bits/stdc++.h>
using namespace std;
struct S {
  long long left = 0;
  long long right = 0;
  long long best = 0;
};
const int N = 1 << 18;
const int MN = 2e5 + 100;
S st[2 * N];
long long d[2 * N];
long long h[2 * N];
long long distSum[2 * N];
void f(long long k, long long l, long long r) {
  if (l < r) {
    long long mid = (l + r) / 2;
    f(k * 2, l, mid);
    f(k * 2 + 1, mid + 1, r);
    st[k].best = max(st[k * 2].best, st[k * 2 + 1].best);
    st[k].best = max(st[k].best, st[k * 2].left + st[k * 2 + 1].right);
    st[k].left = max(st[k * 2 + 1].left,
                     st[k * 2].left + distSum[r + 1] - distSum[mid + 1]);
    st[k].right = max(st[k * 2].right,
                      st[k * 2 + 1].right + distSum[mid + 1] - distSum[l]);
  }
}
S f2(long long k, long long l, long long r, long long x, long long y) {
  if (l > y || r < x) return st[0];
  if (l >= x && r <= y) {
    return st[k];
  }
  long long mid = (l + r) / 2;
  S q = f2(k * 2, l, mid, x, y);
  S w = f2(k * 2 + 1, mid + 1, r, x, y);
  S ret;
  ret.best = max(q.best, w.best);
  ret.best = max(ret.best, q.left + w.right);
  ret.left = max(w.left, q.left + distSum[r + 1] - distSum[mid + 1]);
  ret.right = max(q.right, w.right + distSum[mid + 1] - distSum[l]);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  st[0].best = -1e18;
  st[0].left = -1e18;
  st[0].right = -1e18;
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
    d[i + n] = d[i];
  }
  for (int i = 1; i < 2 * N; ++i) {
    distSum[i] = d[i - 1] + distSum[i - 1];
  }
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    h[i + n] = h[i];
  }
  for (int i = 0; i < 2 * n; ++i) {
    st[i + N].left = h[i] * 2 + d[i];
    st[i + N].right = h[i] * 2;
  }
  f(1, 0, N - 1);
  for (int i = 0; i < m; ++i) {
    int q, w;
    cin >> w >> q;
    --q, --w;
    if (w <= q) w += n;
    cout << f2(1, 0, N - 1, q + 1, w - 1).best << '\n';
  }
}
