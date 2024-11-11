#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (abs(x - 1) < 5 || abs(x - n) < 5 || abs(y - 1) < 5 || abs(y - m) < 5) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
