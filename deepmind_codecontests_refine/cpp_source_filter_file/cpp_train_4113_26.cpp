#include <bits/stdc++.h>
using namespace std;
int vis[505];
vector<pair<int, pair<int, int> > > a;
int main() {
  int n;
  scanf("%d", &n);
  n *= 2;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1, x; j < i; ++j) {
      scanf("%d", &x);
      a.push_back({x, {i, j}});
    }
  }
  sort(a.begin(), a.end());
  while (a.size()) {
    int i = a.back().second.first;
    int j = a.back().second.second;
    a.pop_back();
    if (vis[i] || vis[j]) continue;
    vis[i] = j;
    vis[j] = i;
  }
  for (int i = 1; i <= n; ++i) printf("%d ", vis[i]);
}
