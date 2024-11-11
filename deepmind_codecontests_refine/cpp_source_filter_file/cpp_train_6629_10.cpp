#include <bits/stdc++.h>
using namespace std;
const long long MX = 1ll * 9 * 1e12 / 4;
bool comp(pair<pair<long long, long long>, int> a,
          pair<pair<long long, long long>, int> b) {
  return a.first.first * a.first.first + a.first.second * a.first.second >
         b.first.first * b.first.first + b.first.second * b.first.second;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n;
  cin >> n;
  vector<pair<pair<long long, long long>, int> > data(n);
  pair<long long, long long> v;
  for (int i = 0; i < n; ++i) {
    cin >> data[i].first.first >> data[i].first.second;
    data[i].second = i;
    v.first += data[i].first.first;
    v.second += data[i].first.second;
  }
  pair<long long, long long> cpv = v;
  vector<int> ans(n);
  for (int k = 0; k < 10; ++k) {
    int i = 0;
    shuffle(data.begin(), data.end(), rng);
    fill(ans.begin(), ans.end(), 1);
    for (; i < n && (abs(v.first) > 1e9 || abs(v.second) > 1e9 ||
                     v.first * v.first + v.second * v.second > MX);
         ++i) {
      v.first -= 2 * data[i].first.first;
      v.second -= 2 * data[i].first.second;
      ans[data[i].second] = -1;
    }
    if (v.first * v.first + v.second * v.second <= MX) {
      for (auto x : ans) cout << x << ' ';
      cout << '\n';
      return 0;
    }
    v = cpv;
  }
  return 0;
}
