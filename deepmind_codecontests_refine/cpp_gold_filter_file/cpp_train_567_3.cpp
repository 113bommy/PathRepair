#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 * 1000 + 10;
long long h[MAXN], d[MAXN];
struct node {
  long long l, r, all;
  long long sum;
  node(){};
  node(long long l, long long r, long long all, long long sum)
      : l(l), r(r), all(all), sum(sum){};
};
node up(node a, node b) {
  return node(max(b.sum + a.l, b.l), max(a.sum + b.r, a.r),
              max(max(a.all, b.all), a.l + b.r), a.sum + b.sum);
}
class tree {
 public:
  vector<node> a;
  int len;
  void build(int n) {
    for (len = 1; len < n; len *= 2)
      ;
    a.assign(2 * len, node(0, 0, 0, 0));
    for (int i = 0; i < n; i++)
      a[i + len] = node(d[i] + 2 * h[i], d[i] + 2 * h[i + 1],
                        d[i] + 2 * h[i] + 2 * h[i + 1], d[i]);
    for (int i = len - 1; i > 0; i--) a[i] = up(a[2 * i], a[2 * i + 1]);
  }
  node find(int tl, int tr, int v, int l, int r) {
    if (tl > tr) return node(0, 0, 0, 0);
    if (tl == l && tr == r) return a[v];
    int s = (l + r) / 2;
    return up(find(tl, min(s, tr), 2 * v, l, s),
              find(max(s + 1, tl), tr, 2 * v + 1, s + 1, r));
  }
};
tree t;
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> d[i];
  for (int i = 0; i < n; i++) cin >> h[i];
  for (int i = n; i < 2 * n; i++) d[i] = d[i - n], h[i] = h[i - n];
  n *= 2;
  n--;
  t.build(n);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    if (l <= r) {
      l--, r -= 2;
      r += 2;
      l += (n + 1) / 2 - 2;
      swap(l, r);
    } else {
      l -= 2, r--;
      r++, l--;
      swap(l, r);
    }
    int len = t.len;
    node cur = t.find(l + len, r + len, 1, len, len * 2 - 1);
    cout << cur.all << '\n';
  }
  return 0;
}
