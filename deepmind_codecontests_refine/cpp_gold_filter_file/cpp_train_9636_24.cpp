#include <bits/stdc++.h>
using namespace std;
long long n, r, need[200005], l[200005], t[200005], pre[200005], add;
vector<long long> ans;
int main() {
  ios::sync_with_stdio(0);
  scanf("%lld %lld", &n, &r);
  for (int i = 0; i <= (n)-1; i++) scanf("%lld", &l[i]);
  for (int i = 0; i <= (n)-1; i++) scanf("%lld", &t[i]);
  for (int i = 1; i <= n - 1; i++) pre[i] = pre[i - 1] + l[i - 1];
  for (int i = 0; i <= (n)-1; i++) {
    t[i] = min(t[i], 2 * l[i]);
    need[i] = max(0ll, 2 * l[i] - t[i]);
    if (l[i] > t[i]) {
      cout << -1;
      return 0;
    }
  }
  long long cur = 0;
  long long moment = 0;
  for (int i = 0; i <= (n)-1; i++)
    if (need[i]) {
      if (cur < pre[i]) {
        moment += 2 * (pre[i] - cur);
        cur = pre[i];
      }
      long long tmp = need[i] - (cur - pre[i]);
      if (tmp <= 0) continue;
      if (tmp / r + add > 100005) {
        add += tmp / r;
        cur += r * (tmp / r);
        moment += r * (tmp / r);
        tmp -= r * (tmp / r);
      } else {
        while (tmp >= r) {
          tmp -= r;
          if (ans.size() < 100005) ans.push_back(moment);
          add++;
          cur += r;
          moment += r;
        }
      }
      if (tmp > 0) {
        moment += (pre[i] + l[i] - tmp - cur) * 2;
        cur = pre[i] + l[i] - tmp;
        if (ans.size() < 100005) ans.push_back(moment);
        add++;
        cur += r;
        moment += r;
      }
    }
  printf("%lld\n", add);
  if (add <= 100000)
    for (auto i : ans) printf("%lld ", i);
}
