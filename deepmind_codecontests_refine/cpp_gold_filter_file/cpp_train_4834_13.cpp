#include <bits/stdc++.h>
using namespace std;
int Solution() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector<int> fr(m), kom(k);
  for (int i = 0; i < m; ++i) scanf("%d", &fr[i]);
  for (int i = 0; i < k; ++i) scanf("%d", &kom[i]);
  int res = 0x7fffffff;
  vector<int> ans;
  for (int i = 0; i < m; ++i) {
    int now = 0;
    for (int j = 0; j < k; ++j)
      if (kom[j] % fr[i] == 0) ++now;
    if (now == res) ans.push_back(i + 1);
    if (now < res) {
      ans.clear();
      ans.push_back(i + 1);
      res = now;
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
int main() {
  Solution();
  return 0;
}
