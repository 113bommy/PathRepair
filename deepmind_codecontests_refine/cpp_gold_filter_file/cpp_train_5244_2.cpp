#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> arr[100005];
int main() {
  int n;
  long long j;
  scanf("%d %lld", &n, &j);
  vector<pair<long long, long long> > v;
  pair<long long, long long> m;
  scanf("%lld %lld", &m.first, &m.second);
  pair<long long, long long> ans = m;
  for (int i = int(1); i < int(n + 1); ++i) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    v.emplace_back(a, b);
  }
  for (int i = int(0); i < int(j % (2 * n)); ++i) {
    pair<long long, long long> cur;
    cur.first = v[i % n].first * 2 - ans.first;
    cur.second = v[i % n].second * 2 - ans.second;
    ans = cur;
  }
  printf("%lld %lld\n", ans.first, ans.second);
  return 0;
}
