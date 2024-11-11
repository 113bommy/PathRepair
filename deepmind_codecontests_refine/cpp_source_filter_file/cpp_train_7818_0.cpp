#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > vec[105];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) vec[i].push_back(make_pair(i, i));
  int ct = 100;
  int a, b;
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &a, &b);
    vec[a].push_back(make_pair(ct, a));
    vec[b].push_back(make_pair(ct, b));
    ct++;
  }
  for (int i = 1; i <= n; i++) {
    printf("%d\n", vec[i].size());
    for (int j = 0; j < vec[i].size(); j++)
      printf("%d %d\n", vec[i][j].first, vec[i][j].second);
  }
}
