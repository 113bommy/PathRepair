#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
int solve(int x, vector<pair<int, int> > va, vector<pair<int, int> > vb) {
  vector<int> wa, wb;
  int i = 0, j = 0;
  int ans = 0;
  while (true) {
    while (i < ((int)(va).size()) and va[i].first <= x) {
      wa.push_back(va[i].second);
      push_heap((wa).begin(), (wa).end());
      ++i;
    }
    if (wa.empty()) break;
    x += wa.front();
    pop_heap((wa).begin(), (wa).end());
    wa.pop_back();
    ans += 1;
    swap(i, j);
    swap(va, vb);
    swap(wa, wb);
  }
  return ans;
}
int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  vector<pair<int, int> > vec[2];
  for (int i = 0; i < n; ++i) {
    int t, h, m;
    scanf("%d %d %d", &t, &h, &m);
    vec[t].push_back(make_pair(h, m));
  }
  sort((vec[0]).begin(), (vec[0]).end());
  sort((vec[1]).begin(), (vec[1]).end());
  int ans1 = solve(x, vec[0], vec[1]);
  int ans2 = solve(x, vec[1], vec[0]);
  printf("%d\n", max(ans1, ans2));
}
