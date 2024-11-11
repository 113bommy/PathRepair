#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int maxm = -1;
const int maxk = -1;
int n, m, k, q;
int T;
int main(void) {
  scanf("%d", &n);
  vector<pair<int, int> > v;
  long long cnt = 0;
  for (int i = 0; i < n; ++i) {
    bool valid = false;
    int l;
    scanf("%d", &l);
    int st, ed;
    int prev = INT_MAX;
    for (int j = 1; j <= l; ++j) {
      int now;
      scanf("%d", &now);
      if (j == 1) st = now;
      if (j == l) ed = now;
      if (prev < now) valid = true;
      prev = now;
    }
    cnt += valid;
    if (!valid) v.push_back({st, ed});
  }
  long long ans = cnt * cnt + cnt * v.size() * 2;
  int d[maxn] = {0};
  for (auto i : v) {
    ++d[0];
    --d[i.first + 1];
  }
  for (int i = 1; i < maxn; ++i) {
    d[i] += d[i - 1];
  }
  for (auto i : v) {
    ans += d[i.second + 1] - 1;
  }
  printf("%lld", ans);
  return 0;
}
