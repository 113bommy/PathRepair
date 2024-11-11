#include <bits/stdc++.h>
using namespace std;
int n, c;
int a[10001], b[10001];
int sol = 0;
int bound;
int check(int x) {
  int tek = 0;
  for (int i = 0; i < n; i++) {
    tek += a[i] * x / b[i] + 1;
    if (tek > c) return 1;
  }
  if (tek == c) return 0;
  return -1;
}
int main() {
  scanf("%d%d", &n, &c);
  bound = c;
  unsigned long long mb = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    if (b[i] > mb) mb = b[i];
  }
  bound *= mb;
  for (int i = 1; i < bound; i++) {
    int k = check(i);
    if (k == 0) sol++;
    if (k > 0) break;
  }
  printf("%d\n", sol);
  return 0;
}
