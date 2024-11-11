#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
int n;
vector<pair<int, int> > v;
int dp[200200];
int calc(int ind) {
  if (ind == n) return 0;
  int &res = dp[ind];
  if (res != -1) return res;
  res = calc(ind + 1);
  int val = v[ind].second;
  int l = ind + 1, r = n - 1, pos = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (v[mid].first <= val)
      l = mid + 1;
    else {
      pos = mid;
      r = mid - 1;
    }
  }
  res = max(res, calc(pos) + 1);
  return res;
}
int main() {
  scanf("%d\n", &n);
  for (int i = 0, x, w; i < n; i++) {
    scanf("%d%d", &x, &w);
    v.push_back(make_pair(x - w, x + w));
  }
  sort(v.begin(), v.end());
  memset(dp, -1, sizeof dp);
  cout << calc(0) << endl;
  return 0;
}
