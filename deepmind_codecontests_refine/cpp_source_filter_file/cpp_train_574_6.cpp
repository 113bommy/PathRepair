#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int> > pos;
const int N = 100005;
int n, k, cnt[30000189], limit = 2e9, now;
vector<int> tmp;
long long ans[N];
pair<int, int> a[N];
map<int, int> mp;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    tmp.push_back(a[i].second);
  }
  sort(tmp.begin(), tmp.end());
  tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
  mp[tmp[0]] = 1;
  for (int i = 1; i < tmp.size(); i++) {
    mp[tmp[i]] = mp[tmp[i - 1]] + tmp[i] - tmp[i - 1];
    if (mp[tmp[i - 1]] + k - 1 < mp[tmp[i - 1]] + tmp[i] - tmp[i - 1])
      mp[tmp[i]] = mp[tmp[i - 1]] + k;
  }
  for (int i = 1; i <= n; i++) {
    pos.push_back(pair<pair<int, int>, int>(
        pair<int, int>(a[i].first - k + 1, 1), mp[a[i].second]));
    pos.push_back(pair<pair<int, int>, int>(pair<int, int>(a[i].first + 1, -1),
                                            mp[a[i].second]));
  }
  limit = pos[pos.size() - 1].first.first;
  sort(pos.begin(), pos.end());
  for (int i = 0; i < pos.size(); i++) {
    for (int j = pos[i].second; j >= pos[i].second - k + 1; j--) {
      ans[cnt[j]] -= limit - pos[i].first.first + 1;
      cnt[j] += pos[i].first.second;
      ans[cnt[j]] += limit - pos[i].first.first + 1;
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
