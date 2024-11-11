#include <bits/stdc++.h>
using namespace std;
map<int, int> mark;
int n;
int a[10005], luu[10005];
int d[10005];
void swap(int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}
void heap(int dau, int cuoi) {
  int i, j;
  i = dau;
  j = i * 2;
  while (j <= cuoi) {
    if (j + 1 <= cuoi && a[j] < a[j + 1]) j++;
    if (a[i] < a[j]) {
      swap(i, j);
      i = j;
      j = 2 * i;
    } else
      return;
  }
}
void _sort() {
  int i;
  for (i = n / 2; i >= 1; i--) heap(i, n);
  for (i = n; i >= 1; i--) {
    swap(1, i);
    heap(1, i - 1);
  }
}
void input() {
  int i;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  _sort();
}
void solve() {
  int i, pt;
  pt = 0;
  memset(d, 0, (n + 2) * sizeof(int));
  for (i = 1; i < n; i++) {
    if (mark[a[i]] == 0 && a[i] < a[n]) {
      d[i] = 1;
      luu[++pt] = a[i];
      mark[a[i]] = 1;
    }
  }
  mark.clear();
  luu[++pt] = a[n];
  for (i = n - 1; i >= 1; i--) {
    if (mark[a[i]] == 0 && a[i] < a[n] && d[i] == 0) {
      mark[a[i]] = 1;
      luu[++pt] = a[i];
    }
  }
  printf("%d\n", pt);
  for (i = 1; i <= pt; i++) {
    if (i != 1) printf(" ");
    printf("%d", luu[i]);
  }
  printf("\n");
}
int main() {
  while (scanf("%d", &n) > 0) {
    input();
    solve();
  }
  return 0;
}
