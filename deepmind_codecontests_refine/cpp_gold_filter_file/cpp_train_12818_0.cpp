#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int a[105];
int main() {
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  if (y < x) {
    printf("%d", n);
    return 0;
  }
  if (x <= y) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
      if (a[i] <= x) cnt++;
    printf("%d", (cnt + 1) / 2);
  }
  return 0;
}
