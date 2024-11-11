#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> a[2017];
int main() {
  int n;
  scanf("%d", &n);
  unordered_map<long long, int> cnt;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", &a[i].first, &a[i].second);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i != j) {
        long long tmp1 = a[i].first - a[j].first;
        long long tmp2 = a[i].second - a[j].second;
        long long h = tmp1 * (1e9 + 1) + tmp2;
        cnt[h]++;
      }
    }
  }
  long long ans = 0LL;
  for (auto p : cnt) {
    ans += p.second * (p.second - 1LL) / 2LL;
  }
  cout << ans / 4LL << endl;
  return 0;
}
