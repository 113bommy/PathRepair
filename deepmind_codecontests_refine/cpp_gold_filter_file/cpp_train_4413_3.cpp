#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0, sum1 = 0;
  int x, y;
  int a[105];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  scanf("%d%d", &x, &y);
  int x1 = min(x, y);
  int y1 = max(x, y);
  for (int i = x1; i < y1; i++) {
    sum1 += a[i];
  }
  printf("%d", min(sum1, sum - sum1));
}
