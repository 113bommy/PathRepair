#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  map<long long, bool> check;
  vector<pair<long long, long long>> v(n);
  vector<long long> vec;
  for (long long i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    if (!check[v[i].first]) {
      vec.push_back(v[i].first);
      check[v[i].first] = true;
    }
    if (!check[v[i].second + 1]) {
      vec.push_back(v[i].second + 1);
      check[v[i].second + 1] = true;
    }
  }
  sort(vec.begin(), vec.end());
  long long cnt[500005] = {0};
  long long ans[200005] = {0};
  for (long long i = 0; i < n; i++) {
    long long x = lower_bound(vec.begin(), vec.end(), v[i].first) - vec.begin();
    long long y =
        lower_bound(vec.begin(), vec.end(), v[i].second + 1) - vec.begin();
    cnt[x]++;
    cnt[y]--;
  }
  for (long long i = 1; i < 200005; i++) {
    cnt[i] += cnt[i - 1];
  }
  for (long long i = 0; i < vec.size() - 1; i++) {
    long long c = vec[i + 1] - vec[i];
    if (cnt[i] < 200004) ans[cnt[i]] += c;
  }
  for (long long i = 1; i <= n; i++) cout << ans[i] << " ";
}
