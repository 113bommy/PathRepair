#include <bits/stdc++.h>
int a[100001];
int b[100001];
int sum[100001];
int n, m, c;
inline int max(int x, int y) {
  if (x > y) return x;
  return y;
}
inline int min(int x, int y) {
  if (x < y) return x;
  return y;
}
inline int get(int a, int b) { return sum[b] - sum[a - 1]; }
inline int beg(int i) {
  if (n - i >= m)
    return 1;
  else
    return m - n + i;
}
int main() {
  scanf("%d %d %d", &n, &m, &c);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= m; i++) {
    sum[i] = sum[i - 1] + b[i];
  }
  for (int i = 1; i <= n; i++) {
    a[i] = (a[i] + get(beg(i), min(m, i))) % c;
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
