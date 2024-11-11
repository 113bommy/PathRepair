#include <bits/stdc++.h>
using namespace std;
const int mx = 123;
vector<pair<int, int> > d[mx];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) d[i + j].push_back(make_pair(i, j));
  int ans = 0;
  vector<pair<int, int> > target;
  for (int i = 0; i < mx && k > 0; i++) {
    for (int j = 0; j < int(d[i].size()) && k > 0; j++) {
      k--;
      target.push_back(d[i][j]);
      ans += i + 1;
    }
  }
  printf("%d\n", ans);
  reverse(target.begin(), target.end());
  for (auto p : target) {
    printf("(1 1)");
    int r = 0, c = 0;
    while (r < p.first) {
      r++;
      printf(" (%d %d)", r + 1, c + 1);
    }
    while (c < p.second) {
      c++;
      printf(" (%d %d)", r + 1, c + 1);
    }
    puts("");
  }
  return 0;
}
