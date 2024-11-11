#include <bits/stdc++.h>
int a[100005], n, max, bi[50], k, i, j, ans, p;
bool bj;
template <class T>
void up(T& a, T b) {
  if (a < b) a = b;
}
template <class T>
void down(T& a, T b) {
  if (a > b) a = b;
}
void work1(int l, int r) {
  if (l == 0) return;
  int max = 0;
  for (int i = l + 1; i <= r; i++) up(max, a[i]), up(ans, a[l] ^ max);
}
void work2(int l, int r) {
  int max = 0;
  for (int i = r - 1; i >= l; i--) up(max, a[i]), up(ans, a[r] ^ max);
}
int main() {
  scanf("%d", &n);
  for (bi[0] = i = 1; i <= 31; i++) bi[i] = bi[i - 1] << 1;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]), up(max, a[i]);
  for (k = 30; (max & bi[k]) == 0; k--)
    ;
  for (; !bj && k >= 0; k--) {
    p = 0;
    for (i = 1; i <= n; i++)
      if ((a[i] & bi[k]) != 0) {
        if (p != i - 1) work1(p, i - 1), work2(p + 1, i), bj = 1;
        p = i;
      }
    if (p != n && p != 0) work1(p, n), bj = 1;
  }
  printf("%d", ans);
  return 0;
}
