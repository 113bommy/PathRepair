#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k;
vector<int> v[N];
long long solve(int x) {
  if (x < 0) return 1e18;
  int sum = 0;
  for (int i = x + 1; i < N; i++) sum += v[i].size();
  if (sum > k) return 1e18;
  int take =
      max(0, sum + (int)v[x].size() + (x > 0 ? (int)v[x - 1].size() : 0) - k);
  int rem = max(0, x - take);
  vector<int> v1, v2;
  for (int i = 0; i < N; i++) {
    for (auto u : v[i]) {
      if (i == x - 1 or i == x)
        v1.push_back(u);
      else
        v2.push_back(u);
    }
  }
  if (take > v1.size() or rem + take > x) return 1e18;
  long long res = 0;
  sort(v1.begin(), v1.end());
  for (int i = 0; i < take; i++) res += v1[i];
  for (int i = take; i < v1.size(); i++) v2.push_back(v1[i]);
  if (rem > v2.size()) return 1e18;
  sort(v2.begin(), v2.end());
  for (int i = 0; i < rem; i++) res += v2[i];
  return res;
}
int main() {
  scanf("%d %d", &n, &k);
  k--;
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
  }
  int doNotCare = 200003, canNotTake = 200003, sum = 0;
  while (doNotCare > 0 and sum + v[doNotCare - 1].size() <= k) {
    sum += v[doNotCare - 1].size();
    doNotCare--;
  }
  sum = 0;
  while (canNotTake > 0 and sum + v[canNotTake].size() <= k) {
    sum += v[canNotTake].size();
    canNotTake--;
  }
  long long ans = 1e18;
  for (int i = canNotTake; i <= doNotCare; i++) ans = min(ans, solve(i));
  if (ans > 1e15)
    puts("-1");
  else
    printf("%lld\n", ans);
  return 0;
}
