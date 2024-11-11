#include <bits/stdc++.h>
const int N = 400050;
int l[N], r[N], num[N], nk;
int n, tot;
int id(int v) {
  int L = 1, R = nk, mid;
  while (L <= R) {
    mid = (L + R) / 2;
    if (num[mid] == v) return mid;
    if (num[mid] < v)
      L = mid + 1;
    else
      R = mid - 1;
  }
}
int first[2 * N], to[4 * N], next[4 * N], real[4 * N], size;
int d[2 * N];
void put(int x, int y, int rr) {
  next[++size] = first[x];
  to[first[x] = size] = y;
  real[size] = rr;
  d[x]++;
}
int ans[2 * N], V[2 * N];
void dfs(int v) {
  for (int &k = first[v]; k; k = next[k])
    if (!ans[real[k]]) {
      if (v < to[k])
        ans[real[k]] = 1;
      else
        ans[real[k]] = -1;
      dfs(to[k]);
    }
  V[v] = 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
  for (int i = 1; i <= n; i++)
    num[i] = l[i] = l[i] * 2, num[i + n] = r[i] = r[i] * 2 + 1;
  std::sort(num + 1, num + 2 * n + 1);
  num[0] = -1;
  for (int i = 1; i <= 2 * n; i++)
    if (num[i] != num[i - 1]) num[++nk] = num[i];
  for (int i = 1; i <= n; i++) l[i] = id(l[i]), r[i] = id(r[i]);
  for (int i = 1; i <= n; i++) {
    put(l[i], r[i], ++tot);
    put(r[i], l[i], tot);
  }
  printf("\n");
  for (int i = 1, t = 0, last = 0; i <= nk + 1; i++) {
    if (d[i] & 1) {
      t ^= 1;
      if (!t) put(i, last, ++tot), put(last, i, tot);
      last = i;
    }
  }
  for (int i = 1; i <= nk + 1; i++) dfs(i);
  for (int i = 1; i <= n; i++) {
    if (ans[i] + 1)
      printf("1 ");
    else
      printf("0 ");
  }
}
