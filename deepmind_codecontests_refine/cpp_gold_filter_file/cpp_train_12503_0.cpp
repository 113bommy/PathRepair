#include <bits/stdc++.h>
using namespace std;
long long data[200002], low, high, k;
long long tree[20][200002];
void mergeSort(int level, int l, int h) {
  if (l == h) {
    tree[level][l] = data[l];
    return;
  }
  int m = (l + h) >> 1;
  mergeSort(level + 1, l, m);
  mergeSort(level + 1, m + 1, h);
  for (int i = l, j = m + 1, curr = l; curr <= h; curr++) {
    if (i > m)
      tree[level][curr] = tree[level + 1][j++];
    else if (j > h)
      tree[level][curr] = tree[level + 1][i++];
    else if (tree[level + 1][i] < tree[level + 1][j])
      tree[level][curr] = tree[level + 1][i++];
    else
      tree[level][curr] = tree[level + 1][j++];
  }
}
int getAns(int level, int l, int h) {
  if (l > high || low > h) return 0;
  if (l >= low && h <= high)
    return lower_bound(tree[level] + l, tree[level] + h + 1, k) -
           (tree[level] + l);
  int m = (l + h) >> 1;
  int p = getAns(level + 1, l, m);
  p += getAns(level + 1, m + 1, h);
  return p;
}
int main() {
  int n, i;
  long long t;
  scanf("%d", &n), scanf("%lld", &t);
  long long sum = 0, x;
  for (i = 1; i <= n; i++) {
    scanf("%lld", &x);
    sum += x;
    data[i] = sum;
  }
  mergeSort(1, 1, n);
  long long ans = 0;
  for (i = 1; i <= n; i++) {
    k = t + data[i - 1];
    low = i;
    high = n;
    ans += getAns(1, 1, n);
  }
  printf("%lld\n", ans);
  return 0;
}
