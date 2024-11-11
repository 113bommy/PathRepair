#include <bits/stdc++.h>
using namespace std;
const int lim = 550;
const int MX = 3 * 100000 + 100;
long long dp[MX], w[MX];
long long n, m;
vector<pair<pair<long long, long long>, long long> > f1, f2;
long long p;
vector<pair<long long, long long> > a;
bool cmp(pair<pair<long long, long long>, long long> a,
         pair<pair<long long, long long>, long long> b) {
  if (a.first.first != b.first.first) return (a.first.first < b.first.first);
  return a.first.second < b.first.second;
}
bool cmp2(pair<long long, long long> a, pair<long long, long long> b) {
  return (a.second < b.second);
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> w[i];
  cin >> p;
  for (int i = 0, u, v; i < p; i++) {
    cin >> u >> v;
    u--;
    if (v > lim) {
      f2.push_back(make_pair(make_pair(v, u), i));
    } else
      f1.push_back(make_pair(make_pair(v, u), i));
  }
  sort(f2.begin(), f2.end(), cmp);
  sort(f1.begin(), f1.end(), cmp);
  for (int k = 0; k < (int)f1.size(); k++) {
    if (k > 0 && f1[k].first.first == f1[k - 1].first.first) {
      a.push_back(make_pair(dp[f1[k].first.second], f1[k].second));
      continue;
    }
    memset(dp, 0, sizeof(dp));
    int b = f1[k].first.first;
    for (int j = n - 1; j >= 0; j--) {
      if (j + b > n - 1)
        dp[j] = w[j];
      else
        dp[j] = dp[j + b] + w[j];
    }
    a.push_back(make_pair(dp[f1[k].first.second], f1[k].second));
  }
  for (int i = 0; i < (int)f2.size(); i++) {
    long long ans;
    long long b = f2[i].first.first, ind = f2[i].first.second;
    for (int j = ind; j < n; j += b) ans += w[j];
    a.push_back(make_pair(ans, f2[i].second));
  }
  sort(a.begin(), a.end(), cmp2);
  for (int i = 0; i < (int)a.size(); i++) cout << a[i].first << endl;
  return 0;
}
