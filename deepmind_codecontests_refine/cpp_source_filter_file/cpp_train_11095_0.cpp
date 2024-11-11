#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x1, x2, y1, y2;
  scanf("%d", &n);
  puts("YES");
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%d\n", (((x1 & 1) << 0) + (y1 & 1) + 1));
  }
}
