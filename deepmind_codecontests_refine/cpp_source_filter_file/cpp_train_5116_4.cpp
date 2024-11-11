#include <bits/stdc++.h>
using namespace std;
const int N = 1100;
int a[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int res = 0;
  for (int qtd = 1; qtd <= n; ++qtd) {
    vector<int> ans;
    for (int i = 0; i < qtd; ++i) {
      ans.push_back(a[i]);
    }
    if (qtd % 2 == 1) {
      ans.push_back(0);
    }
    sort(ans.begin(), ans.end());
    int height = 0;
    for (int i = 0; i < qtd; i += 2) {
      height += max(ans[i], ans[i + 1]);
    }
    if (height <= k) {
      res = qtd;
    }
  }
  printf("%d\n", res);
}
