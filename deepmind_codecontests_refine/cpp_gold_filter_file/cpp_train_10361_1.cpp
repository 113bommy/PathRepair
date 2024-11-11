#include <bits/stdc++.h>
using namespace std;
void task();
int main() {
  task();
  return 0;
}
const int N = (int)1e5 + 10;
const long long int MOD = (long long int)1e9 + 7;
const int INF = 1 << 30;
const long long int LINF = (long long int)8e18 + 100;
const int BUF_SIZE = (int)1e5 + 10;
bool d;
struct SegTree {
  long long int tree[4 * N];
  SegTree() { memset(tree, 0, sizeof(tree)); }
  void setElement(int v, int l, int r, int pos, long long int val) {
    if (l > r) return;
    if (l == pos && r == pos) {
      tree[v] = val;
      return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
      setElement(2 * v, l, mid, pos, val);
    else
      setElement(2 * v + 1, mid + 1, r, pos, val);
    tree[v] = max(tree[2 * v], tree[2 * v + 1]);
  }
  long long int getMax(int v, int l, int r, int ql, int qr) {
    if (l > r || ql > qr) {
      return 0;
    }
    if (l == ql && r == qr) {
      return tree[v];
    }
    int mid = (l + r) / 2;
    return max(getMax(2 * v, l, mid, ql, min(mid, qr)),
               getMax(2 * v + 1, mid + 1, r, max(mid + 1, ql), qr));
  }
};
long long int a[N];
int ind[N];
SegTree tree;
map<long long int, int> has;
void task() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; ++i) {
    int rad, l;
    scanf("%d %d", &rad, &l);
    a[i] = rad * (long long int)rad * l;
  }
  for (int i = 1; i < n + 1; ++i) has[a[i]] = 1;
  int num = 1;
  for (auto& x : has) x.second = num++;
  for (int i = 1; i < n + 1; ++i) {
    ind[i] = has[a[i]];
  }
  for (int i = 1; i < n + 1; ++i) {
    int index = ind[i];
    long long int res = tree.getMax(1, 1, n, 1, index - 1) + a[i];
    (void(1));
    ;
    tree.setElement(1, 1, n, index, res);
  }
  printf("%.12f", tree.getMax(1, 1, n, 1, n) * acos(-1.0));
}
