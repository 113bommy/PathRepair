#include <bits/stdc++.h>
using namespace std;
int v[200001];
int main() {
  int n, m, k, i, box;
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (i = n, box = 0; i > 0; i--) {
    if (box + v[i] > k) {
      m--;
      if (m == 0) break;
      box = v[i];
    } else
      box += v[i];
  }
  printf("%d", n - i);
  return 0;
}
