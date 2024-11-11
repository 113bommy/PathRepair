#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int du[maxn];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    du[x]++;
    du[y]++;
  }
  int fg = 0;
  for (int i = 1; i <= n; i++)
    if (du[i] == 2) {
      fg = 1;
      break;
    }
  if (fg == 1)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}
