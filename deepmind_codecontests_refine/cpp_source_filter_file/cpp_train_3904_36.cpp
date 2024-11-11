#include <bits/stdc++.h>
using namespace std;
int a[102][102];
int main() {
  int i, j;
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int mini = min(n, m);
  for (i = 1; i <= k; i++) {
    int st, en;
    scanf("%d%d", &st, &en);
    mini = min(mini, min(abs(st - 1),
                         min(abs(st - n), min(abs(en - m), abs(st - 1)))));
  }
  if (mini <= 4 && k != 0) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
