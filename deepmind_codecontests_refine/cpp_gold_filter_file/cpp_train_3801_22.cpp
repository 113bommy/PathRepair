#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > ans;
vector<pair<long long, long long> > ans2;
int main() {
  unsigned long long n;
  cin >> n;
  unsigned long long last = 1;
  unsigned long long mi = 0;
  while (last <= (int)1e7 && last <= n) {
    mi += (last) * (last - 1) / 2;
    unsigned long long di = (last * (last + 1)) / 2;
    if ((n + mi) % di == 0) {
      unsigned long long res = (n + mi) / di;
      if (res == last) {
        ans.push_back(make_pair(last, last));
        break;
      } else if (res < last)
        break;
      else {
        ans.push_back(make_pair(last, res));
        ans2.push_back(make_pair(res, last));
      }
    }
    last++;
  }
  printf("%d\n", ans.size() + ans2.size());
  for (int i = 0; i < ans.size(); ++i)
    printf("%lld %lld\n", ans[i].first, ans[i].second);
  reverse(ans2.begin(), ans2.end());
  for (int i = 0; i < ans2.size(); ++i)
    printf("%lld %lld\n", ans2[i].first, ans2[i].second);
  return 0;
}
