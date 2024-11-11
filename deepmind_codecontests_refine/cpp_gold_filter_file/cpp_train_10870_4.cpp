#include <bits/stdc++.h>
using namespace std;
const int base = 1e9;
const int maxn = 80;
const int logn = 20;
const int inf = 2e9;
const int alpha = 26;
const int my_hash = 29;
const long long l_inf = 4e18;
const long long mod = 1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-9;
long long w, m, k, ans = 0;
int n;
vector<pair<long long, long long> > cnt;
void init() {
  cnt.push_back(make_pair(9, 1));
  for (int i = int(0); i < int(16); i++)
    cnt.push_back(make_pair(cnt[i].first * 10 + 9, cnt[i].second + 1));
}
int main() {
  ios_base::sync_with_stdio();
  init();
  cin >> w >> m >> k;
  for (int i = int(0); i < int(cnt.size()); i++) {
    if (m > cnt[i].first) continue;
    if ((cnt[i].first - m + 1) * cnt[i].second <= w / k) {
      ans += cnt[i].first - m + 1;
      w -= (cnt[i].first - m + 1) * (cnt[i].second * k);
      m = cnt[i].first + 1;
    } else {
      long long l = 0, r = 1e16;
      while (l != r) {
        long long mid = (l + r) / 2;
        mid* cnt[i].second <= w / k ? l = mid + 1 : r = mid;
      }
      ans += l - (l * cnt[i].second > w / k);
      break;
    }
  }
  cout << ans;
}
