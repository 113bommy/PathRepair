#include <bits/stdc++.h>
const int maxn = 105, maxm = 6e4 + 5;
struct node {
  int a, b;
  bool operator<(const node a) const { return this->a + this->b >= a.a + a.b; }
} A[maxn], B[maxn];
int n, r, cnt_a, cnt_b, ans, f[maxm];
inline int max(int a, int b) { return a > b ? a : b; }
inline bool cmp(node a, node b) {
  if (a.a != b.a) return a.a < b.a;
  return a.b > b.b;
}
int main() {
  scanf("%d%d", &n, &r);
  for (int i = 1; i <= n; i++) {
    node tmp;
    scanf("%d%d", &tmp.a, &tmp.b);
    if (tmp.b >= 0)
      A[++cnt_a] = tmp;
    else
      B[++cnt_b] = tmp;
  }
  std::sort(A + 1, A + cnt_a + 1, cmp);
  std::sort(B + 1, B + cnt_b + 1);
  int len = 0;
  for (int i = 1; i <= cnt_a; i++) {
    if (r >= A[i].a) {
      r += A[i].b;
      len++;
    } else
      break;
  }
  for (int i = 1; i <= cnt_b; i++) {
    for (int j = max(-B[i].b, B[i].a); j <= r; j++) {
      f[j + B[i].b] = max(f[j] + 1, f[j + B[i].b]);
      ans = max(ans, f[j + B[i].b]);
    }
  }
  printf("%d\n", len + ans);
  return 0;
}
