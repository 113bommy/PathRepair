#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[607][607];
void input() {
  scanf("%d%d", &n, &m);
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
}
void solve() {
  long long br1 = 0;
  long long br2 = 0;
  int i, j;
  for (j = 0; j < m; j++) {
    if (abs((a[(n / 2)][j] - a[(n / 2) - 1][j])) > 125) {
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
  return;
  if (br1 >= br2) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
}
int main() {
  int q;
  scanf("%d", &q);
  while (q != 0) {
    q--;
    input();
    solve();
  }
  return 0;
}
