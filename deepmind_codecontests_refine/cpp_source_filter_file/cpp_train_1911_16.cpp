#include <bits/stdc++.h>
using namespace std;
int n, A[250005], f[20][250005], g[20][250005];
int solve(int tar, int a) {
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) >> 1, d = 0, w = a;
    for (int i = 0; i <= 20; i++)
      if (mid & 1 << i) {
        d = min(d + g[i][w], n);
        w = f[i][w];
      }
    if (d == n)
      r = mid - 1;
    else {
      int dis = (w - tar + n) % n;
      if (dis <= A[w])
        r = mid;
      else
        l = mid + 1;
    }
  }
  return l + 1;
}
struct node {
  pair<int, int> minn;
  node() { minn = make_pair(0x3f3f3f3f, 0x3f3f3f3f); }
} S[250005 << 2];
void Insert(int q, int l, int r, int k, pair<int, int> s) {
  S[q].minn = min(S[q].minn, s);
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (k <= mid)
    Insert(q << 1, l, mid, k, s);
  else
    Insert(q << 1 | 1, mid + 1, r, k, s);
}
pair<int, int> Query(int q, int l, int r, int L, int R) {
  if (L > R) return make_pair(0x3f3f3f3f, 0x3f3f3f3f);
  if (l == L && r == R) return S[q].minn;
  int mid = (l + r) >> 1;
  if (R <= mid) return Query(q << 1, l, mid, L, R);
  if (L > mid) return Query(q << 1 | 1, mid + 1, r, L, R);
  return min(Query(q << 1, l, mid, L, mid),
             Query(q << 1 | 1, mid + 1, r, mid + 1, R));
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    Insert(1, 0, n - 1, i, make_pair(i - A[i], i));
  }
  for (int i = 0; i < n; i++) {
    if (A[i] <= i) {
      int fa = Query(1, 0, n - 1, i - A[i], i - 1).second;
      f[0][i] = fa;
      g[0][i] = i - fa;
    } else {
      pair<int, int> fa1 = Query(1, 0, n - 1, 0, i - 1);
      pair<int, int> fa2 = Query(1, 0, n - 1, max(i + 1, i - A[i] + n), n - 1);
      fa2.first -= n;
      fa2.second -= n;
      fa1 = min(fa1, fa2);
      f[0][i] = (n + fa1.second) % n;
      g[0][i] = i - fa1.second;
    }
  }
  for (int i = 1; i <= 20; i++)
    for (int j = 0; j < n; j++) {
      f[i][j] = f[i - 1][f[i - 1][j]];
      g[i][j] = min(n, g[i - 1][j] + g[i - 1][f[i - 1][j]]);
    }
  long long ans = 0;
  for (int i = 0; i < n; i++) ans += solve((i + 1) % n, i);
  printf("%I64d\n", ans);
}
