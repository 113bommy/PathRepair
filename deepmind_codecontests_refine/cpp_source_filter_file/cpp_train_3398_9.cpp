#include <bits/stdc++.h>
using namespace std;
vector<long long> v1, v2;
int n, p[20];
long long k;
int mx, id = 0;
void dfs1(int dep, long long x) {
  if (dep >= mx) {
    v1.push_back(x);
    return;
  }
  dfs1(dep + 1, x);
  while (1) {
    if (x > 1e18 / p[dep]) break;
    x = x * p[dep];
    dfs1(dep + 1, x);
  }
}
void dfs2(int dep, long long x) {
  if (dep >= mx) {
    v2.push_back(x);
    return;
  }
  dfs2(dep + 1, x);
  while (x <= 1e18) {
    if (x > 1e18 / p[dep]) break;
    x = x * p[dep];
    dfs2(dep + 1, x);
  }
}
long long count(long long x) {
  long long ans = upper_bound(v1.begin(), v1.end(), x) - v1.begin();
  if (v2.size()) {
    ans = ans + upper_bound(v2.begin(), v2.end(), x) - v2.begin();
    for (int i = 1; i < v1.size(); i++) {
      long long lim = x / v1[i];
      if (lim == 0) break;
      ans += upper_bound(v2.begin(), v2.end(), lim) - v2.begin() - 1;
    }
    ans--;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  scanf("%lld", &k);
  sort(p + 1, p + 1 + n);
  mx = min(n + 1, 6);
  dfs1(1, 1);
  long long ans = v1.size();
  if (n + 1 >= 7) {
    mx = n + 1;
    dfs2(6, 1);
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  long long L = 1, R = 1e18;
  while (R - L > 1) {
    long long mid = (L + R) >> 1;
    if (count(mid) < k) {
      L = mid;
    } else {
      R = mid;
    }
  }
  cout << (L + 1) << endl;
}
