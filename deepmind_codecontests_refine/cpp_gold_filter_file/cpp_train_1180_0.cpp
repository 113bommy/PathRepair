#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
long long n, k, ans, cnt;
map<int, deque<int> > mp;
vector<pair<int, int> > rng;
vector<int> beg;
int cmp(pair<int, int> a, pair<int, int> b) { return (a.second < b.second); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < (n); i++) {
    int x;
    cin >> x;
    mp[x].push_back(i);
    if (mp[x].size() == k) {
      rng.push_back({mp[x].front(), mp[x].back()});
      mp[x].pop_front();
    }
  }
  sort(rng.begin(), rng.end(), cmp);
  int m = rng.size();
  for (int i = 0; i < (m); i++) {
    int pre = -1;
    if (i) {
      if (rng[i].first < beg.back()) continue;
      pre = beg.back();
    }
    long long l = rng[i].first - pre - 1, r = n - rng[i].second - 1;
    ans += l + r + l * r + 1;
    beg.push_back(rng[i].first);
  }
  cout << ans << endl;
}
