#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int t, n;
pair<long long, long long> res[N];
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return (a.first - a.second) < (b.first - b.second);
}
void solve() {
  int k;
  long long x, minn, ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &k);
    minn = 0;
    for (int j = 0; j < k; ++j) {
      scanf("%lld", &x);
      if (x >= minn) minn = x + 1;
      ++minn;
    }
    res[i].first = minn;
    res[i].second = k;
  }
  sort(res, res + n);
  ans = res[0].first - res[0].second;
  long long cur = res[0].first;
  for (int i = 1; i < n; ++i) {
    int temp = res[i].first - res[i].second;
    if (temp > cur) {
      ans += temp - cur;
      cur = res[i].first;
    } else {
      cur += res[i].second;
    }
  }
  printf("%lld\n", ans);
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    solve();
  }
  return 0;
}
