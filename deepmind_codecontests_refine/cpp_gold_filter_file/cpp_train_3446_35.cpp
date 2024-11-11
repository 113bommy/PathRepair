#include <bits/stdc++.h>
using namespace std;
int cows[300000];
long long tmp[300000];
long long ans[300000];
map<int, vector<pair<int, int>>> mp;
int n, p;
void tmpClear() {
  for (long long &x : tmp) {
    x = 0;
  }
}
void sumCows(long long b) {
  for (int i = 0; i < n; ++i) {
    if (i + b >= n) break;
    tmp[i + b] = tmp[i] + cows[i];
  }
}
long long getAns(int a, int b) {
  long long ans = 0;
  for (int i = a; i < n; i += b) ans += cows[i];
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", cows + i);
  scanf("%d", &p);
  for (int i = 0; i < p; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    mp[b].push_back({a - 1, i});
  }
  for (auto &x : mp) {
    if (x.second.size() <= x.first) {
      for (auto &sce : x.second) {
        ans[sce.second] = getAns(sce.first, x.first);
      }
      continue;
    }
    tmpClear();
    sumCows(x.first);
    for (auto &sce : x.second) {
      int ind2 = sce.first + (n - sce.first - 1) / x.first * x.first;
      ans[sce.second] = tmp[ind2] - tmp[sce.first] + cows[ind2];
    }
  }
  for (int i = 0; i < p; ++i) printf("%lld\n", ans[i]);
  return 0;
}
