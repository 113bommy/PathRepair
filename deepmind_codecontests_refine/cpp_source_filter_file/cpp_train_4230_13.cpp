#include <bits/stdc++.h>
void intIntSort(int d[], int m[], int s) {
  int i = -1, j = s, k, t;
  if (s <= 1) return;
  k = (d[0] + d[s - 1]) / 2;
  for (;;) {
    while (d[++i] < k)
      ;
    while (d[--j] > k)
      ;
    if (i >= j) break;
    t = d[i];
    d[i] = d[j];
    d[j] = t;
    t = m[i];
    m[i] = m[j];
    m[j] = t;
  }
  intIntSort(d, m, i);
  intIntSort(d + j + 1, m + j + 1, s - j - 1);
}
int n, qs;
int q[200000], q_ind[200000];
int root;
int left[200000], right[200000], up[200000], num[200000];
double sum[200000], per[200000];
int mi[200000], mx[200000];
int mx_node[200000], mn_node[200000];
int res_size;
double res[200000];
void pre_cal(int node) {
  if (left[node] == -1) {
    mx_node[node] = mn_node[node] = num[node];
    return;
  }
  pre_cal(left[node]);
  pre_cal(right[node]);
  mn_node[node] = mn_node[left[node]];
  mx_node[node] = mx_node[right[node]];
}
void solve(int node) {
  int i, j, k;
  int nx;
  if (left[node] == -1) {
    while (res_size < qs && mi[node] <= q[res_size] &&
           q[res_size] <= mx[node]) {
      res[q_ind[res_size]] = sum[node] / per[node];
      res_size++;
    }
    return;
  }
  nx = left[node];
  mi[nx] = mi[node];
  mx[nx] = num[node] - 1;
  sum[nx] = sum[node] + mn_node[right[node]];
  per[nx] = per[node] + 1;
  solve(nx);
  nx = right[node];
  mi[nx] = num[node] + 1;
  mx[nx] = mx[node];
  sum[nx] = sum[node] + mx_node[left[node]];
  per[nx] = per[node] + 1;
  solve(nx);
}
int main() {
  int i, j, k, l, m;
  while (scanf("%d", &n) == 1) {
    for (i = 0; i < n; i++) scanf("%d%d", up + i, num + i), up[i]--;
    scanf("%d", &qs);
    for (i = 0; i < qs; i++) scanf("%d", q + i);
    for (i = 0; i < n; i++) left[i] = right[i] = -1;
    for (i = 0; i < n; i++) {
      if (up[i] < 0) {
        root = i;
        continue;
      }
      if (num[i] < num[up[i]]) left[up[i]] = i;
      if (num[i] > num[up[i]]) right[up[i]] = i;
    }
    for (i = 0; i < qs; i++) q_ind[i] = i;
    intIntSort(q, q_ind, qs);
    pre_cal(root);
    res_size = 0;
    mi[root] = -2000000000;
    mx[root] = 2000000000;
    solve(root);
    for (i = 0; i < qs; i++) printf("%.10lf\n", res[i]);
  }
  return 0;
}
