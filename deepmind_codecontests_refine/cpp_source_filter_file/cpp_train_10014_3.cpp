#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[3 * N], ans[3 * N], ct[N];
struct node {
  int num, pos;
} qc[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < 3; ++i) {
    for (int j = 0; j < n; ++j) a[j + i * n] = a[j];
  }
  int mx = 3 * n, head = 0, tail = 0;
  for (int i = 0; i < mx; ++i) {
    int p = i % n;
    ct[p]++;
    if (ct[p] == 3 && ans[p] == 0) {
      ans[p] = -1;
      continue;
    }
    while (head < tail && a[p] * 2 < qc[head].num) {
      int pos = qc[head].pos;
      while (pos >= 0 && ans[pos] == 0) {
        ans[pos] = i - pos;
        pos--;
      }
      head++;
    }
    while (tail > head && qc[tail - 1].num <= a[p]) tail--;
    qc[tail++] = node{a[p], i};
  }
  for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
  return 0;
}
