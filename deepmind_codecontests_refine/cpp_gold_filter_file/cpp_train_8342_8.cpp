#include <bits/stdc++.h>
struct data {
  int value, l, r;
  data() {}
  data(int value, int l, int r) {
    this->value = value;
    this->l = l;
    this->r = r;
  }
  bool operator<(const data &a) {
    if (value != a.value) return value < a.value;
    if (r != a.r) return r < a.r;
    return false;
  }
};
const int LN = 1508;
data p[LN * LN];
int a[LN];
int pre[LN];
int f[LN];
int g[LN];
int n, m;
int sz;
data res[LN];
template <typename T>
void swap(T &a, T &b) {
  T c = a;
  a = b;
  b = c;
}
void sort(int l, int r) {
  data key = p[(l + r) >> 1];
  int i = l, j = r;
  while (i <= j) {
    while (p[i] < key) i++;
    while (key < p[j]) j--;
    if (i <= j) {
      swap(p[i], p[j]);
      i++;
      j--;
    }
  }
  if (l < j) sort(l, j);
  if (i < r) sort(i, r);
}
int Find(int x, int l, int r) {
  int res = -1;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (p[m].r < x) {
      res = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int m = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += a[j];
      p[m++] = data(sum, i, j);
    }
  }
  sort(0, m - 1);
  int j = 0;
  for (int i = 0; i < m; i++) {
    if (i + 1 == m || p[i].value < p[i + 1].value) {
      for (int k = j; k <= i; k++) {
        f[k - j] = 1;
        pre[k - j] = -1;
        g[k - j] = k - j;
        int x = Find(p[k].l, j, k - 1);
        if (x != -1 && f[k - j] < f[x - j] + 1) {
          f[k - j] = f[x - j] + 1;
          pre[k - j] = g[x - j];
        }
        if (k > j && f[k - j] < f[k - j - 1]) {
          f[k - j] = f[k - j - 1];
          g[k - j] = g[k - j - 1];
          pre[k - j] = pre[k - j - 1];
        }
      }
      if (f[i - j] > sz) {
        sz = f[i - j];
        int t = g[i - j];
        int len = sz;
        while (len--) {
          res[len] = p[t + j];
          t = pre[t];
        }
      }
      j = i + 1;
    }
  }
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    printf("%d %d\n", res[i].l + 1, res[i].r + 1);
  }
}
