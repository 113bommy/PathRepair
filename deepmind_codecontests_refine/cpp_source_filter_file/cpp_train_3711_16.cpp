#include <bits/stdc++.h>
using namespace std;
vector<long long> v[70];
int n;
long long ans[100010], cur = 0;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    long long u;
    scanf("%lld", &u);
    for (int j = 60; j >= 0; j--)
      if ((u >> j) & 1) {
        v[j].push_back(u);
        break;
      }
  }
  for (int i = 1; i <= n; i++) {
    bool ok = 0;
    for (int j = 0; j <= 60; j++)
      if (!(cur & (1 << j)) && !v[j].empty()) {
        cur ^= (ans[i] = v[j].back());
        v[j].pop_back();
        ok = 1;
        break;
      }
    if (!ok) {
      puts("No");
      return 0;
    }
  }
  printf("Yes\n");
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  return 0;
}
