#include <bits/stdc++.h>
using namespace std;
int an[400], bn[400];
int n;
vector<pair<int, int> > ans;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &an[i]);
  for (int i = 0; i < n; i++) scanf("%d", &bn[i]);
  for (int i = 0; i < n; i++) {
    int j;
    for (j = i; j < n; j++) {
      if (an[i] == bn[j]) break;
    }
    while (j != i) {
      std::swap(bn[j - 1], bn[j]);
      ans.push_back({j - 1, j});
      j--;
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  return 0;
}
