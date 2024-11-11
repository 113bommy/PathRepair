#include <bits/stdc++.h>
using namespace std;
struct coord {
  int x, y;
} a[1002];
int n, cnt;
int main() {
  cin >> n;
  for (int i = 1; i <= n + 1; i++) scanf("%d %d", &a[i].x, &a[i].y);
  for (int i = 2; i < n; i++) {
    if (a[i].y > a[i - 1].y && a[i].x > a[i + 1].x) cnt++;
    if (a[i].x > a[i - 1].x && a[i].y < a[i + 1].y) cnt++;
    if (a[i].y < a[i - 1].y && a[i].x < a[i + 1].x) cnt++;
    if (a[i].x < a[i - 1].x && a[i].y > a[i + 1].y) cnt++;
  }
  cout << cnt;
  return 0;
}
