#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, h;
  cin >> n >> d >> h;
  if (h + h < d || d > n || h > d || (h + 1 < n && 2 > d) || n < d + 1)
    cout << -1, exit(0);
  for (int i = 0; i < d - h; ++i) printf("%d %d\n", i + 1, i + 2);
  int k = d - h + 2;
  printf("%d %d\n", 1, k);
  for (int i = 0; i < h - 2; ++i) printf("%d %d\n", k, k + 1), ++k;
  int x = k;
  if (h == 1) x = 1;
  ++k;
  while (k <= n) printf("%d %d\n", x, k), ++k;
}
