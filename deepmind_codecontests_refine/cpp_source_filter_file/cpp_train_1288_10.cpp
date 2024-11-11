#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k * 3 > n) {
    printf("-1\n");
    return 0;
  }
  vector<int> ans(n);
  for (int i = 0; i < k; ++i) ans[i] = (i + 1) % k;
  for (int i = k; i < n; ++i) ans[i] = i % k;
  for (int i = 0; i < n; ++i) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
  return 0;
}
