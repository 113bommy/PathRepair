#include <bits/stdc++.h>
using namespace std;
int n, m;
set<pair<int, int>> s;
pair<pair<int, int>, int> ab[100009], cdk[100009];
int total[100009], ans[100009];
int main() {
  int j;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &ab[i].first.first, &ab[i].first.second);
    ab[i].second = i;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &cdk[i].first.first, &cdk[i].first.second, &total[i]);
    cdk[i].second = i;
  }
  sort(ab + 1, ab + n + 1);
  sort(cdk + 1, cdk + m + 1);
  j = 1;
  for (int i = 1; i <= n; i++) {
    while (j <= m && cdk[j].first.first <= ab[i].first.first) {
      s.insert(make_pair(cdk[j].first.second, cdk[j].second));
      j++;
    }
    set<pair<int, int>>::iterator iter =
        s.lower_bound(make_pair(ab[i].first.second, 0));
    if (iter == s.end()) {
      printf("NO\n");
      return (0);
    }
    ans[ab[i].second] = iter->second;
    total[iter->second]--;
    if (!total[iter->second]) s.erase(iter);
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
