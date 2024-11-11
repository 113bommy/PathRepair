#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > res;
void solve() {
  for (int i = 1; i < n; i++)
    for (int len = 1; len < n; len += 2)
      if (len != 2) {
        if (i + len > n) break;
        res.push_back(pair<int, int>(i, i + len));
      }
}
int main() {
  scanf("%d", &n);
  solve();
  printf("%d\n", res.size());
  for (int i = 0; i < res.size(); i++)
    printf("%d %d\n", res[i].first, res[i].second);
  return 0;
}
