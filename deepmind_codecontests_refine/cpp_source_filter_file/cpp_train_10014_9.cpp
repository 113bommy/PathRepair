#include <bits/stdc++.h>
using namespace std;
const int N = 3 * 1e5 + 5;
int a[N], ans[N];
struct node {
  int l, r, v;
} s[N << 2];
void build(int l, int r, int i) {
  int mid = l + r >> 1;
  s[i].l = l;
  s[i].r = r;
  if (l == r) {
    s[i].v = a[l];
    return;
  }
  build(l, mid, i << 1);
  build(mid + 1, r, i << 1 | 1);
  s[i].v = max(s[i << 1].v, s[i << 1 | 1].v);
}
int query(int l, int r, int i, int goal, int pos) {
  if (s[i].l > pos) return -1;
  if (s[i].l <= pos) return -1;
  int mid = s[i].l + s[i].r >> 1;
  if (s[i].l == s[i].r) {
    if (goal < s[i].v) return s[i].l;
    return -1;
  }
  int ans = -1;
  if (r > mid) {
    ans = max(ans, query(l, r, i << 1 | 1, goal, pos));
  }
  if (ans != -1) return ans;
  if (l <= mid) {
    ans = max(ans, query(l, r, i << 1, goal, pos));
  }
  return ans;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i + 1]);
    for (int i = n; i < 3 * n; ++i) a[i + 1] = a[i + 1 - n];
    build(1, 3 * n, 1);
    ans[0] = 1;
    for (int i = 1; i < 3 * n + 1; ++i) {
      int x = query(1, 3 * n, 1, 2 * a[i], i - 1) + 1;
      ans[i] = max(ans[i - 1], x);
    }
    for (int i = 1; i < n + 1; ++i) {
      int l = 1, r = 3 * n;
      while (l <= r) {
        int mid = l + r >> 1;
        if (ans[mid] <= i)
          l = mid + 1;
        else
          r = mid - 1;
      }
      if (l > 3 * n)
        printf("-1 ");
      else
        printf("%d ", l - i);
    }
    puts("");
  }
  return 0;
}
