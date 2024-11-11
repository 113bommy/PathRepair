#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n), b(m);
  for (auto &it : a) scanf("%d", &it);
  for (auto &it : b) scanf("%d", &it);
  for (int i = n - 2; i >= 0; i--) {
    a[i] = min(a[i], a[i + 1]);
  }
  if (a[0] != b[0]) {
    printf("0\n");
    return 0;
  }
  int ans = 1;
  for (int i = 1; i < m; i++) {
    int qtd = upper_bound((a).begin(), (a).end(), b[i]) -
              lower_bound((a).begin(), (a).end(), b[i]);
    ans = (int)(1ll * ans * qtd) % mod;
  }
  printf("%d\n", ans);
}
