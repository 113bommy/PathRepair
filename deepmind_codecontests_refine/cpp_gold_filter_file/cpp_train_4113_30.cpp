#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, pair<int, int> > > v;
  for (int i = 2; i <= 2 * n; i++) {
    for (int j = 1; j < i; j++) {
      int x;
      scanf("%d", &x);
      v.push_back(make_pair(x, make_pair(i, j)));
    }
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int ans[1000];
  memset(ans, -1, sizeof(ans));
  for (int i = 0; i < v.size(); i++) {
    int u = v[i].second.first;
    int w = v[i].second.second;
    if (ans[u] == -1 and ans[w] == -1) {
      ans[u] = w;
      ans[w] = u;
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    if (i) printf(" ");
    printf("%d", ans[i + 1]);
  }
  printf("\n");
  return 0;
}
