#include <bits/stdc++.h>
using namespace std;
int n;
int A, B;
int curr, prv;
struct point {
  int x, y;
};
bool cmp(point a, point b) {
  if (a.x == b.x) return a.y > b.y;
  return a.x < b.x;
}
map<int, vector<point> > a;
vector<vector<long long> > dp(int(2 * 1e5 + 9), vector<long long>(2, 1e18));
point cf, cl, pf, pl;
set<int> lvl;
point o;
long long dist(point a, point b) { return abs(a.y - b.y) + abs(a.x - b.x); }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &A, &B);
    o.x = A;
    o.y = B;
    a[max(A, B)].push_back(o);
    lvl.insert(max(A, B));
  }
  o.x = o.y = 0;
  a[0].push_back(o);
  lvl.insert(0);
  for (map<int, vector<point> >::iterator it = a.begin(); it != a.end(); it++)
    sort(it->second.begin(), it->second.end(), cmp);
  dp[0][0] = dp[0][1] = 0;
  set<int>::iterator it = lvl.begin();
  for (int i = 1; i < lvl.size(); i++) {
    pf = a[*it][0];
    pl = a[*it].back();
    it++;
    cf = a[*it][0];
    cl = a[*it].back();
    dp[i][0] = min(dp[i][0], dp[i - 1][0] + dist(pf, cl) + dist(cl, cf));
    dp[i][0] = min(dp[i][0], dp[i - 1][1] + dist(pl, cl) + dist(cl, cf));
    dp[i][1] = min(dp[i][0], dp[i - 1][0] + dist(pf, cf) + dist(cl, cf));
    dp[i][1] = min(dp[i][0], dp[i - 1][1] + dist(pl, cf) + dist(cl, cf));
  }
  printf("%I64d", min(dp[lvl.size() - 1][0], dp[lvl.size() - 1][1]));
  return 0;
}
