#include <bits/stdc++.h>
using namespace std;
vector<int> V;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int val;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &val);
    ans += (val / 10);
    V.push_back(10 - (val % 10));
  }
  sort(V.begin(), V.end());
  for (int i = 0; i < n; i++) {
    if (k >= V[i])
      k -= V[i], ans++;
    else {
      k = 0;
      break;
    }
  }
  if (k) ans = min(10 * n, ans + k / 10);
  printf("%d\n", ans);
  return 0;
}
