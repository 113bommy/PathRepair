#include <bits/stdc++.h>
long long seq[1000005];
long long sum[1000005];
int bsearch(int, int, int, int, int);
int main() {
  int A, B, n, l, t, m;
  scanf("%d %d %d", &A, &B, &n);
  seq[1] = A;
  sum[1] = seq[1];
  for (int i = 2; i <= 1000000; i++) {
    seq[i] = seq[i - 1] + B;
    sum[i] = sum[i - 1] + seq[i];
  }
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &l, &t, &m);
    int ans = bsearch(l, l, 1000000, t, m) - 1;
    if (ans < l) {
      printf("-1\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
int bsearch(int inl, int l, int r, int t, int m) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (seq[mid] <= t && sum[mid] - sum[inl - 1] <= (long long)m * t) {
    return bsearch(inl, mid + 1, r, t, m);
  } else {
    return bsearch(inl, l, mid, t, m);
  }
}
