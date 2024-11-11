#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct Segment_tree {
  int key[N * 50 + 5], ch[N * 50 + 5][2], pos, root[N + 5];
  int cpynode(int o) {
    ++pos;
    ch[pos][0] = ch[o][0], ch[pos][1] = ch[o][1], key[pos] = key[o];
    return pos;
  }
  void insert(int &o, int l, int r, int loc) {
    o = cpynode(o);
    ++key[o];
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (loc <= mid)
      insert(ch[o][0], l, mid, loc);
    else
      insert(ch[o][1], mid + 1, r, loc);
  }
  int query(int o, int l, int r, int loc) {
    if (!o || loc <= l) return key[o];
    int mid = (l + r) >> 1, c1 = 0, c2 = 0;
    if (loc <= mid) c1 = query(ch[o][0], l, mid, loc);
    c2 = query(ch[o][1], mid + 1, r, loc);
    return c1 + c2;
  }
} T;
int n, a;
long long ans;
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    ans += T.query(T.root[min(i - 1, a)], 1, n, i);
    T.insert(T.root[i] = T.root[i - 1], 1, n, min(a, n));
  }
  printf("%I64d\n", ans);
}
int main() {
  work();
  return 0;
}
