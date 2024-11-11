#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
int n, N, m, bsz;
long long a[2000001], b[2000001], ts[30][2];
bool rev[30];
int Merge(int l1, int r1, int l2, int r2) {
  int j = l2;
  long long ret = 0;
  bsz = 0;
  for (int i = l1; i <= r1; i++) {
    while (j <= r2 && a[j] < a[i]) ret += r1 - i + 1, b[++bsz] = a[j++];
    b[++bsz] = a[i];
  }
  for (; j <= r2; j++) b[++bsz] = a[j];
  return ret;
}
void MergeSort(int l, int r, int lv) {
  int mid = (l + r) / 2;
  if (l == r) return;
  MergeSort(l, mid, lv - 1), MergeSort(mid + 1, r, lv - 1);
  ts[lv][1] += Merge(mid + 1, r, l, mid),
      ts[lv][0] += Merge(l, mid, mid + 1, r);
  for (int i = 1; i <= bsz; i++) a[l + i - 1] = b[i];
}
int main() {
  int t1;
  scanf("%d", &N), n = 1 << N;
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  MergeSort(1, n, N);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    long long ans = 0;
    scanf("%d", &t1);
    for (int j = 1; j <= t1; j++) rev[j] ^= 1;
    for (int j = 1; j <= N; j++) ans += ts[j][rev[j]];
    printf("%I64d\n", ans);
  }
  return 0;
}
