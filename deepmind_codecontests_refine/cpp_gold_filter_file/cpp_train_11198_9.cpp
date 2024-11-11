#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  int MIN = INF;
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    MIN = min(MIN, r - l + 1);
  }
  printf("%d\n", MIN);
  for (int i = 2; i <= n + 1; i++) {
    printf("%d ", i % MIN);
  }
  return 0;
}
