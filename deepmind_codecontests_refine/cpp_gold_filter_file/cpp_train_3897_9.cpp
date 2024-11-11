#include <bits/stdc++.h>
using namespace std;
const int NS = 1010;
const int MS = 19;
const int MOD = 1000000007;
const double PI = acos(-1.0);
const long long INF = (1LL << 60);
class Solution {
 public:
  long long maxProfit(int k, vector<long long> &a) {
    int n = (int)a.size();
    stack<pair<int, int> > vp;
    vector<long long> g;
    for (int v = 0, p; v < n; v = p + 1) {
      for (; v + 1 < n && a[v] >= a[v + 1]; v++)
        ;
      for (p = v + 1; p + 1 < n && a[p] <= a[p + 1]; p++)
        ;
      if (p >= n) break;
      for (; !vp.empty() && a[vp.top().first] >= a[v]; vp.pop())
        g.push_back(a[vp.top().second] - a[vp.top().first]);
      for (; !vp.empty() && a[vp.top().second] <= a[p]; vp.pop()) {
        long long x = a[vp.top().second] - a[v];
        if (x > 0) g.push_back(x);
        v = vp.top().first;
      }
      vp.push(make_pair(v, p));
    }
    for (; !vp.empty(); vp.pop())
      g.push_back(a[vp.top().second] - a[vp.top().first]);
    k = min(k, (int)g.size());
    if (k > 0)
      nth_element(g.begin(), g.begin() + k - 1, g.end(), greater<long long>());
    long long ans = 0;
    for (int i = 0; i < k; i++) {
      ans += g[i];
    }
    return ans;
  }
};
int main() {
  int n, k;
  while (~scanf("%d %d", &n, &k)) {
    vector<long long> Pr;
    long long vt;
    for (int i = 0; i < n; i++) {
      scanf("%I64d", &vt);
      Pr.push_back(vt);
    }
    Solution sol;
    long long ans = sol.maxProfit(k, Pr);
    printf("%I64d\n", ans);
  }
  return 0;
}
