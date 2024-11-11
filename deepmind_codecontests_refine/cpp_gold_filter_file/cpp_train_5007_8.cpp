#include <bits/stdc++.h>
using namespace std;
const int N = 1000004;
int n, u, v, m, check[N], ans[N];
vector<int> a[N], res;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    if (check[i] == 0) {
      check[i] = ans[i] = 1;
      for (int j = 0; j < a[i].size(); j++) {
        check[a[i][j]] = 1;
      }
    }
  }
  memset(check, 0, sizeof(check));
  for (int i = n; i >= 1; i--) {
    if (ans[i] == 1) {
      if (check[i] == 0) {
        res.push_back(i);
        for (int j = 0; j < a[i].size(); j++) {
          check[a[i][j]] = 1;
        }
      }
    }
  }
  printf("%d\n", res.size());
  for (int i = res.size() - 1; i >= 0; i--) printf("%d ", res[i]);
}
