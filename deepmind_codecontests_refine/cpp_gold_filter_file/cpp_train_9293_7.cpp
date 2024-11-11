#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
set<int> d;
int cnt[N], id[N];
vector<int> s[N];
pair<int, int> ans1[N], ans2[N];
int main() {
  for (int i = 1; i <= 200000; ++i)
    for (int j = i; j <= 200000; j += i) s[j].push_back(i);
  int n, m;
  long long l, r;
  scanf("%d%d%lld%lld", &n, &m, &l, &r);
  int curl = m + 1, curr = m;
  for (int x1 = 1; x1 <= n; ++x1) {
    long long L = (l - 1) / x1 + 1;
    long long R = r / x1;
    while (curl > L) {
      --curl;
      for (int t : s[curl]) {
        if (!cnt[t]) d.insert(t);
        ++cnt[t];
        id[t] = curl;
      }
    }
    while (curr > R) {
      for (int t : s[curr]) {
        --cnt[t];
        if (!cnt[t]) d.erase(t);
      }
      --curr;
    }
    for (int a : s[x1]) {
      auto v = d.upper_bound(a);
      if (v == d.end()) continue;
      int b = *v, y1 = id[b];
      if (1ll * x1 / a * b <= n) {
        ans1[x1] = make_pair(x1, y1);
        ans2[x1] = make_pair(x1 / a * b, y1 / b * a);
        break;
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    if (ans1[i].first == 0)
      puts("-1");
    else
      printf("%d %d %d %d\n", ans1[i].first, ans1[i].second, ans2[i].first,
             ans2[i].second);
  return 0;
}
