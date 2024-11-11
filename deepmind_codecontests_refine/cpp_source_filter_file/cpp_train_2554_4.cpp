#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
map<int, int> mp;
int n, k;
inline void f(long long mn) {
  k -= mn;
  auto bg = mp.begin();
  auto rbg = mp.rbegin();
  auto pr1 = *bg, pr2 = *rbg;
  int rem = mn % pr1.second, dv = mn / pr1.second;
  mp[pr1.first] -= pr1.second;
  mp[pr1.first + dv] += pr1.second - rem;
  if (rem) mp[pr1.first + dv + 1] += rem;
  rem = mn % pr2.second, dv = mn / pr2.second;
  mp[pr2.first - dv] += pr2.second - rem;
  mp[pr2.first] -= pr2.second;
  if (rem) mp[pr2.first - dv - 1] += rem;
  if (mp.begin()->second == 0) mp.erase(mp.begin());
  auto it = mp.end();
  --it;
  if (it->second == 0) mp.erase(it);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  while (n--) {
    int tmp;
    cin >> tmp;
    ++mp[tmp];
  }
  while (k && mp.rbegin()->first - mp.begin()->second > 1) {
    long long mn = k;
    auto bg = mp.begin(), it1 = bg;
    ++it1;
    auto rbg = mp.rbegin(), it2 = rbg;
    ++it2;
    int val1 = it1->first, val2 = it2->first;
    if (mp.size() == 2) val1 = val2 = (bg->first + rbg->first) / 2;
    mn = min(mn, 1LL * (val1 - bg->first) * bg->second);
    mn = min(mn, 1LL * (rbg->first - val2) * rbg->second);
    f(mn);
  }
  cout << mp.rbegin()->first - mp.begin()->first;
}
