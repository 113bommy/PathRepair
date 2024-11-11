#include <bits/stdc++.h>
using namespace std;
int n, w;
const int MAX_N = 1E6;
long long bit[MAX_N + 1];
void add(int idx, long long val) {
  for (++idx; idx <= MAX_N; idx += idx & -idx) bit[idx] += val;
}
void range_add(int l, int r, long long val) {
  add(l, val);
  add(r + 1, -val);
}
long long point_query(int idx) {
  long long ret = 0;
  for (++idx; idx > 0; idx -= idx & -idx) ret += bit[idx];
  return ret;
}
const int K = 25;
int l;
int a[MAX_N];
int st[MAX_N][K];
int lolog[MAX_N + 1];
int amax(int L, int R) {
  int j = lolog[R - L + 1];
  return max(st[L][j], st[R - (1 << j) + 1][j]);
}
void do_point(int i) {
  int val = amax(max(0, i - (w - l)), min(l - 1, i));
  if (i < (w - l) || i >= l) val = max(val, 0);
  range_add(i + 1, i + 1, val);
}
int main() {
  lolog[1] = 0;
  for (int i = 2; i <= MAX_N; i++) lolog[i] = lolog[i / 2] + 1;
  cin >> n >> w;
  for (int ro = 0; ro < n; ro++) {
    scanf("%d", &l);
    for (int i = 0; i < l; i++) scanf("%d", &a[i]);
    for (int i = 0; i < l; i++) st[i][0] = a[i];
    for (int j = 1; j <= K; j++)
      for (int i = 0; i + (1 << j) <= l; i++)
        st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    if (2 * l >= w) {
      for (int i = 0; i < w; i++) do_point(i);
    } else {
      for (int i = 0; i < l; i++) do_point(i);
      for (int i = w - l; i < w; i++) do_point(i);
      int val = max(0, amax(0, l - 1));
      range_add(l + 1, w - l, val);
    }
  }
  for (int i = 0; i < w; i++) printf("%lld ", point_query(i + 1));
  printf("\n");
  return 0;
}
