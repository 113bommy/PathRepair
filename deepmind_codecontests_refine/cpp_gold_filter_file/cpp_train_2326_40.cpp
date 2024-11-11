#include <bits/stdc++.h>
using namespace std;
const int T = 2003;
int n, d;
int main() {
  int now(1), ans(0);
  scanf("%d%d", &d, &n);
  for (int i = 1, x; i < n; i++) scanf("%d", &x), ans += (d - x);
  printf("%d\n", ans);
  return 0;
}
