#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > odd, even;
int mx[100010], mn[100010];
long long solve(vector<pair<int, int> > &cur) {
  if (cur.empty()) return 0;
  sort(cur.begin(), cur.end());
  mx[0] = mn[0] = cur[0].second;
  for (int i = 1; i < cur.size(); i++) {
    mx[i] = max(mx[i - 1], cur[i].second);
    mn[i] = min(mn[i - 1], cur[i].second);
  }
  int Mx, Mn;
  Mx = Mn = cur.back().second;
  long long ans = 0;
  for (int i = cur.size() - 1; i; i--) {
    ans += 1ll * (cur[i].first - cur[i - 1].first) *
           (min(Mx, mx[i - 1]) - max(Mn, mn[i - 1]));
    Mx = max(Mx, cur[i - 1].second);
    Mn = min(Mn, cur[i - 1].second);
  }
  return ans / 4;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i <= n; i++) {
    scanf("%d%d", &x, &y);
    if ((x + y) & 1)
      odd.push_back(pair<int, int>(x + y + 1, x + 1 - y));
    else
      even.push_back(pair<int, int>(x + y, x - y));
  }
  printf("%I64d\n", solve(odd) + solve(even));
}
