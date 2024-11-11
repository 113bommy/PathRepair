#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N], m[2 * N], lz[2 * N] = {0};
void build(int i, int s, int e) {
  if (s > e) return;
  if (s == e) {
    m[i] = a[s];
    return;
  }
  int q = (s + e) >> 1;
  build(2 * i + 1, s, q);
  build(2 * i + 2, q + 1, e);
  m[i] = min(m[2 * i + 1], m[2 * i + 2]);
}
void push(int i, int s, int e) {
  if (lz[i]) {
    m[i] += lz[i];
    if (s != e) {
      lz[2 * i + 1] += lz[i];
      lz[2 * i + 2] += lz[i];
    }
    lz[i] = 0;
  }
}
void update(int i, int s, int e, int l, int r, int v) {
  push(i, s, e);
  if (s > e || s > r || e < l) return;
  if (s >= l && e <= r) {
    m[i] += v;
    if (s != e) {
      lz[2 * i + 1] += v;
      lz[2 * i + 2] += v;
    }
    return;
  }
  int q = (s + e) / 2;
  update(2 * i + 1, s, q, l, r, v);
  update(2 * i + 2, q + 1, e, l, r, v);
  m[i] = min(m[2 * i + 1], m[2 * i + 2]);
}
int get(int i, int s, int e, int l, int r) {
  if (s > e || s > r || e < l) return INT_MAX;
  push(i, s, e);
  if (s >= l && e <= r) return m[i];
  int q = (s + e) / 2;
  return min(get(2 * i + 1, s, q, l, r), get(2 * i + 2, q + 1, e, l, r));
}
void printM(int n) {
  for (int i = 0; i < 2 * n; i++) printf("%d %d\n", i, m[i]);
  printf("\n");
}
int main() {
  int n, Q, l, r, v;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  build(0, 0, n - 1);
  char ch;
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d %d%c", &l, &r, &ch);
    if (ch != '\n') {
      scanf("%d", &v);
      if (r >= l)
        update(0, 0, n - 1, l, r, v);
      else {
        update(0, 0, n - 1, 0, r, v);
        update(0, 0, n - 1, l, n - 1, v);
      }
    } else {
      if (r >= l)
        printf("%d\n", get(0, 0, n - 1, l, r));
      else
        printf("%d\n", min(get(0, 0, n - 1, 0, r), get(0, 0, n - 1, l, n - 1)));
    }
  }
  return 0;
}
