#include <bits/stdc++.h>
using namespace std;
const int N = 1111;
int mem[N][N];
int val[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", mem[i] + j);
  int ans = 0;
  for (int j = 0; j < n; j++) ans += mem[j][j];
  ans = ans % 2;
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int a;
    scanf("%d", &a);
    if (a != 3) {
      int j;
      scanf("%d", &j);
      ans = 1 - ans;
    } else
      printf("%d", ans);
  }
  printf("\n");
  return 0;
}
