#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int main() {
  int a[6];
  for (int i = 0; i < 6; ++i) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = 0; i < min(a[1], a[5]); ++i) ans += 2 * a[0]++ + 1;
  for (int i = 0; i < abs(a[1] - a[5]); ++i) ans += a[0];
  for (int i = 0; i < min(a[2], a[4]); ++i) ans += 2 * a[3]++ + 1;
  printf("%d", ans);
  return 0;
}
