#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int l, r, k = INF;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &l, &r);
    k = min(k, r - l + 1);
  }
  printf("%d\n", k);
  for (int i = 0; i < n; i++) printf("%d ", i % k);
  puts("");
  return 0;
}
