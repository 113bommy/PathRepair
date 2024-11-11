#include <bits/stdc++.h>
using namespace std;
const int max = 1e5 + 10;
int n, m;
int l, r;
int main() {
  int minx = 1e6;
  scanf("%d%d", &n, &m);
  while (m--) {
    scanf("%d%d", &l, &r);
    minx = min(minx, r - l);
  }
  printf("%d\n", minx + 1);
  int cnt = -1;
  for (int i = 1; i <= n; i++) {
    if (++cnt <= minx) {
      cout << cnt << ' ';
    } else {
      cnt = 0;
      cout << cnt << ' ';
    }
  }
}
