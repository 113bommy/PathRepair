#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<int, int> > ve;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    pair<int, int> tmp;
    scanf("%d", &tmp.first);
    tmp.second = i;
    ve.push_back(tmp);
  }
  sort(ve.begin(), ve.end());
  reverse(ve.begin(), ve.end());
  vector<int> tree;
  tree.push_back(ve[0].second * 2);
  for (int i = 1; i < n; i++) {
    printf("%d %d\n", ve[i - 1].second * 2, ve[i].second * 2);
    tree.push_back(ve[i].second * 2);
  }
  for (int i = 0; i < n; i++) {
    int k = i + ve[i].first - 1;
    printf("%d %d\n", ve[i].second * 2 - 1, tree[k]);
    if (k + 1 == tree.size()) {
      tree.push_back(ve[i].second * 2 - 1);
    }
  }
  return 0;
}
