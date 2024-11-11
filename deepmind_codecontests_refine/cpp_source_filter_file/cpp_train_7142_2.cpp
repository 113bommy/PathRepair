#include <bits/stdc++.h>
using namespace std;
int n, ok[100000];
pair<int, int> a[100000], b[100000];
map<int, int> mp;
vector<int> ans[100000];
int idx;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].first);
    b[i].first = a[i].first;
    b[i].second = i;
  }
  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    mp[b[i].first] = i;
  }
  for (int i = 0; i < n; i++) {
    a[i].second = mp[a[i].first];
  }
  for (int i = 0; i < n; i++) {
    if (ok[i]) {
      continue;
    }
    int to = i;
    while (!ok[to]) {
      ans[idx].push_back(b[to].second);
      ok[to] = 1;
      to = a[to].second;
    }
    idx++;
  }
  printf("%d\n", idx);
  for (int i = 0; i < idx; i++) {
    printf("%d", (int)ans[i].size());
    for (int j = 0; j < (int)ans[i].size(); j++) {
      printf(" %d", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
