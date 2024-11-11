#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[10000005];
pair<int, int> b[10000005];
vector<int> ans;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    a[x]++;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &b[i].first);
    b[i].second = i + 1;
  }
  sort(b, b + m);
  int j = m - 1;
  for (int i = 10000000; i > 0; i--) {
    if (a[i] > k) {
      a[i - 1] += a[i] - k;
      continue;
    }
    while (j > -1 && b[j].first >= i && a[i] < k) {
      ans.push_back(b[j].second);
      j--;
      a[i]++;
    }
  }
  if (a[0] > k) {
    printf("-1\n");
    return 0;
  }
  while (j > -1 && a[0] < k) {
    ans.push_back(b[j].second);
    j--;
    a[0]++;
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf(i == 0 ? "%d" : " %d", ans[i]);
  }
}
