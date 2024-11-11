#include <bits/stdc++.h>
using namespace std;
const int N = 30033;
int a[N], n;
int vis[N];
vector<int> x, y;
void check(int i, int j) {
  memset(vis, 0, sizeof(vis));
  vis[i] = vis[j] = 1;
  int k = j + 1, last = j, d = a[j] - a[i];
  int Ed = 0;
  for (; k <= n; k++) {
    if (a[k] - a[last] == d) {
      last = k;
      vis[k] = 1;
    } else
      Ed = k;
  }
  int Ls;
  for (Ls = 1; Ls <= n && vis[Ls]; Ls++)
    ;
  if (Ls > n) {
    for (int i = (2); i <= (n); i++) printf("%d ", a[i]);
    printf("\n");
    printf("%d\n", a[1]);
    exit(0);
  }
  last = Ls;
  d = 1e9;
  for (int h = (Ls + 1); h <= (n); h++) {
    if (vis[h] == 0) {
      if (abs(a[h] - a[last]) < abs(d)) d = a[h] - a[last];
      last = h;
    }
  }
  vis[Ls] = 2;
  last = Ls;
  bool tmp = 0;
  for (int h = (Ls + 1); h <= (n); h++) {
    if (h > Ed && tmp == 0) break;
    if (a[h] - a[last] == d) {
      if (vis[h] == 1) tmp = 1;
      vis[h] = 2;
      last = h;
    } else {
      if (vis[h] == 0 || (vis[h] == 1 && tmp)) return;
    }
  }
  if (vis[i] == 2 || vis[j] == 2) return;
  for (int h = (1); h <= (n); h++)
    if (vis[h] == 1) printf("%d ", a[h]);
  printf("\n");
  for (int h = (1); h <= (n); h++)
    if (vis[h] == 2) printf("%d ", a[h]);
  printf("\n");
  exit(0);
}
int main() {
  cin >> n;
  for (int i = (1); i <= (n); i++) {
    scanf("%d", a + i);
  }
  if (n == 2) {
    printf("%d\n%d\n", a[1], a[2]);
    return 0;
  } else if (n == 3) {
    printf("%d\n%d %d\n", a[1], a[2], a[3]);
    return 0;
  }
  check(1, 2);
  check(1, 3);
  check(2, 3);
  printf("No solution\n");
  return 0;
}
